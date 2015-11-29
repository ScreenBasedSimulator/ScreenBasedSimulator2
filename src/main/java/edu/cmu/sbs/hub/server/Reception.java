package edu.cmu.sbs.hub.server;

import com.google.gson.Gson;
import edu.cmu.sbs.hub.Kiosk;
import edu.cmu.sbs.hub.datatype.exception.IllegalProtocol;
import edu.cmu.sbs.hub.datatype.exception.PatientNotFoundException;
import edu.cmu.sbs.protocol.StatusProtocol;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.util.Map;

import static spark.Spark.*;

public class Reception {

    final private String FAILURE = "Failure";
    final private String SUCCESS = "Success";

    private Gson gson = new Gson();

    public Reception(Kiosk kiosk) {

        Logger logger = LoggerFactory.getLogger("Reception");

        port(26666);

        post("/biogears/update", (request, response) -> {

            logger.info(LocalTime.now().format(DateTimeFormatter.ISO_LOCAL_TIME) + " received " + request.body());

            try {
                kiosk.receive(new StatusProtocol(gson.fromJson(request.body(), Map.class)));

                return SUCCESS;
            } catch (PatientNotFoundException e) {
                logger.error(e.getMessage());
                return FAILURE;
            }
        });

        // TODO establish transfer protocol
        get("/unity/status", (request, response) -> {

            //return PatientStatus.getRandomFakeStatus();

            try {
                return kiosk.locatePatient("abcdefg").getStatus().toString();
            } catch (PatientNotFoundException e) {
                logger.error(e.getMessage());
                return FAILURE;
            } finally {
                logger.info("Status Update Success");
            }

        });

        // TODO establish create protocol
        get("/unity/create", (request, response) -> {
            try {
                kiosk.createPatient(request.toString());
                return SUCCESS;
            } catch (IllegalProtocol illegalProtocol) {
                logger.error(illegalProtocol.getMessage());
                return FAILURE;
            }


        });

        // TODO establish Action pattern
        get("/unity/:action", (request, response) -> {
            if (request.params(":action").equals("inject")) {
                logger.info("Inject Action Received");
                Action.inject();
            }
            return 0;
        });
    }
}
