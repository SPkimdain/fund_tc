package basic;

import java.io.*;
import java.io.IOException;
import java.util.logging.Logger;

import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Writer: Gyuhang Shim
 * Date: 3/29/12
 */
public class ImproperCheckForUnusualOrExceptionalCondition extends HttpServlet {
    public static final String ITEM_NAME = "ITEM_NAME";
    public static final String IMPORTANT_ITEM = "IMPORTANT_ITEM";

    public void readFromFile(String fileName) {
        try {
            File file = new File(fileName);
            FileReader reader = new FileReader(file);

            // 아래 alarm 은 MethodIgnoresReturnValueChecker 에서 검증한다.
            reader.read();
            // do something

        }
        // 아래와 같이 광범위한 Exception 사용을 검출한다.
        catch (Exception | IOException e) { // @violation
            System.out.println("error");
        }
    }

    public void readFromFile2(String fileName) {
        try {
            File file = new File(fileName);
            FileReader reader = new FileReader(file);
        }
        // 제외 메소드 호출이 경우는 제외한다.
        catch (Exception e) { /* No ALARM */
            System.out.println("error");
            Logger.getAnonymousLogger();
        }
    }

    public void readFromFile3(String fileName) {
        try (File file = new File(fileName);
             FileReader reader = new FileReader(file);
        ) {
            // 아래 alarm 은 MethodIgnoresReturnValueChecker 에서 검증한다.
            reader.read();
            // do something

        }
        // 아래와 같이 광범위한 Exception 사용을 검출한다.
        catch (Exception | IOException e) { // @violation
            System.out.println("error");
        }
    }

    public void doPost(HttpServletRequest request, HttpServletResponse res) {
        String itemName = request.getParameter(ITEM_NAME);
        // HttpServletRequest.getParameter 에서 얻어온 값은 null 검사가 선행 되어야 한다.

        if (itemName.compareTo(IMPORTANT_ITEM) == 0) {
            // do something
        }
        if (itemName.equals(IMPORTANT_ITEM)) {
            // do something
        }

        if (itemName == null) { // null check
            // null handling
        }
        if (itemName.compareTo(IMPORTANT_ITEM) == 0) {
            // do something
        }
        if (itemName.equals(IMPORTANT_ITEM)) {
            // do something
        }
    }

    public void getSystemProperty() {
        String os = System.getProperty("os.name");
        // System.getProperty 에서 얻어온 값은 null 검사가 선행 되어야 한다.
        if (os.equalsIgnoreCase("Windows 95")) {
            System.out.println("Not supported");
        }

        if (os == null) { // null check
            // do something
        }
        if (os.equals("Windows 7")) {
            System.out.println("Windows 7 is the best.");
        }
    }

    public void bad() throws Throwable
    {
        String data;

        Logger log_bad = Logger.getLogger("local-logger");

        data = "FileReaderDemo.java"; /* init data */

        Socket sock = null;
        BufferedReader buffread = null;
        InputStreamReader instrread = null;
        try {
            /* Read data using an outbound tcp connection */
            sock = new Socket("192.168.0.100", 9000);

            /* read input from socket */
            instrread = new InputStreamReader(sock.getInputStream(), "UTF-8");
            buffread = new BufferedReader(instrread);

            data = buffread.readLine();
        }
        catch( IOException ioe )
        {
            log_bad.warning("Error with stream reading");
        }
        finally {
        	/* clean up stream reading objects */
            try {
                if( buffread != null )
                {
                    buffread.close();
                }
            }
            catch( IOException ioe )
            {
                IO.logger.log(Level.WARNING, "Error closing BufferedReader", ioe);
            }

            try {
                if( instrread != null )
                {
                    instrread.close();
                }
            }
            catch( IOException ioe )
            {
                IO.logger.log(Level.WARNING, "Error closing InputStreamReader", ioe);
            }

        	/* clean up socket objects */
            try {
                if( sock != null )
                {
                    sock.close();
                }
            }
            catch( IOException e )
            {
                IO.logger.log(Level.WARNING, "Error closing Socket", e);
            }
        }

        FileReader fr = null;
        BufferedReader br = null;
        try
        {
            if(data != null)
            {
                fr = new FileReader(data);
            }
            br = new BufferedReader(fr);
            String s;
            while((s = br.readLine()) != null)
            {
                System.out.println(s);
            }
        } catch (IOException | Exception e) // @violation
        {
			/* FLAW */
            IO.logger.log(Level.WARNING, "Unknown error occurred");
        }
        finally
        {
            try
            {
                if(br != null)
                {
                    br.close();
                }
            }
            catch(IOException ioe)
            {
                IO.logger.log(Level.WARNING, "Error closing bufferReader", ioe);
            }
            try
            {
                if(fr != null)
                {
                    fr.close();
                }
            }
            catch(IOException ioe)
            {
                IO.logger.log(Level.WARNING, "Error closing fileReader", ioe);
            }
        }
    }
}
