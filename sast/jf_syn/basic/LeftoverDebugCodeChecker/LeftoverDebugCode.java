package basic;

import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import jakarta.ejb.*; //J2EE 환경 설정. J2EE환경이 아닐시에는, public static void main(String [] args) 를 잡지 않는다.

public class LeftoverDebugCode extends HttpServlet {
    public static void main(String[] a) { // @violation
        if(a!=null && a[0] instanceof String)
            System.out.println(a.length);
    }

    public void doPost(HttpServletRequest request, HttpServletResponse response) {
        if (request.getParameter("debug")) {
            System.out.println("debug code here."); // @violation
        }

        if (request.getParameter("debug")) { System.out.println("debug code here."); } // @violation

        if (request.getParameter("debug"))
            System.out.println("debug code here."); // @violation

        if (request.getParameter("debug")) System.out.println("debug code here."); // @violation

        if (request.getParameter("debug") &&
                request.getParameter("debug")) {
            System.out.println("debug code here."); // @violation
            int a = 10;
        }
    }
}

class LeftoverDebugCode1 extends HttpServlet {
    public static void main(String []a) { // @violation
    }
}

class LeftoverDebugCode2 extends HttpServlet {
    public static void main(String a[]) { // @violation
    }
}

class LeftoverDebugCode3{
    public static void main(String[] a) { // @violation
    }
}

class LeftoverDebugCode4 extends HttpServlet {
    public static final void main(String[] a) {
    }
}

class LeftoverDebugCode5 extends HttpServlet {
    public static void main(String a) {
    }
}

class LeftoverDebugCode6 {
    public void bad() throws Throwable
    {
        String data;

        Logger log_bad = Logger.getLogger("local-logger");

        data = ""; /* init data */

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
            //message for debugging
            /* FLAW */
            System.out.println("Debugging...data: " + data); // @violation
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
    }
}
