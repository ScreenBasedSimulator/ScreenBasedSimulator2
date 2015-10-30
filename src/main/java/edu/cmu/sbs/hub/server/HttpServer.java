package edu.cmu.sbs.hub.server;

import com.google.gson.Gson;
import edu.cmu.sbs.hub.Kiosk;
import edu.cmu.sbs.protocol.StatusProtocol;

import java.time.LocalTime;
import java.time.format.DateTimeFormatter;

import static spark.Spark.port;
import static spark.Spark.post;

public class HttpServer {

    private Gson gson = new Gson();

    private Kiosk kiosk;

    public HttpServer(Kiosk kiosk) {

        this.kiosk = kiosk;

        port(8081);
        post("/update", (request, response) -> {

            System.out.println("Received at : " + LocalTime.now().format(DateTimeFormatter.ISO_LOCAL_TIME));
            System.out.println("received:\n" + request.body());

            kiosk.receive(gson.fromJson(request.body(), StatusProtocol.class));

            return 1;
        });
    }


}
