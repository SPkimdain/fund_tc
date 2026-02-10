package basic;

import java.lang.String;
import java.util.List;

public class UnnotifiedObject {

    private List list;
    private List unnotifiedList;

    public void removeItem() throws InterruptedException {
        synchronized(list) {
            while (list.isEmpty()) {
                list.wait();
            }
            String item = (String)list.remove(0);
        }

        synchronized(unnotifiedList) {
            while(unnotifiedList.isEmpty()) {
                unnotifiedList.wait(); // @violation
            }
            String item = (String)unnotifiedList.remove(0);
        }
    }

    public void addItem(String item, List list1, List list2, List list3) {
        list3 = list;
        list1 = list3;
        list2 = list1; // list2 <- list1 <- list3 <- list

        synchronized(list2) {
            list2.add(item);
            list2.notifyAll(); // Means list2 <- list ==>> list.notifyAll()
        }
        synchronized(unnotifiedList) {
            unnotifiedList.add(item);
        }
    }
}
