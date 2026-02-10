import java.io.*;
import pobis.framework.base.POBISException;

public class MissingCauseExceptionInThrow {
    public void violation1() throws POBISException {
        try {
            FileReader reader = new FileReader("D:\\file.txt");
        } catch (IOException e) {
            throw new POBISException("BEXYZ00000");                                             // @violation
        }
    }

    public void violation2() throws POBISException {
        try {
            FileReader reader = new FileReader("D:\\file.txt");
        } catch (IOException e) {
            Exception e1 = new Exception();

            throw new POBISException("BEXYZ00000", e1);                                         // @violation
        }
    }

    public void violation3() throws POBISException {
        try {
            FileReader reader = new FileReader("D:\\file.txt");
        } catch (Exception e) {
            throw new POBISException("BEXYZ00000", new Object[]{"주민번호"});                   // @violation
        }
    }

    public void violation4() throws POBISException {
        String address = requestData.getString("주민번호");
        if(StringUtils.isBlank(address)) {
            throw new POBISException("BEXYZ00000", new Object[]{address}, new Exception());     // @violation
        }
    }

    public void violation6() throws POBISException {
        try {
            FileReader reader = new FileReader("D:\\file.txt");
        } catch (Exception e) {
            throw new POBISException();                                                         // @violation
        }
    }

    public void good1() throws POBISException {
        try {
            FileReader reader = new FileReader("D:\\file.txt");
        } catch (IOException e) {
            throw new POBISException("BEXYZ00000", e);                                          /* SAFE */
        }
    }

    public void good2() throws POBISException {
        try {
            FileReader reader = new FileReader("D:\\file.txt");
        } catch (Exception e) {
            throw new POBISException("BEXYZ00000", new Object[]{"주민번호"}, e);                /* SAFE */
        }
    }

    public void good3() throws POBISException {
        String address = requestData.getString("주민번호");
        if(StringUtils.isBlank(address)) {
            throw new POBISException("BEXYZ00000", new Object[]{address});                      /* SAFE */
        }
    }

    public void good4() throws POBISException {
        try {
            try {
                try {
                    FileReader reader = new FileReader("D:\\file.txt");
                } catch (IOException g) {
                    String s = e.getMessageId();
                    // Do Nothing
                } catch (Exception g) {
                    throw new POBISException("BEXYZ00000", new Object[]{"주민번호"}, g);        /* SAFE */
                }
            } catch (Exception f) {
                throw new POBISException("BEXYZ00000", new Object[]{"주민번호"}, f);            /* SAFE */
            }
        } catch (Exception e) {
            throw new POBISException("BEXYZ00000", new Object[]{"주민번호"}, e);                /* SAFE */
        } catch (Exception e1) {
            throw new POBISException(e1);
        } catch (Exception e2) {
            throw new POBISException("BEXYZ00000", new Object[]{"주민번호"}, e2);               /* SAFE */
        }
    }
}
