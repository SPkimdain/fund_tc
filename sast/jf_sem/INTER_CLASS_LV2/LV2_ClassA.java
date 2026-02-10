package inter_class_lv2;

/* inter class level 2 test */
public class LV2_ClassA extends LV2_CLASS {
    public int getOne() {
        return 1;
    }
    public void dummy1() {}
    public int getSomeInt() {
        if (getOne() == 1) {
            return 1;
        } else return 0;
    }
    public String getNullString() {return null;}
    public void dummy2() {}
}
