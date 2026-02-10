package cc;

public class DirectUseOfIntegerLiteral {
    public void a(String sMessage) {
        String strClassName;
        Class cls;

        String strIfId = sMessage.substring(0, 8); // 8 // @violation

        strClassName = strIfId.substring(0, 1)
                + strIfId.substring(1, 2).toLowerCase() // 2 // @violation
                + strIfId.substring(2, 3) // 2 3 // @violation 2
                + strIfId.substring(3, 4).toLowerCase() // 3 4 // @violation 2
                + strIfId.substring(4, 5) // 4 5 // @violation 2
                + strIfId.substring(5, 6).toLowerCase() // 5 6 // @violation 2
                + strIfId.substring(6, Integer.parseInt(Integer.valueOf(8).toString())) + "VO"; // 6 8 // @violation 2

        cls = Class.forName("com.klfc.jms.model." + strClassName);
    }

    public void b() {
        int CONST = 10000;

        // test for loop head
        for (int i = 0;i < 10;i++) { // 10 - optional // @violation
            System.out.println(i + 100); // 100 // @violation
        }

        for (int j = 0X0;j < 0x1000_f0f0; j++) { // 0x1000f0f0 - optional // @violation
            System.out.println(j + Integer.parseInt(Integer.valueOf(1000).toString())); // @violation
        }

        for (int k = 0b11;k < 0B1111_0000_1011; k += 1) { // 2 - optional 0b111100001011 - optional // @violation
            System.out.println(k);
        }
    }
}