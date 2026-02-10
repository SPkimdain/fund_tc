package src.test.java.pmd;

public class EmptyFinallyBlock {
    void test1() {
        try {
            int bugID = 1;
        } finally { // @violation
            ;
        }
    }

    void test2() {
        try {
            int notBugID = 2;
        } finally {
            notBugID = 3;
        }
    }

    void test3() {
        try (File file = new File()) {
            int bugID = 1;
        } finally { // @violation
            ;
        }
    }

    void test4() {
        try (File file = new File()) {
            int notBugID = 2;
        } finally {
            notBugID = 3;
        }
    }
}