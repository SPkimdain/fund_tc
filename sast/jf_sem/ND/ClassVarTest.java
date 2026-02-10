package nd;

import java.io.File;

class ClassVarTest {
    String name;
    File file;
    String setName() {
        if(this.name == null) {
            try {
                this.name = this.file.getCanonicalPath();
            } catch(Exception e) {
                this.name = this.file.getAbsolutePath();
            }
        }
        return this.name;
    }
    void checkName() {
        setName();
        String x = setName();
        x.toUpperCase();
        return;
    }
}