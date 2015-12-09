package edu.cmu.sbs.hub.server;

import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;
import edu.cmu.sbs.hub.Kiosk;
import edu.cmu.sbs.hub.datatype.exception.PatientNotFoundException;
import edu.cmu.sbs.protocol.StatusProtocol;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.lang.reflect.Type;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.util.Map;

import static spark.Spark.*;

public class Reception {

    private static int counter = 10;
    private static boolean kill = false;
    final private String FAILURE = "Failure\n";
    final private String SUCCESS = "Success\n";
    private Gson gson = new Gson();

    public Reception(Kiosk kiosk) {

        Logger logger = LoggerFactory.getLogger("Reception");

        port(26666);
        post("/biogears/update", (request, response) -> {

            logger.info(LocalTime.now().format(DateTimeFormatter.ISO_LOCAL_TIME) + " received " + request.body());

            try {
                Type castType = new TypeToken<Map<String, String>>() {
                }.getType();

                kiosk.receive(new StatusProtocol(gson.fromJson(request.body(), castType)));

                if (!kill && counter != 0) {
                    counter--;
                } else if (!kill) {
                    Action.kill();
                    kill = true;
                }

                return SUCCESS;
            } catch (PatientNotFoundException e) {
                logger.error(e.getMessage());
                return FAILURE;
            }
        });

        // TODO establish transfer protocol
        get("/unity/status", (request, response) -> {

            try {
                return kiosk.locatePatient("abcdefg").getStatus().toString();
            } catch (PatientNotFoundException e) {
                logger.error(e.getMessage());
                return FAILURE;
            } finally {
                logger.info("Status Update Success");
            }

        });

        // No create for now.
        // TODO establish create protocol
        //get("/unity/create", (request, response) -> {
        //    try {
        //        kiosk.createPatient(request.toString());
        //        return SUCCESS;
        //    } catch (IllegalProtocol illegalProtocol) {
        //        logger.error(illegalProtocol.getMessage());
        //        return FAILURE;
        //    }
        //
        //
        //});

        // TODO establish Action pattern
        post("/unity/action/:action", (request, response) -> {

            String action = request.params(":action").toLowerCase();

            logger.info(action + " Action Received");

            switch (action) {
                case "oxygen":
                	  String status = request.queryParams("status");
                	  if (status.equals("on")) {
                	  	Action.resumeOxygen();
                	  } else {
                	  	Action.noOxygen();
                	  }
                    return SUCCESS;

                case "kill":
                    Action.kill();
                    return SUCCESS;
                case "inject":
                		System.out.println(request.queryParams("drug_name"));
                		System.out.println(Double.parseDouble(request.queryParams("dose")));
                		Action.inject(request.queryParams("drug_name"), Double.parseDouble(request.queryParams("dose")));
                		return SUCCESS;

                default:
                    return FAILURE;
            }
        });
    }
}
