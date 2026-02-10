public class ForbiddenRaceConditionMethod {
    public class RaceConditionMethodBad1  {
        void func() {
            ThreadGroup tg = new ThreadGroup("wow");
            ThreadGroup[] ta = new ThreadGroup[4];
            Thread[] t = new Thread[3];

            int i = 0;
            boolean b = true;
            String s;

            i = tg.activeCount();       // @violation
            tg.checkAccess();           // @violation
            i = tg.enumerate(t, b);     // @violation
            tg.destroy();               // @violation
        }
    }
}