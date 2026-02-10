package pmd;

public class AvoidUsingHardCodeIP {
    String testCase1 = "127.0.0.1"; // @violation
    String testCase2 = "2001:0DB8:1000:0000:0000:0000:1111:2222"; // @violation
    String testCase3 = "2001:DB8:1000::1111:2222"; // @violation
    String testCase4 = "999.999.999.999";
    String testCase5 = "255.255.0.0"; // @violation
    String testCase6 = "BEAF:2002:0221:F207:0000:0000:FFFF:4002"; // @violation
    String testCase7 = "BEAF:2002:0221:F207:0:0:FFFF:4002"; // @violation
    String testCase8 = "::"; /* safe*/
    String testCase9 = "ffff::ffff"; // @violation
    String testCase10 = "1234::"; /* safe */
}

