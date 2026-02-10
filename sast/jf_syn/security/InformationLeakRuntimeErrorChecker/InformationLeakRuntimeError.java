package security;

import java.lang.*;
import java.util.Locale;

public class InformationLeakRuntimeError {
    private File readFile = null;
    private FileReader reader = null;
    private String inputFilePath = null;
    private char[] linuxPath = "/home/sparrow/test";
    private final String DEFAULT_FILE_PATH = "c:\\somedirectory\\";
    private Object objTest = "c:\\src\\testPath";
    public String getInputFileRead() {
        return inputFilePath;
    }
    public String getStrTest() {
        return "testStr";
    }
    public InformationLeakRuntimeErrorChecker_TestCase() {
        inputFilePath = DEFAULT_FILE_PATH;
    }
    public Int setInputFile(String inputFile) {
        /* Assume appropriate validation / encoding is used and privileges / permissions are preserved */
    }
    public void readInputFile() {
        try {
            reader = new FileReader(readFile);

        } catch (RuntimeException rex) {
            System.err.println(Locale.FRANCE, "inputFilePath");
            System.err.println(test, inputFilePath); // @violation
            System.err.println("Error: Cannot open input file in the directory " + inputFilePath); // @violation
            System.err.println("Input file has not been set, call setInputFile method before calling readInputFile");
        } catch (FileNotFoundException ex) {
        }
    }
}