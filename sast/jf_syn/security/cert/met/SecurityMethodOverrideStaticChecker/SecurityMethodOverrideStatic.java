class GrantAccess {
    public static void displayAccountStatus() {                 // @violation
        System.out.println("Account details for admin: XX");
    }
}

class GrantUserAccess extends GrantAccess {
    public static void displayAccountStatus() {                 // @violation
        System.out.println("Account details for user: XX");
    }
}

public class StatMethod {
    public static void choose(String username) {
        GrantAccess admin = new GrantAccess();
        GrantAccess user = new GrantUserAccess();
        if (username.equals("admin")) {
            admin.displayAccountStatus();               /* Call static method */
        } else {
            user.displayAccountStatus();                /* Call static method */
        }
    }

    public static void main(String[] args) {
        choose("user");
    }
}

class GrantAccess2 {
    public static void displayAccountStatus() {                 /* Safe */
        System.out.println("Account details for admin: XX");
    }
}

class GrantUserAccess2 extends GrantAccess2 {
    public static void displayAccountStatus() {                 /* Safe */
        System.out.println("Account details for user: XX");
    }
}

public class StatMethod2 {
    public static void choose(String username) {
        GrantAccess2 admin = new GrantAccess2();
        GrantAccess2 user = new GrantUserAccess2();
        if (username.equals("admin")) {
            GrantAccess2.displayAccountStatus();                 /* Call static method but safe */
        } else {
            GrantUserAccess2.displayAccountStatus();             /* Call static method but safe */
        }
    }

    public static void main(String[] args) {
        choose("user");
    }
}

class GrantAccess3 {
    public void displayAccountStatus() {                 /* Safe */
        System.out.println("Account details for admin: XX");
    }
}

class GrantUserAccess3 extends GrantAccess {
    public void displayAccountStatus() {                 /* Safe */
        System.out.println("Account details for user: XX");
    }
}

public class StatMethod3 {
    public static void choose(String username) {
        GrantAccess3 admin = new GrantAccess3();
        GrantAccess3 user = new GrantUserAccess3();
        if (username.equals("admin")) {
            admin.displayAccountStatus();               /* Call method */
        } else {
            user.displayAccountStatus();                /* Call method */
        }
    }

    public static void main(String[] args) {
        choose("user");
    }
}