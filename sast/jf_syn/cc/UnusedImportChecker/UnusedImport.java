package cc;

import java.util.Map; // @violation
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;
import com.fasoo.CustomClass;
import com.fasoo.sparrow.*;
import static com.fasoo.CustomClass.unusedStaticMethod; // @violation
import static com.fasoo.CustomClass.usedStaticMethod;
import org.springframework.beans.factory.annotation.Autowired;
import com.fasoo.sparrow.*; // @violation

import java.lang.Exception; // @violation
import java.io.IOException; // @violation
import java.sql.SQLException;

import cc.*; // @violation

import org.springframework.stereotype.Repository;

@Repository
public class UnusedImport {
    public void func() throws SQLException {
        HashMap hm = new HashMap();
        List<HashMap> hmList = new ArrayList<HashMap>();
        int v = CustomClass.STATIC_VALUE;
        int w = com.fasoo.CustomClass.STATIC_VALUE;
        int x = CustomClass.STATIC_INSTANCE.STATIC_VALUE;
        int y = com.fasoo.CustomClass.STATIC_INSTANCE.STATIC_VALUE;
        try {
            usedStaticMethod(v, w, x, y);
        } catch(Exception e) {
            // Do something ...
        }
    }

    @Autowired
    public void auto() {
        // Do something ...
    }
}
