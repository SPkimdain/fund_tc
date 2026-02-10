package security;

import javax.servlet.http.HttpServletRequest;
import java.io.FileOutputStream;
import java.io.ObjectOutputStream;

public class SavingUnserializableObjectsToDisk {
    public static void main(String[] args, HttpServletRequest request) {
        String userinput = request.getParameter("dan");

        Dan_Serial danSerial = new Dan_Serial(userinput);

        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("Dan_objectData.ser"))) {
            oos.writeObject(danSerial);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}