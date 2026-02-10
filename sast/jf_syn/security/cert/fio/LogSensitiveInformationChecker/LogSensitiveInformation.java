import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.logging.Logger;

class LogSensitiveInformation {
    private void generateSecurityException() throws SecurityException {
        throw new SecurityException();
    }

    public void logRemoteIPAddress(String name) {
        Logger logger = Logger.getLogger("com.organization.Log");
        InetAddress machine = null;
        try {
            machine = InetAddress.getByName(name);
            // ...
            generateSecurityException();
        } catch (UnknownHostException e) {
            // Do Nothing
        } catch (SecurityException e) {
            logger.severe(name + "," + machine.getHostAddress() + "," + e);		// violation     // FORWARD_NULL, LOG_SENSITIVE_INFORMATION for jf_sem
        }
    }

    public void sensitiveVariable() {
        Logger logger = Logger.getLogger("com.organization.Log");

        int passengerAge = 20;
        int ageUser = 21;
        String age = "22";

        logger.info("Age: " + passengerAge);                            		// @violation       // for jf_syn
        logger.info(String.valueOf(ageUser));                                 	// @violation       // for jf_syn
        logger.info(age);                                                    	// @violation       // for jf_syn
    }
}