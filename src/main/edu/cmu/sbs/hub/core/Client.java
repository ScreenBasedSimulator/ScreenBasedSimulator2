package hub.core;

import com.github.kevinsawicki.http.HttpRequest;
import datatype.PatientStatus;

import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

public class Client {


    public static void main(String[] args) {
//        Scanner in = new Scanner(System.in);
//
//        String str = in.nextLine();
//
//        while (!str.isEmpty()) {
//            HttpRequest.post("http://localhost:8081").send("hahaha").code();
//            str = in.nextLine();
//        }


//        for (int i = 1; i < 20; i++) {
//            HttpRequest.post("http://localhost:8081").send("test").code();
//        }

        Runnable testRun = () -> {

            PatientStatus status = PatientStatus.getRandomFakeStatus();

            Calendar cal = Calendar.getInstance();
            SimpleDateFormat currentTime = new SimpleDateFormat("HH:mm:ss");
            String time = currentTime.format(cal.getTime());

            HttpRequest.post("http://localhost:8081/update").send(serialize(status)).code();
            System.out.println("Sent at " + time);
        };

        ScheduledExecutorService executorService = Executors.newSingleThreadScheduledExecutor();
        executorService.scheduleAtFixedRate(testRun, 0, 800, TimeUnit.MILLISECONDS);
    }

    public static String serialize(PatientStatus status) {
        return status.toString();
    }
}
