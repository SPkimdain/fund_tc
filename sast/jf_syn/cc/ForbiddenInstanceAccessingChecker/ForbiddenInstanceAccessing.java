package cc;

public class ForbiddenInstanceAccessing {

    public class Inner {

        private Storage storage = new Storage();
        private static Storage staticStorage = new Storage();

        private int field;
        private static int staticField;

        public void func() {
            // Do something ...
        }

        public static void staticFunc() {
            // Do something ...
        }

        public Storage getStorage() {
            return this.storage;
        }
    }

    public class Storage {
        private int field;
        private static int staticField;
    }

    private Inner inner = new Inner();

    public void func() {
        inner.field = 0;
        inner.staticField = 0; // @violation

        inner.func();
        inner.staticFunc(); // @violation

        inner.storage.field = 0;
        inner.storage.staticField = 0; // @violation

        inner.getStorage().field = 0;
        inner.getStorage().staticField = 0; // @violation

        inner.staticStorage.field = 0; // @violation

        Inner.staticField = 0;
        Inner.staticFunc();
        Storage.staticFunc = 1;
    }
}
