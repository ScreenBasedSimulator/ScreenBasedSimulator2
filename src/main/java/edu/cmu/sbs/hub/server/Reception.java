package edu.cmu.sbs.hub.server;

import com.google.gson.Gson;
import edu.cmu.sbs.hub.Kiosk;
import edu.cmu.sbs.hub.datatype.Patient;
import edu.cmu.sbs.hub.datatype.PatientStatus;
import edu.cmu.sbs.hub.datatype.PatientStatus.Metric;
import edu.cmu.sbs.hub.datatype.exception.PatientNotFoundException;
import edu.cmu.sbs.hub.logging.RecordKeeperEZ;
import edu.cmu.sbs.scoring.ScoringUtil;
import org.joda.time.DateTime;
import org.joda.time.Duration;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.util.EnumMap;

import static spark.Spark.*;

public class Reception {

    private static int counter = 10;
    private static boolean kill = false;
    final private String FAILURE = "Failure\n";
    final private String SUCCESS = "Success\n";
    final private DateTime startTime;
    private Gson gson = new Gson();
    private Action actionBag = new Action();
    private RecordKeeperEZ recordKeeperEZ;

    public Reception(Kiosk kiosk) {

        startTime = new DateTime();

        Logger logger = LoggerFactory.getLogger("Reception");

        recordKeeperEZ = kiosk.roster.recordKeeperEZ;
        staticFileLocation("/static");
        port(26666);

        // Obsolete
        //post("/biogears/update", (request, response) -> {
        //
        //    logger.info(LocalTime.now().format(DateTimeFormatter.ISO_LOCAL_TIME) + " received " + request.body());
        //
        //    try {
        //        Type castType = new TypeToken<Map<String, String>>() {
        //        }.getType();
        //
        //        kiosk.receive(new StatusProtocol(gson.fromJson(request.body(), castType)));
        //
        //        if (!kill && counter != 0) {
        //            counter--;
        //        } else if (!kill) {
        //            actionBag.kill();
        //            kill = true;
        //        }
        //
        //        return SUCCESS;
        //    } catch (PatientNotFoundException e) {
        //        logger.error(e.getMessage());
        //        return FAILURE;
        //    }
        //});

        // TODO establish transfer protocol
        get("/unity/status/:patienthash", (request, response) -> {

            try {
                // TODO for test patient, it will ALWAYS return a random data instead of actual Biogears data.

                return kiosk.locatePatient("abcdefg").getStatus().toString();
            } catch (PatientNotFoundException e) {
                logger.error(e.getMessage());
                return FAILURE;
            } finally {
                logger.info("Status Update Success");
            }

        });
        
        // TODO establish transfer protocol
        get("/report", (request, response) -> {
            try {
            	//warning: this part is only for testing use!
            	ScoringUtil scoringUtil = new ScoringUtil();
        		
        		//set model status
        		EnumMap<Metric, String> modelParamMap = new EnumMap<>(Metric.class);
        		modelParamMap.put(PatientStatus.Metric.HEART_RATE, "72.0");
        		modelParamMap.put(PatientStatus.Metric.SYSTOLIC_ARTERIAL_PRESSURE, "64");
                modelParamMap.put(PatientStatus.Metric.DIASTOLIC_ARTERIAL_PRESSURE, "105");
                modelParamMap.put(PatientStatus.Metric.OXYGEN_SATURATION, "97");
        		modelParamMap.put(PatientStatus.Metric.RESPIRATION_RATE, "100");
        		Patient patientModel = new Patient("model", "model", Patient.Gender.MALE, 0, 0.0, 0.0);
        		patientModel.updateStatus(modelParamMap);
        		scoringUtil.setModel(patientModel);
        		
        		//set new Patient every second, until game over
        		Patient initialPatient = Patient.generateRandomPatient();
        		initialPatient.updateStatus(PatientStatus.getRandomFakeStatus().getStatus());
        		scoringUtil.setPatient(initialPatient);
            	
                return scoringUtil.getReport();
            } catch (Exception e) {
                logger.error(e.getMessage());
                return FAILURE;
            } finally {
                logger.info("Report successfully sent");
            }

        });

        // TODO establish create protocol
        //get("/unity/create", (request, response) -> {
        //    try {
        //        kiosk.createPatient(request.toString());
        //        return SUCCESS;
        //    } catch (IllegalProtocol illegalProtocol) {
        //        logger.error(illegalProtocol.getMessage());
        //        return FAILURE;
        //    }
        //
        //
        //});

        // Obsolete
        //get("/scoring/die:hash", (request, response) -> {
        //    String id = request.params(":hash");
        //
        //    try {
        //        kiosk.roster.locatePatient(id).die();
        //        return "Success";
        //    } catch (PatientNotFoundException e) {
        //        logger.error("Patient " + id + " does not exist");
        //        return "Failure";
        //    }
        //});

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
        post("/unity/create/:patientHash", (request, response) -> {
            return SUCCESS;
        });
    }


    public void logAction(String action) {
        recordKeeperEZ.log(format(action));
    }

    private String format(String entry) {
        return String.format("%1$%-15s %2$10s", new Duration(startTime, new DateTime()) + " :", entry);
    }
}
