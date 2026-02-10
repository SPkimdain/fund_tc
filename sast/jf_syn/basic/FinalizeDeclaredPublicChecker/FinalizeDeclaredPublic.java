package basic;

public class cwe583_d {

    private boolean cleaned = false;

    public void finalize() { //@violation
        System.out.println("Cleaning up resources");
        cleaned = true;
    }

    public static void main(String[] args) {
        cwe583_d resource = new cwe583_d();
        resource.finalize();
        if (resource.cleaned) {
            System.out.println("Resource was cleaned up");
        } else {
            System.out.println("Resource cleanup failed");
        }
    }
}