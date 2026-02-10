package security;

import java.io.*;
import javax.servlet.*;

public class ServletWorkWithCommittedResponse {
    public void test(HttpServletRequest request, HttpServletResponse response)
            throws IOException, ServletException {
        PrintWriter out = response.getWriter();
        try {
            out.println("<html>");
            // ... Write some response text
            out.flush(); // Commits the stream
            // ... More work
        } catch (IOException x) {
            response.sendError(HttpServletResponse.SC_INTERNAL_SERVER_ERROR);   // @violation
        }
    }

    public void test2(HttpServletRequest request, HttpServletResponse response)
            throws IOException, ServletException {
        ServletOutputStream out = response.getOutputStream();
        try {
            out.println("<html>");
            // ... Write some response text
            out.flush(); // Commits the stream
            // ... More work
        } catch (IOException x) {
            out.println(x.getMessage());    // @violation
            out.flush();    // @violation
        }
    }
}