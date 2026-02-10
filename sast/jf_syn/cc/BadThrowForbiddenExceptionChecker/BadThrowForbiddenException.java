public class PDPM0100 extends ProcessUnit {
    public void pDPM01001RI() throws Throwable {
        try {
            Integer.parseInt("abc");
        } catch(Exception e) {
            throw e; // @violation, Exception is not allowed to be thrown
        } catch(Throwable e) {
            throw new Throwable(); // @violation, Throwable is not allowed to be thrown
        } catch(FSBException e) {
            FSBException e1 = new FSBException();

            throw e1; // safe
        }
    }
}