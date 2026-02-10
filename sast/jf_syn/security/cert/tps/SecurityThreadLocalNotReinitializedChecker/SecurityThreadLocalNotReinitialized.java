public class SecurityThreadLocalNotReinitialized {
    enum Day {
        MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY;
    }

    final class Diary {
        private static final ThreadLocal<Day> days =
                new ThreadLocal<Day>() {
                    // Initialize to Monday
                    protected Day initialValue() {
                        return Day.MONDAY;
                    }
                };

        private static Day currentDay() {
            return days.get();
        }

        public static void setDay(Day newDay) {
            days.set(newDay);
        }

        // Performs some thread-specific task
        public void threadSpecificTask() {
            // Do task ...
        }
    }

    final class DiaryPool {
        final int numOfThreads = 2; // Maximum number of threads allowed in pool
        final Executor exec;
        final Diary diary;

        DiaryPool() {
            exec = (Executor) Executors.newFixedThreadPool(numOfThreads);
            diary = new Diary();
        }

        public void doSomething1() {
            exec.execute(new Runnable() { // @violation
                @Override public void run() {
                    diary.setDay(Day.FRIDAY);
                    diary.threadSpecificTask();
                }
            });
        }

        public void foo() {
            DiaryPool dp = new DiaryPool();
            dp.doSomething1();
        }
    }

    final class DiaryPool2 {
        final int numOfThreads = 2; // Maximum number of threads allowed in pool
        final Executor exec;
        final Diary2 diary2;

        DiaryPool2() {
            exec = (Executor) Executors.newFixedThreadPool(numOfThreads);
            diary2 = new Diary2();
        }

        public void doSomething2() {
            exec.execute(new Runnable() { // @violation
                @Override public void run() {
                    diary2.threadSpecificTask();
                }
            });
        }

        public void foo2() {
            DiaryPool2 dp = new DiaryPool2();
            dp.doSomething2();
        }
    }

    final class DiaryPool3 {
        final int numOfThreads = 2; // Maximum number of threads allowed in pool
        final Executor exec;
        final Diary3 diary3;

        DiaryPool3() {
            exec = (Executor) Executors.newFixedThreadPool(numOfThreads);
            diary3 = new Diary3();
        }

        public void doSomething3() {
            exec.execute(new Runnable() { // @violation
                @Override public void run() {
                    try {
                        Diary3.setDay(Day.FRIDAY);
                        diary3.threadSpecificTask();
                    } finally {
                        // Do nothing
                    }
                }
            });
        }

        public void foo3() {
            DiaryPool3 dp = new DiaryPool3();
            dp.doSomething3();
        }
    }

}
