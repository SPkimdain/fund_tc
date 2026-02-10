//DO_NOT_ASSIGN_EXTERNAL_DATA_TO_MEMBER_VARIABLES
package security;

public class DoNotAssignExternalDataToMemberVariables_Bad {
    private Object myState = null;

    public void setState(Object state) {
        myState = state;    // @violation
    }
}

public class DoNotAssignExternalDataToMemberVariables_Good {
    private Object myState = null;
    private int value = 0;

    public void setState(Object state) {
        if(state == null) {
            //do something
        }
        myState = state;    /* SAFE */
    }

    public void setValue(int val) {
        value = val; /* SAFE */
    }
}
