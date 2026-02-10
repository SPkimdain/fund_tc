class SensitiveClass {
    private char[] filename;
    private Boolean shared = false;

    SensitiveClass(String filename) {
        this.filename = filename.toCharArray();
    }

    final void replace() {
        if (!shared) {
            for(int i = 0; i < filename.length; i++) {
                filename[i]= 'x' ;}
        }
    }

    final String get() {
        if (!shared) {
            shared = true;
            return String.valueOf(filename);
        } else {
            throw new IllegalStateException("Failed to get instance");
        }
    }

    final void printFilename() {
        System.out.println(String.valueOf(filename));
    }
}

class MaliciousSubclass extends SensitiveClass implements Cloneable {   // @violation
    protected MaliciousSubclass(String filename) {
        super(filename);
    }

    @Override public MaliciousSubclass clone() {  // Well-behaved clone() method
        MaliciousSubclass s = null;
        try {
            s = (MaliciousSubclass)super.clone();
        } catch(Exception e) {
            System.out.println("not cloneable");
        }
        return s;
    }

    public static void main(String[] args) {
        MaliciousSubclass ms1 = new MaliciousSubclass("file.txt");
        MaliciousSubclass ms2 = ms1.clone(); // Creates a copy
        String s = ms1.get();  // Returns filename
        System.out.println(s); // Filename is "file.txt"
        ms2.replace();         // Replaces all characters with 'x'
        // Both ms1.get() and ms2.get() will subsequently return filename = 'xxxxxxxx'
        ms1.printFilename();   // Filename becomes 'xxxxxxxx'
        ms2.printFilename();   // Filename becomes 'xxxxxxxx'
    }
}

class SafeSensitiveClass {
    private char[] filename;
    private Boolean shared = false;

    SensitiveClass(String filename) {
        this.filename = filename.toCharArray();
    }

    final void replace() {
        if (!shared) {
            for(int i = 0; i < filename.length; i++) {
                filename[i]= 'x' ;}
        }
    }

    final String get() {
        if (!shared) {
            shared = true;
            return String.valueOf(filename);
        } else {
            throw new IllegalStateException("Failed to get instance");
        }
    }

    final void printFilename() {
        System.out.println(String.valueOf(filename));
    }

    public final SensitiveClass clone()
            throws Exception {
        throw new Exception();
    }
}

class SafeSubclass extends SafeSensitiveClass implements Cloneable {    // @violation
    protected MaliciousSubclass(String filename) {
        super(filename);
    }

    @Override
    public SafeSubclass clone() {  // Well-behaved clone() method
        MaliciousSubclass s = null;
        try {
            s = (MaliciousSubclass) super.clone();  /* Safe : the instance cloning is not operated, because of final clone method */
        } catch (Exception e) {
            System.out.println("not cloneable");
        }
        return s;
    }

}

class SafeSensitiveClass2 {

}

class SafeSubclass2 extends SafeSensitiveClass2 implements Cloneable {   // @violation
    protected MaliciousSubclass(String filename) {
        super(filename);
    }

    @Override public SafeSubclass2 clone() {  // Well-behaved clone() method
        MaliciousSubclass s = null;
        try {
            s = (MaliciousSubclass)super.clone();  /* Safe : the instance cloning is not operated, because of final clone method */
        } catch(Exception e) {
            System.out.println("not cloneable");
        }
        return s;
    }

}