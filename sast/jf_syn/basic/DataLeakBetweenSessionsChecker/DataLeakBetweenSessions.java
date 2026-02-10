package basic;

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

public class DataLeakBetweenSessions extends HttpServlet {
    private String name1; // @violation
    private static String name2; // @violation
    private final String name3;

    @Controller
    public class InnerController {
        //
        // * User variable
        // article, page variables
        private int currentPage = 1;
        private int showArticleLimit = 10; // change value if want to show more articles by one page
        private int showPageLimit = 10; // change value if want to show more page links
        private int startArticleNum = 0;
        private int endArticleNum = 0;
        private int totalNum = 0;
        @Autowired private ModelDao modelDao;

        @Override
        protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
            name1=req.getParameter("name");
        }

        private class InnerClass {
            private String field;
        }

        private class InnerHttpClass extends DataLeakBetweenSessions {
            private String field; // @violation
        }

        @RequestMapping("/list.do")
        public ModelAndView boardList(HttpServletRequest request, HttpServletResponse response) {

            String type = null;
            String keyword = null;

            // set variables from request parameter
            if(request.getParameter("page") == null || request.getParameter("page").trim().isEmpty() || request.getParameter("page").equals("0")) {
                currentPage = 1; // @violation
            } else {
                currentPage = Integer.parseInt(request.getParameter("page")); // @violation
            }

            if(request.getParameter("type") != null) {
                type = request.getParameter("type").trim();
            }

            if(request.getParameter("keyword") != null) {
                keyword = request.getParameter("keyword").trim();
            }
            //

            // expression article variables value
            startArticleNum = (currentPage - 1) * showArticleLimit + 1; // @violation
            endArticleNum = startArticleNum + showArticleLimit -1; // @violation
            //

            // get boardList and get page html code
            List<BoardModel> boardList;
            if(type != null && keyword != null) {
                boardList = service.searchArticle(type, keyword, startArticleNum, endArticleNum);
                totalNum = service.getSearchTotalNum(type, keyword); // @violation
            } else {
                boardList = service.getBoardList(startArticleNum, endArticleNum);
                totalNum = service.getTotalNum(); // @violation
            }
            StringBuffer pageHtml = getPageHtml(currentPage, totalNum, showArticleLimit, showPageLimit, type, keyword);
            //

            ModelAndView mav = new ModelAndView();
            mav.addObject("boardList", boardList);
            mav.addObject("pageHtml", pageHtml);
            mav.setViewName("/board/list");
            this.modelDao = new ModelDaoImpl(); /* Excluded */
            return mav;
        }
    }

    @Service
    public class InnerService {
        private int totalNum = 0;
        @Autowired private ModelDao modelDao;
        private Logger logger;

        public void doFunc() {
            totalNum = 1; // @violation
            modelDao = new ModelDaoImpl(); /* Excluded */
            logger = Logger.getLogger("abc"); /* Excluded */
        }
    }
}
