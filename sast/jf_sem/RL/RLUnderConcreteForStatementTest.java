package rl;

import java.io.IOException;
import java.lang.String;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.FileOutputStream;

class RLUnderConcreteForStatementTest {
    public String getUserAll(){
        try{
            for (int i =0; i<470; i++) ;

            String sData = "";

            FileOutputStream fosLdap = new FileOutputStream("c:\\LdapSearchAll.txt");
            BufferedWriter bwLdap = new BufferedWriter(new OutputStreamWriter(fosLdap));
            bwLdap.write(sData);
            return "ALL"; /* BUG */
        }
        catch (IOException ex) {
        }
        catch (Exception e) {
        }
        return "";
    }
}



