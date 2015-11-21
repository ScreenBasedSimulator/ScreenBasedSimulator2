package edu.cmu.sbs.hub.server;

import com.google.gson.Gson;
import edu.cmu.sbs.hub.Kiosk;
import edu.cmu.sbs.hub.datatype.exception.PatientNotFoundException;
import edu.cmu.sbs.protocol.StatusProtocol;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.util.Map;

import static spark.Spark.*;

public class Reception {

    private Gson gson = new Gson();

    private Kiosk kiosk;

    public Reception(Kiosk kiosk) {

        Logger logger = LoggerFactory.getLogger("Reception");

        this.kiosk = kiosk;

        port(6666);

        // Receive status update from BioGears Engine
        post("/update", (request, response) -> {

            logger.info(LocalTime.now().format(DateTimeFormatter.ISO_LOCAL_TIME) + " received " + request.body());

            try {
                kiosk.receive(new StatusProtocol(gson.fromJson(request.body(), Map.class)));

                return true;
            } catch (PatientNotFoundException e) {
                logger.error(e.getMessage());
                return false;
            }
        });

        // TODO establish tranfter protocal
        get("/unity/status", (request, response) -> {

            //return PatientStatus.getRandomFakeStatus();

            try {

                return kiosk.locatePatient("abcdefg").getStatus();
            } catch (PatientNotFoundException e) {
                logger.error(e.getMessage());
                return "Error 404";
            } finally {
                System.out.println("Success");
            }

        });

        get("/test/:action", (request, response) -> {
            if (request.params(":action").equals("inject")) {
                logger.info("Inject Action Received");
                Action.inject();
            }
            return 0;
        });
    }


}
