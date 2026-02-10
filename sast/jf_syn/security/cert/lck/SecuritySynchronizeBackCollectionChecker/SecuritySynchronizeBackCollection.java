import java.util.Set;

public class SecuritySynchronizeBackCollection {
    private final Map<Integer, String> mapView =
            Collections.synchronizedMap(new HashMap<Integer, String>());
    private final Set<Integer> setView = new Set<Integer>();

    public MisuseSynchronizeBackCollection() {
        setView = mapView.keySet();
    }

    public Map<Integer, String> getMap() {
        return mapView;
    }

    public void doSomething() {
        synchronized (setView) {                                    // @violation
            for (Integer k : setView) {
                // ...
            }
        }

        synchronized (mapView) {                                    /* Safe */
            for (Integer k : setView) {
                // ...
            }
        }
    }
}