import java.io.*;

public class SecurityCallFileDelete {
    public void test() {
        File file = new File("file");
        file.delete();                   // @violation
        if (file.delete() == 0) {       /* Safe */
            System.out.println("Deletion failed");
        } else if(!file.delete()) {     /* Safe */
            System.out.println("Deletion failed");
        } else if(file.delete()) {      /* Safe */
            System.out.println("Deletion failed");
        }

        if(condition) {
            file.delete();                  // @violation
        }
    }
}