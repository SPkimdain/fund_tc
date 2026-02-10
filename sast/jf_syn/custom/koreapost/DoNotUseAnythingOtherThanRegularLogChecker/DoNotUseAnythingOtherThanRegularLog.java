import nexcore.framework.core.log.ILog;
import org.apache.commons.logging.Log;

class DoNotUseAnythingOtherThanRegularLog {
    public void violation() {
        Log log = getLog(onlineCtx);        // @violation
    }

    public void good() {
        ILog log = getLog(onlineCtx);       /* SAFE */
    }
}