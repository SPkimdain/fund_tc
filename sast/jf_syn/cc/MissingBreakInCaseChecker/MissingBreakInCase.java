package cc;

public class MissingBreakInCase {

    public void func1(int a, int b) {
        switch(a) {
            case 1:
                b = b+1;
                break;
            case /* @violation */ 2:
                b = b+1;
            case 3:
                b = b+1;
                // Fall through
            case /* @violation */ 4:
            case 5:
                break;
            case 6:
            {
                b = b+1;
                break;
            }
            case /* @violation */ 7:
            {
                b = b+1;
            }
            case 8:
            {
                b = b+1;
                // Fall through
            }
            /* @violation */ default :
        }

        switch(b) {
            case 1:
                a = a+1;
                break;
            default:
                // End of case
        }
    }

    public void func2(int a, int b) {
        switch(a) {
            case 1:
                b = b+1;
                if(b > a) {
                    break;
                } else {
                    break;
                }
            case /* @violation */ 2:
                b = b+1;
                if(b > a) {
                    break;
                }
            case /* @violation */ 3:
                b = b+1;
                if(b > a) {
                    break;
                } else if(b < a) {
                    break;
                }
            case /* @violation */ 4:
                while(b < a) {
                    return;
                }
            case /* @violation */ 5:
                switch(b) {
                    case 1:
                        return;
                    case 2:
                        return;
                    default:
                        break;
                }
        }
    }

    public void false1() {
        // False alarm case from NH : 20140620
        int hashCode = fieldName.hashCode();
        switch(hashCode) {
            case 514137987: return new AbstractDataObjectList(this.lACO1010R0_Session_OUT);

            default: throw new ProframeException("unknown fieldName : " + fieldName);
        }
    }
}
