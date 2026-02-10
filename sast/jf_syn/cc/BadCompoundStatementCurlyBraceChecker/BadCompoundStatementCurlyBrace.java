// COMPOUND_STATEMENT.CURLY_BRACE
package cc;

public class BadCompoundStatementCurlyBrace
{ // @violation
    public void func()
    {                                       // @violation
        int i,j;

        for(i=0; i<10; i++)
        {                   // @violation
            // Do something ...
        }
    }

    public void func2() {
        // Do something ...
    }

    public void func3() {
        // Do something ...
       } // @violation
    public void func4() {
        while (true)
        { // @violation
            // Do something ...
        }
        switch (a)
        { // @violation
        case 1:
            a= 2;
            break;
        default:
            break;
        }
    }

    public void func5() {

        /* safe */
        try {

        } catch (Exception e) {

        } finally {

        }


        try{    // @violation

        }catch (Exception e) {  // @violation

        }finally {  // @violation

        }


        try {

        } catch (Exception e){  // @violation

        } finally{  // @violation

        }


        try (File file = new File()){   // @violation

        } catch (Exception e) {

        } finally{  // @violation

        }


        /* safe */
        int i = 0;
        if (i==0) {

        } else if (i==1) {

        } else {

        }


        if (i==0){  // @violation

        } else if (i==1){   // @violation

        } else{ // @violation

        }


        if (i==0) {

        }else if (i==1) {   // @violation

        }else { // @violation

        }

        /* safe */
        do {

        } while(1);


        do{ // @violation

        } while(1);


        do {

        }while(1);  // @violation

    }
}