package basic;

import java.io.File;
import java.lang.Exception;
import java.lang.String;

public class IncorrectPermissionAssignmentForCriticalResource {

    public void run() throws Exception {

        Runtime runtime = Runtime.getRuntime();
        String command1 = "umask 0";
        String[] env = new String[]{};

        String criticalFileName = "C:\\Critical.dat";
        File criticalFile = new File(criticalFileName);

        // Use of "umask 0" directly
        Runtime.getRuntime().exec("umask 0"); // @violation
        Runtime.getRuntime().exec("umask 0", new String[]{}); // @violation
        Runtime.getRuntime().exec("umask 0", new String[]{}, new File("C:\\Critical.dat")); // @violation
        Runtime.getRuntime().exec("umask 0", new String[]{}, new File(criticalFileName)); // @violation
        Runtime.getRuntime().exec("umask 0", env, criticalFile); // @violation

        // Use of new String[]{"umask 0"}
        Runtime.getRuntime().exec(new String[]{"umask 0"}); // @violation
        Runtime.getRuntime().exec(new String[]{"umask 0"}, new String[]{}); // @violation
        Runtime.getRuntime().exec(new String[]{"umask 0"}, new String[]{}, new File("C:\\Critical.dat")); // @violation
        Runtime.getRuntime().exec(new String[]{"umask 0"}, new String[]{}, new File(criticalFileName)); // @violation
        Runtime.getRuntime().exec(new String[]{"umask 0"}, env, criticalFile); // @violation

        // Use of new String[]{"umask", "0"}
        Runtime.getRuntime().exec(new String[]{"umask", "0"}); // @violation
        Runtime.getRuntime().exec(new String[]{"umask", "0"}, new String[]{}); // @violation
        Runtime.getRuntime().exec(new String[]{"umask", "0"}, new String[]{}, new File("C:\\Critical.dat")); // @violation
        Runtime.getRuntime().exec(new String[]{"umask", "0"}, new String[]{}, new File(criticalFileName)); // @violation
        Runtime.getRuntime().exec(new String[]{"umask", "0"}, env, criticalFile); // @violation

        // Use of "umask 0" directly for runtime variable
        runtime.exec("umask 0"); // @violation
        runtime.exec("umask 0", new String[]{}); // @violation
        runtime.exec("umask 0", new String[]{}, new File("C:\\Critical.dat")); // @violation
        runtime.exec("umask 0", new String[]{}, new File(criticalFileName)); // @violation
        runtime.exec("umask 0", env, criticalFile); // @violation

        // Use of new String[]{"umask 0"} for runtime variable
        runtime.exec(new String[]{"umask 0"}); // @violation
        runtime.exec(new String[]{"umask 0"}, new String[]{}); // @violation
        runtime.exec(new String[]{"umask 0"}, new String[]{}, new File("C:\\Critical.dat")); // @violation
        runtime.exec(new String[]{"umask 0"}, new String[]{}, new File(criticalFileName)); // @violation
        runtime.exec(new String[]{"umask 0"}, env, criticalFile); // @violation

        // Use of the command in a variable
        Runtime.getRuntime().exec(command1); // @violation
        Runtime.getRuntime().exec(command1, new String[]{}); // @violation
        Runtime.getRuntime().exec(command1, new String[]{}, new File("C:\\Critical.dat")); // @violation
        Runtime.getRuntime().exec(command1, new String[]{}, new File(criticalFileName)); // @violation
        Runtime.getRuntime().exec(command1, env, criticalFile); // @violation

        // Use of the command in a variable - the second case
        String[] command2 = new String[]{"umask 0"};
        Runtime.getRuntime().exec(command2); // @violation
        Runtime.getRuntime().exec(command2, new String[]{}); // @violation
        Runtime.getRuntime().exec(command2, new String[]{}, new File("C:\\Critical.dat")); // @violation
        Runtime.getRuntime().exec(command2, new String[]{}, new File(criticalFileName)); // @violation
        Runtime.getRuntime().exec(command2, env, criticalFile); // @violation

        // Use of the command in a variable - the third case
        String[] command3 = new String[]{"umask", "0"};
        Runtime.getRuntime().exec(command3); // @violation
        Runtime.getRuntime().exec(command3, new String[]{}); // @violation
        Runtime.getRuntime().exec(command3, new String[]{}, new File("C:\\Critical.dat")); // @violation
        Runtime.getRuntime().exec(command3, new String[]{}, new File(criticalFileName)); // @violation
        Runtime.getRuntime().exec(command3, env, criticalFile); // @violation

        // Safe cases and use of the commands in a variable
        command1 = "umask 77";
        Runtime.getRuntime().exec(command1);
        Runtime.getRuntime().exec(command1, new String[]{});
        Runtime.getRuntime().exec(command1, new String[]{}, new File("C:\\Critical.dat"));
        Runtime.getRuntime().exec(command1, new String[]{}, new File(criticalFileName));
        Runtime.getRuntime().exec(command1, env, criticalFile);

        command2 = new String[]{"umask 77"};

        Runtime.getRuntime().exec(command2);
        Runtime.getRuntime().exec(command2, new String[]{});
        Runtime.getRuntime().exec(command2, new String[]{}, new File("C:\\Critical.dat"));
        Runtime.getRuntime().exec(command2, new String[]{}, new File(criticalFileName));
        Runtime.getRuntime().exec(command2, env, criticalFile);

        command3 = new String[]{"umask", "77"};

        Runtime.getRuntime().exec(command3);
        Runtime.getRuntime().exec(command3, new String[]{});
        Runtime.getRuntime().exec(command3, new String[]{}, new File("C:\\Critical.dat"));
        Runtime.getRuntime().exec(command3, new String[]{}, new File(criticalFileName));
        Runtime.getRuntime().exec(command3, env, criticalFile);
    }

    public void safeRun() throws Exception {
        String criticalFileName = "C:\\Critical.dat";
        Runtime.getRuntime().exec("umask 0"); /* SAFE */
        Runtime.getRuntime().exec("umask 0", new String[]{}); /* SAFE */
        Runtime.getRuntime().exec("umask 0", new String[]{}, new File("C:\\Critical.dat")); // @violation
        Runtime.getRuntime().exec("umask 0", new String[]{}, new File(criticalFileName)); // @violation
    }

    public void bad() throws Throwable {
        File file = new File("c:\\report.txt");
        /* FLAW */
        file.setExecutable(true);
        file.setReadable(true);
        file.setWritable(true); // @violation
    }
}
