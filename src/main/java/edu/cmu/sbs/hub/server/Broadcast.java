package edu.cmu.sbs.hub.server;

import com.github.kevinsawicki.http.HttpRequest;
import edu.cmu.sbs.hub.datatype.PatientStatus;

import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

public class Broadcast {

    final private static String serverIP = "";

    public static void main(String[] args) {

        Runnable testRun = () -> {

            PatientStatus status = PatientStatus.getRandomFakeStatus();

            Calendar cal = Calendar.getInstance();
            SimpleDateFormat currentTime = new SimpleDateFormat("HH:mm:ss");
            String time = currentTime.format(cal.getTime());

            HttpRequest.post("http://" + serverIP + "/update").send(serialize(status)).code();
            System.out.println("Sent at " + time);
        };

        ScheduledExecutorService executorService = Executors.newSingleThreadScheduledExecutor();
        executorService.scheduleAtFixedRate(testRun, 0, 800, TimeUnit.MILLISECONDS);
    }

    public static String serialize(PatientStatus status) {
        return status.toString();
    }
}
