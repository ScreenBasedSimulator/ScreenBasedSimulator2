package hub.core;

import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.util.Map;

import static spark.Spark.*;
import datatype.PatientStatus;
import com.google.gson.Gson;

public class HttpServer {
    private static Gson gson = new Gson();
    public HttpServer() {

        port(8081);
        post("/update", (request, response) -> {

            System.out.println("Received at : " + LocalTime.now().format(DateTimeFormatter.ISO_LOCAL_TIME));
            System.out.println("received:\n" + request.body());
            PatientStatus status = gson.fromJson(request.body(), Map<Metric, Double>.class);
            System.out.println(status.toString());
            return 1;
        });

    }

    public static void main(String[] args) {

        HttpServer server = new HttpServer();

    }


}
