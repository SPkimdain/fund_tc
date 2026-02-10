package basic;

import java.util.io;
import javax.ejb.Stateless;

@Stateless
public class ClassLoaderBean implements ClassLoaderLocal {

    public void loadClasses() {
        try {
            Class<?> classForName = Class.forName("com.example.MyClass"); //@violation
            ClassLoader test = Thread.currentThread().getContextClassLoader();
            Class<?> contextClass = test.loadClass("com.example.MyClass"); //@violation
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}