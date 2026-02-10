package com.example;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class LoggerTestCase {

    private static final Logger logger = LoggerFactory.getLogger(LoggerTestCase.class);

    public static void main(String[] args) {
        String msg = "message";

        JavaNode node = new JavaNode();

        logger.debug("User password is 1234", node.toString());
        logger.info("This contains secret information", node.toString());
        logger.error("ERROR: Password leaked!", node.toString());

        logger.debug(msg, node);
        logger.info(msg, node);
        logger.error(msg, node);
    }
}

class JavaNode {
    @Override
    public String toString() {
        return "JavaNodeObject";
    }
}
