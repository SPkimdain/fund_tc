//SERVER_SIDE_REQUEST_FORGERY
package security;

import javax.servlet.http.HttpServletRequest;
import java.util.Hashtable;
import java.net.*;

public class ServerSideRequestForgery extends HttpServlet {

    @Override
    public void doGet(HttpServletRequest request, HttpServletResponse resp) throws IOException {
        try {
            HashSet<String> whiteList = new HashSet<String>();

            String sUrl = request.getParameter("url");
            String sUrl2 = request.getParameter("url");
            String sUrl3 = request.getParameter("url");
            URL url = new URL(request.getParameter("url")); // @violation
            URL url2 = new URL(sUrl); // @violation
            
            if (!whiteList.contains(sUrl2)) {
                throw new IOException();
            }
            URL url3 = new URL(sUrl2);    /* Safe */

            if(!checkParam(sUrl3)) {
                throw new IOException();
            }
            URL url4 = new URL(sUrl3);    /* Safe */
            
            
        } catch (IOException e) {
            //..
        }
	}

    public boolean checkParam(String inputData) {
        return inputData;
    }
}