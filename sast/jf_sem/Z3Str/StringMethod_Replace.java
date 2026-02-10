package z3str;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class StringMethod_Replace {
	
	private static final long serialVersionUID = 1L;
	
	public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doPost(request, response);
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		response.setContentType("text/html");
	
		String param = request.getParameter("vector");
		if (param == null) param = "";
		
		
		String bar = "";
		if (param != null && param.length() > 1) {
		    StringBuilder sbxyz51584 = new StringBuilder(param);
		    bar = sbxyz51584.replace(param.length()-"Z".length(), param.length(),"Z").toString();
		}
		
		
		int length = 1;
		if (bar != null) {
			length = bar.length();
			response.getWriter().write(bar,0,length);
		}
	}
}
