package cc;

public class BadOrganizationClass {

    public class Inner1 {
        private int a;
        private void func() {} // @violation
        public Inner(int x) {}
    }

    public class Inner2 {
        public Inner() {}
        private void func() {}
        private int a; // @violation
        static {
            // Do something ...
        }
    }

    public class Inner3 {
        private void func() {}
        private void func(int x) {}
        private void func(int x, int y, int z) {}
        private void func(int x, int y) {}
    }

    public class Inner4 {
        public Inner4(int x, int y, int z) {}
        public Inner4(int x) {} // @violation
        public Inner4(int x, int y) {}
        public Inner4() {}
    }

    public class Inner5 {
        public class GrandInner {} // @violation
        private int a;
        public class GrandInner2 {}
        public Inner5() {}
        public void func() {}
    }

    public class Inner6 {
        public class GrandInner {} // @violation
        private int a;
        public class GrandInner2 {}
        private void func() {} // @violation
        public Inner6() {}
        private void func(int x) {}
        private void func(int x, int y, int z) {}
        private void func(int x, int y) {}
    }
}
