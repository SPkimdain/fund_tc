package custom;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import org.springframework.stereotype.Controller;
import org.springframework.stereotype.Service;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.multipart.MultipartFile;
import org.springframework.web.multipart.MultipartHttpServletRequest;
import org.springframework.web.servlet.ModelAndView;
import org.apache.log4j.Logger;

public class DataLeakBetweenSessionsUri extends HttpServlet {
    private String name1; // @violation
    private static String name2; // @violation
    private final String name3;

    public class DataLeakPattern1 extends HttpServlet {
        private String pattern1; //@violation
    }

    public class DataLeakPattern2 extends HttpServlet {
        private String safe; //It's ok.

        public DataLeakPattern2(Object obj) {
            safe = WFApplicationContext.getBean(obj, Some.class);
        }
    }

    public class DataLeakPattern3 extends HttpServlet {
        private String safe; //It's ok.

        //...

        public void doSomething(Object obj) {
            safe = WFApplicationContext.getBean(obj, Some.class);
        }
    }

    public class DataLeakPattern4 extends HttpServlet {
        private String safe; //It's ok.

        private String pattern4; //@violation

        public DataLeakPattern2(Object obj) {
            safe = WFApplicationContext.getBean(obj, Some.class);
        }
    }

}
