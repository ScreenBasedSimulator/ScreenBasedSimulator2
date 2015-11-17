package edu.cmu.sbs.hub.server;

import com.github.kevinsawicki.http.HttpRequest;
import edu.cmu.sbs.hub.datatype.PatientStatus;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

public class Broadcast {

    final private static String serverIP = "0.0.0.0";
    final private static int port = 8081;
    final private static String url = "/update";

    public static void main(String[] args) {

        Logger logger = LoggerFactory.getLogger("Broadcaster");

        Runnable testRun = () -> {

            PatientStatus status = PatientStatus.getRandomFakeStatus();

            HttpRequest.post("http://" + serverIP + ":" + port + url).send(serialize(status)).code();
            logger.info("Sent at : " + LocalTime.now().format(DateTimeFormatter.ISO_LOCAL_TIME));
        };

        ScheduledExecutorService executorService = Executors.newSingleThreadScheduledExecutor();
        executorService.scheduleAtFixedRate(testRun, 0, 800, TimeUnit.MILLISECONDS);
    }

    public static String serialize(PatientStatus status) {
        return status.toString();
    }
}
