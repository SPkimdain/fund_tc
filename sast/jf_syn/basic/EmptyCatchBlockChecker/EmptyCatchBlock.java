package basic;

import java.io.FileReader;
import java.lang.Exception;
import java.lang.String;

/**
 * @author jwyoon
 * @since 20120925
 */
public class EmptyCatchBlock {
	
    public void func1(String filePath) {
		try {
			// Read with the file name of the given option
			FileReader fr = new FileReader(filePath);
			fr.close();
		} catch(Exception e) { // @violation
		}
	}
	
	public void func2(String filePath) {
		try {
			// Read with the file name of the given option
			FileReader fr = new FileReader(filePath);
			fr.close();
		} catch(Exception e) { // @violation
			;
		}
	}
	
	public void func3(String filePath) {
		try {
			// Read with the file name of the given option
			FileReader fr = new FileReader(filePath);
			fr.close();
		} catch(Exception e) { // @violation
			{
				;
			}
		}
	}

    public void func4(String filePath) {
		try {
			// Read with the file name of the given option
			FileReader fr = new FileReader(filePath);
			fr.close();
		} catch(Exception e) {
			e.printStacktrace();
		}
	}
	
	public void func5(String filePath) {
		try {
			// Read with the file name of the given option
			FileReader fr = new FileReader(filePath);
			fr.close();
		} catch(Exception e) {
			{
				;
			}
			e.printStacktrace();
		}
	}

    public void fun6(String filePath) {
        try {
            // Read with the file name of the given option
            FileReader fr = new FileReader(filePath);
            fr.close();
        } catch(Exception e) { // @violation
            ;;
        }
    }

    public void fun7(String filePath) {
        FileReader fr = null;
        try {
            fr = new FileReader(filePath);
        } catch(Exception e) {
            e.printStackTrace();
        } finally {
            try {
                if(fr != null) {
                    String encoding = fr.getEncoding();
                    fr.close();
                }
            } catch(Exception e) { // @violation

            }
        }
    }

    public void exception(String filePath) {
        FileReader fr = null;
        try {
            fr = new FileReader(filePath);
        } catch(Exception e) {
            e.printStackTrace();
        } finally {
            try {
                if(fr != null) {
                    fr.close();
                }
            } catch(Exception e) { /* SAFE */

            }
        }
    }

    public void exception2(String filePath) {
        FileReader fr = null;
        try {
            fr = new FileReader(filePath);
        } catch(Exception e) {
            e.printStackTrace();
        } finally {
            if(fr != null) {
                try {
                    fr.close();
                } catch(Exception e) { /* SAFE */

                }
            }
        }
    }

    public void exception3(String filePath) {
        FileReader fr = null;
        FileReader fr2 = null;
        try {
            fr = new FileReader(filePath);
            fr2 = new FileReader(filePath);
        } catch(Exception e) {
            e.printStackTrace();
        } finally {
            try {
                if(fr != null) {
                    fr.close();
                }
                if(fr2 != null) {
                    fr2.close();
                }
            } catch(Exception e) { /* SAFE */

            }
        }
    }

    public void exception4(String filePath) {
        try (StringBufferInputStream sbis = new StringBufferInputStream("abc")) {

        } catch(Exception e) { // @violation
            // Do something ...
        }
    }
}
