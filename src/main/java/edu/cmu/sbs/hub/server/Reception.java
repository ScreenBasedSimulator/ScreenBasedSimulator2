package edu.cmu.sbs.hub.server;

import com.google.gson.Gson;
import edu.cmu.sbs.hub.Kiosk;
import edu.cmu.sbs.protocol.ActionProtocol;
import edu.cmu.sbs.protocol.StatusProtocol;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.time.LocalTime;
import java.time.format.DateTimeFormatter;

import static spark.Spark.*;

public class Reception {

    private Gson gson = new Gson();

    private Kiosk kiosk;

    public Reception(Kiosk kiosk) {

        Logger logger = LoggerFactory.getLogger(this.getClass());

        this.kiosk = kiosk;

        port(8081);
        post("/update", (request, response) -> {

            logger.info("Received at : " + LocalTime.now().format(DateTimeFormatter.ISO_LOCAL_TIME));
            logger.info("received:\n" + request.body());

            kiosk.receive(gson.fromJson(request.body(), StatusProtocol.class));

            return 1;
        });

        get("/unity/status", (request, response) -> {

            kiosk.receive(gson.fromJson(request.body(), ActionProtocol.class));

            StringBuilder sb = new StringBuilder();

            return sb.toString();
        });
    }


}
