package edu.cmu.sbs.hub.server;

import java.util.NoSuchElementException;

import edu.cmu.sbs.hub.Kiosk;
import edu.cmu.sbs.hub.datatype.Patient;
import edu.cmu.sbs.hub.datatype.Patient.PatientBuilder;
import edu.cmu.sbs.hub.datatype.PatientStatus.PatientStatusBuilder;
import edu.cmu.sbs.hub.logging.RecordKeeperEZ;
import edu.cmu.sbs.scoring.ScoringUtil;

import org.joda.time.DateTime;
import org.joda.time.Duration;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import static spark.Spark.*;

public class Reception {

    private static int counter = 10;
    private static boolean kill = false;
    final private String FAILURE = "Failure\n";
    final private String SUCCESS = "Success\n";
    final private DateTime startTime;
    private Action actionBag = new Action();
    private RecordKeeperEZ recordKeeperEZ;

    public Reception(Kiosk kiosk) {

        startTime = new DateTime();

        Logger logger = LoggerFactory.getLogger("Reception");

        recordKeeperEZ = kiosk.roster.recordKeeperEZ;
        staticFileLocation("/static");
        port(26666);


        // TODO establish transfer protocol
        get("/unity/status/:patientUUID", (request, response) -> {
            try {
                String uuid = request.params("patientUUID");
                return kiosk.locatePatient(uuid).getStatus().toString();
            } catch (NoSuchElementException e) {
                logger.error(e.getMessage());
                return FAILURE;
            } catch (IllegalStateException e) {
                return "patient is not ready";  
            } finally {
                logger.info("Status Update Success");
            }

        });
        
        // TODO establish transfer protocol
        get("/report/:patientHash", (request, response) -> {
            try {
            	//warning: this part is only for testing use!
            	ScoringUtil scoringUtil = new ScoringUtil();
        		
        		//set model status
            	Patient standardPatient = new PatientBuilder().isStatic(true).build();
                PatientStatusBuilder builder = new PatientStatusBuilder();
                builder.setHeartRate(72.0)
                       .setSystolicArterialPressure(64.0)
                       .setDiastolicArterialPressure(105.0)
                       .setOxygenSaturation(97)
                       .setRespirationRate(16.0);
                
                standardPatient.setStatus(builder.build());
        		scoringUtil.setStandartPatient(standardPatient);
        		
        		//set new Patient every second, until game over
        		Patient initialPatient = Patient.generateRandomPatient();
//        		initialPatient.updateStatus(PatientStatus.getRandomFakeStatus());
        		scoringUtil.setPatient(initialPatient);
            	
                return scoringUtil.getReport();
            } catch (Exception e) {
                logger.error(e.getMessage());
                return FAILURE;
            } finally {
                logger.info("Report successfully sent");
            }

        });


        post("/unity/action/:patientHash/:action", (request, response) -> {

            String action = request.params(":action").toLowerCase();
            String hash = request.params(":patientHash");

            logger.info(action + " Action Received on patient: " + hash);

            switch (action) {
                case "oxygen":
                    String status = request.queryParams("status");

                    if (status.equals("on")) {
                        Action.resumeOxygen(kiosk.locatePatient(hash));
                    } else {
                        Action.noOxygen(kiosk.locatePatient(hash));
                    }

                    //logging
                    logAction(action);

                    return SUCCESS;

                case "kill":
                    Action.kill(kiosk.locatePatient(hash));

                    //logging
                    logAction(action);

                    return SUCCESS;
                case "inject":

                    logAction("Injecting " + request.queryParams("drug_name") + ":" + Double.parseDouble(request.queryParams("dose") + " on " + hash));
                    Action.inject(kiosk.locatePatient(hash), request.queryParams("drug_name"), Double.parseDouble(request.queryParams("dose")));

                    // TODO inject content is unlogged
                    logAction(action);

                    return SUCCESS;

                default:
                    return FAILURE;
            }
        });

        // TODO
        post("/unity/create", (request, response) -> {
            Patient patient = kiosk.createPatient("standard");
            return patient.getUUID();
        });
    }


    public void logAction(String action) {
        recordKeeperEZ.log(format(action));
    }

    private String format(String entry) {
        return String.format("%1$%-15s %2$10s", new Duration(startTime, new DateTime()) + " :", entry);
    }
}
