package ti;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;
import java.io.*;
import java.util.Properties;
import org.springframework.web.multipart.MultipartHttpServletRequest;
import org.springframework.web.multipart.MultipartFile;
import org.springframework.web.servlet.ModelAndView;
import java.util.ArrayList;
import java.util.List;
import java.util.zip.ZipFile;
import java.util.zip.ZipEntry;
import java.util.Enumeration;

/**
 * 디렉토리 경로 조작 을 테스트 해 볼수 있는 Test case
 * 상대경로 조작, 절대경로 조작 Test case 가 차례로 열거 되어 있다.
 * Writer: Gyuhang Shim
 * Date: 5/10/12
 */
public class PATH_TRAVERSAL_TestCase {
    public void pathTraversalRelativeTest(HttpServletRequest req, Properties request) {
        String name = request.getProperty("filename");
        name = req.getParameter("filename");
        if (name != null) {
            File file = new File("/usr/local/tmp/" + name); /* BUG 2 */
            file.delete();
        }
    }

    public void pathTraversalRelativeSafeTest(HttpServletRequest req, Properties request) {
        String name = request.getProperty("filename");
        name = req.getParameter("filename");
        if (name != null) {
            String sanitizedName = name.replaceAll("/","");
            File file = new File("/usr/local/tmp/" + sanitizedName);
            file.delete();
        }
    }

    public void pathTraversalRelativeTest2(HttpServletRequest req, Properties request) {
        String name = request.getProperty("filename");
        name = req.getParameter("filename");
        FileOutputStream outputStream = null;
        if (name != null) {
            try {
                outputStream = new FileOutputStream("/usr/local/tmp/" + name); /* BUG 2 */
                outputStream.write(1);
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            }
            finally {
                if (outputStream != null) {
                    try {
                        outputStream.close();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
            }
        }
    }

    public void pathTraversalAbsTest(HttpServletRequest req, Properties request) {
        String name = request.getProperty("filename");
        name = req.getParameter("filename");
        if (name != null) {
            FileInputStream file = null;
            try {
                file = new FileInputStream("/usr/local/tmp/" + name); /* BUG 2 */
                file.read();
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            } finally {
                try {
                    if(file != null) file.close();
                } catch (IOException e) {}
            }

        }
    }

    public void pathTraversalAbsSafeTest(HttpServletRequest req, Properties request) {
        String name = request.getProperty("filename");
        name = req.getParameter("filename");
        if (name != null) {
            name = name.replaceAll("/","");
            FileInputStream file = null;
            try {
                file = new FileInputStream("/usr/local/tmp/" + name); /* SAFE */
                file.read();
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            } finally {
                try {
                    if(file != null) file.close();
                } catch (IOException e) {}
            }

        }
    }

    // source : javax.servlet.http.HttpServletRequest.getQueryString()
    // sink :   java.io.File.File(java.lang.String)
    public void test1(HttpServletRequest request) {
        String fileName = request.getQueryString();

        try {
            File file = new File(fileName); /* BUG 2 */ // PATH_TRAVERSAL, RESOURCE_INJECTION
        } catch (Exception e) {

        }
    }

    // openeg 1
    public void springFileUpload1(HttpServletRequest request, MultipartHttpServletRequest multiPartRequest){
        String uploadPath = multiPartRequest.getContextPath()+"/files/";
        String orgFileName = multiPartRequest.getParameter("orgFile");
        MultipartFile newFile = multiPartRequest.getFile("newFile");
        String newFileName = newFile.getOriginalFilename();

        // if: when want to change upload file
        if(newFile != null && !newFileName.equals("")){
            if(orgFileName != null && !orgFileName.equals("")){
                // remove uploaded file
                File removeFile = new File(uploadPath  + orgFileName); /* BUG */
                removeFile.delete();
            }
            // create new upload file
            File newUploadFile = new File(uploadPath + newFileName); /* BUG */
            try {
                newFile.transferTo(newUploadFile);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

    }

    // openeg 2
    public ModelAndView boardDelete(HttpServletRequest request, HttpSession session){
        String uploadPath=request.getContextPath()+"/files/";
        System.out.println("uploadPath: "+uploadPath);
        String userId = (String) session.getAttribute("userId");
        int idx = Integer.parseInt(request.getParameter("idx"));

        ModelAndView mav = new ModelAndView();

        if(!userId.equals("1")){
            mav.addObject("errCode", "1");    // it's forbidden connection
            mav.addObject("idx", idx);
            mav.setViewName("redirect:view.do");
        } else {
            List<Integer> commentList = new ArrayList<Integer>();
            if(commentList.size() > 0){
                mav.addObject("errCode", "2"); // can't delete because a article has comments
                mav.addObject("idx", idx);
                mav.setViewName("redirect:view.do");
            } else {
                // if: when the article has upload file - remove that
                if(commentList.iterator() != null) {
                    File removeFile = new File(uploadPath + mav.toString()); /* SAFE */
                    removeFile.delete();
                }
                //
                mav.setViewName("redirect:list.do");
            }
        }
        return mav;
    }

    public void pathTraversalZipFile(String f) {
        try {
            ZipFile zf = new ZipFile(f);
            final Enumeration<? extends ZipEntry> zipEntries = zf.entries();
            while (zipEntries.hasMoreElements()) {
                ZipEntry ze = zipEntries.nextElement();
                String name = ze.getName();
                if (name != null) {
                    File file = new File("/usr/local/tmp/", name); /* BUG 2 */
                    file.delete();
                }
            }
        }
        catch (Exception e) {

        }
    }

}
