package security;

public class test {
    public int test1(){
        Long sum = 0L;
        List<Long> num = new ArrayList<>();
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < 1000; i++) {
            num.add(i); //@violation
            sum += i;
            map.put("key" + i, i); //@violation
        }
        return 1;
    }

    public int test2(){
        Long sum = 0L;
        for (int i = 0; i < 1000; sum++) { //@violation
            System.out.println("test");
        }
        return 1;
    }

    public int test(){
        Long sum = 0L;
        List<Long> num = new ArrayList<>();

        while(true){
            sum += 1;
            num.add(sum); //@violation
        }

        return 1;
    }
}