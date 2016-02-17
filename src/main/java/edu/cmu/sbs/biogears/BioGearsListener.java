package edu.cmu.sbs.biogears;

import mil.tatrc.physiology.utilities.Log;
import mil.tatrc.physiology.utilities.LogListener;

public class BioGearsListener extends LogListener {
    protected BioGearsListener() {
        super();
        listen(false);
    }

    public void handleDebug(String msg) {
        Log.debug(msg);
    }

    public void handleInfo(String msg) {
        Log.info(msg);
    }

    public void handleWarn(String msg) {
        Log.warn(msg);
    }

    public void handleError(String msg) {
        Log.error(msg);
    }

    public void handleFatal(String msg) {
        Log.fatal(msg);
    }
}
