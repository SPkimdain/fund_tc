package cc;

public class BadOperatorTooManyLogicalOperations {
   

    public void func() {

        if((condition1 && condition2)                                      /* Safe */
          || (condition3 && condition4)
          || !(condition5 && condition6)
        ) {
            doSomethingAboutIt();
        }

        if( (condition1 && condition2) || (condition3 && condition4) || !(condition5 && condition6)) {     // @violation
            doSomethingAboutIt();
        }
    }
}
