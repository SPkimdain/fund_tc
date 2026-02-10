import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;
import java.lang.String;

/**
 * Writer: Gyuhang Shim
 * Date: 9/17/12
 */
public class MissingAuthenticationForCriticalFunction {
    class BankAccount {
        private double balance;
        private String accountNumber;
        private String person;
        public void setAccountNumber(String accountNumber) {this.accountNumber = accountNumber;}
        public void setToPerson(String person) {this.person = person;}
        public void setBalance(double balance) {this.balance = balance;}
    }
    static class AccountManager {
        public static void send(BankAccount account) {}
        public int sendAccount(BankAccount account) {return 1;}
    }

    public void sendBankAccount(String accountNumber, double balance) {
        BankAccount account = new BankAccount();
        account.setAccountNumber(accountNumber);
        account.setToPerson("toPerson");
        account.setBalance(balance);
        AccountManager.send(account); // @violation
    }

    public void safeSendBankAccount(HttpServletRequest request, HttpSession session, String accountNumber, double balance) {
        String newUserName = request.getParameter("username");
        String newPassword = request.getParameter("password");
        String password = session.getValue("password").toString();
        String userName = session.getValue("username").toString();

        // 재인증을 통해서 이체여부를 판단한다.
        if (newUserName.equals(userName) && newPassword.equals(password)) { // if 문 안에 있으면 안전하다고 판단한다.
            BankAccount account = new BankAccount();
            account.setAccountNumber(accountNumber);
            account.setToPerson("toPerson");
            account.setBalance(balance);
            AccountManager.send(account); /* SAFE */
        }
    }

    public int test(HttpSession session, String newUserName) {
        BankAccount account = new BankAccount();
        String userName = session.getValue("username");

        AccountManager manager = new AccountManager();
        manager.sendAccount(account); // @violation
        // if authenticaion test
        if(newUserName.equals(userName)) {
            manager.sendAccount(account); /* SAFE */
        } else if(1 == 1) {
            manager.sendAccount(account); // @violation
        }
        // switch authenticaion test
        switch(1) {
            case 1 : manager.sendAccount(account); // @violation
            default: break;
        }
        // while authenticaion test
        while(newUserName.equals(userName)) {
            manager.sendAccount(account); /* SAFE */
        }
        // while authenticaion test
        while(1 == 1) {
            manager.sendAccount(account); // @violation
        }

        // for authenticaion test
        for (;newUserName.equals(userName);) {
            manager.sendAccount(account); /* SAFE */
        }
        for (;;) {
            manager.sendAccount(account); // @violation
        }
        // ternary operator authenticaion test
        if(true/*In some cond*/) {
            return 1 == 1 ? manager.sendAccount(account) : 0; // @violation
        } else {
            return newUserName.equals(userName) ? manager.sendAccount(account) : 0; /* SAFE */
        }

        for (;;) {
            /* DO NOTHING: NOT A BUG */
        }
    }

    public void bad(HttpServletRequest request, HttpServletResponse response) throws Throwable
    {
        String newUserName;
        String newPassword;
        String password;
        String userName;
        String toPerson;
        int balance, accountNumber;

        newUserName = request.getParameter("username");
        newPassword = request.getParameter("password");
        toPerson ="person";
        balance = 1;
        accountNumber = 11;

        if(newUserName == null || newPassword == null)
        {
            response.getWriter().println("first data error");
        }

        HttpSession session = request.getSession(true);

        password = session.getAttribute("password").toString();
        userName = session.getAttribute("username").toString();

        if(password == null || userName == null)
        {
            response.getWriter().println("second data error");
        }

        /* POTENTIAL FLAW: Missing_Authentication_for_Critical_Function */
        BankAccount account = new BankAccount();
        account.setAccountNumber(accountNumber);
        account.setToPerson(toPerson);
        account.setBalance(balance);
        account.send(); // @violation
    }
}
