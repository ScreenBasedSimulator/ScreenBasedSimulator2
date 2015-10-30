package edu.cmu.sbs.hub.server;

import com.google.gson.Gson;
import edu.cmu.sbs.hub.datatype.PatientStatus;
import edu.cmu.sbs.protocol.StatusProtocol;

import java.time.LocalTime;
import java.time.format.DateTimeFormatter;

import static spark.Spark.port;
import static spark.Spark.post;

public class HttpServer {
    private static Gson gson = new Gson();

    public HttpServer() {

        port(8081);
        post("/update", (request, response) -> {

            System.out.println("Received at : " + LocalTime.now().format(DateTimeFormatter.ISO_LOCAL_TIME));
            System.out.println("received:\n" + request.body());
            StatusProtocol status = gson.fromJson(request.body(), StatusProtocol.class);



            System.out.println(status.toString());
            return 1;
        });

    }

    private StatusProtocol statusToProtocol(PatientStatus status) {
        StatusProtocol statusProtocol = new StatusProtocol();
        return statusProtocol;
    }

    public static void main(String[] args) {

        HttpServer server = new HttpServer();

    }


}
