class DoNotUseStringOperationInLog {
    public void violation1(org.slf4j.Logger logger) {
        String text = "Hello";

        logger.info("blah blah log " + text);           // @violation
    }

    public void violation2(org.apache.log4j.Logger log) {
        log.debug("blah blah log " + "Hello");          // @violation
    }

    public void violation3(org.slf4j.Logger logger) {
        String text = "Hello";
        int num = 12345;

        logger.info("blah blah log " + text + num);     // @violation
    }


    public void good1(org.slf4j.Logger logger) {
        String text = "Hello";

        logger.info("blah blah log Hello");             /* SAFE */
    }

    public void good2(org.apache.log4j.Logger log) {
        log.debug("blah blah log Hello");               /* SAFE */
    }

    public void good3(org.apache.log4j.Logger log) {
        log.debug("blah blah log {0}", "Hello");        /* SAFE */
    }

    public void good4(org.slf4j.Logger logger) {
        int num = 12345;

        logger.info("blah blah log " + num);           /* SAFE */
    }
}