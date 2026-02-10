package rl;

/**
 * User: starblood
 * Date: 5/16/13
 * Time: 11:16 AM
 */
public class TemporaryResourceAllocTest {
    private ClassLoader loader = null;
    private boolean checkResource(String resource) {
        if (loader != null) {
            return (loader.getResourceAsStream(resource) != null); /* BUG */ // RESOURCE_LEAK
        } else {
            ClassLoader cL = this.getClass().getClassLoader();
            if (cL != null) {
                return (cL.getResourceAsStream(resource) != null); /* BUG */ // RESOURCE_LEAK
            } else {
                return (ClassLoader.getSystemResourceAsStream(resource) != null); /* BUG */ // RESOURCE_LEAK
            }
        }
    }
}
