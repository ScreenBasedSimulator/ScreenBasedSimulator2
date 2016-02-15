package edu.cmu.sbs.hub.logging;

import edu.cmu.sbs.hub.datatype.Patient;
import org.joda.time.DateTime;
import org.joda.time.Duration;
import org.joda.time.format.PeriodFormatter;
import org.joda.time.format.PeriodFormatterBuilder;

import java.util.Date;
import java.util.HashMap;
import java.util.LinkedList;

public class RecordKeeperEZ {

    // Time util
    PeriodFormatter formatter = new PeriodFormatterBuilder()
            .appendDays()
            .appendSuffix(":")
            .appendHours()
            .appendSuffix(":")
            .appendMinutes()
            .appendSuffix(":")
            .appendSeconds()
            .toFormatter();
    // reserved for multiple patients implementation
    // always register patient in logging system when creating new patient
    HashMap<Patient, LinkedList<Event>> patientEventsMap = new HashMap<>();
    HashMap<Patient, DateTime> startTimeMap = new HashMap<>();
    Patient preExistingPatient = null;
    public RecordKeeperEZ() {
    }

    public void registerPatient(Patient patient) {
        patientEventsMap.put(patient, new LinkedList<>());
        startTimeMap.put(patient, new DateTime(new Date()));
        preExistingPatient = patient;
    }

    public void log(String action) {
        patientEventsMap.get(preExistingPatient).add(new Event(new DateTime(new Date()), action));
    }

    public String generateReport(Patient patient) {
        StringBuilder sb = new StringBuilder();
        sb.append("---------------------------------------------------\n");
        sb.append(patient);
        sb.append("\n");

        DateTime startTime = startTimeMap.get(patient);

        LinkedList<Event> patientEvents = patientEventsMap.get(patient);

        for (Event e : patientEvents) {
            sb.append(getFormatted(startTime, e.time));
            sb.append(e.action);
            sb.append("\n");
        }

        return sb.toString();
    }

    private String getFormatted(DateTime start, DateTime end) {
        return String.format("%-10s", formatter.print(new Duration(start, end).toPeriod()));
    }

    class Event {
        DateTime time;
        String action;

        public Event(DateTime time, String action) {
            this.time = time;
            this.action = action;
        }
    }
}
