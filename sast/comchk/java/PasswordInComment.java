public class test {
    /* password : a!2@3b4a */
    /* password : a!2@3b4 */
    /* password : a12b3cd5 */
    /* password : 1 */
    /* Key : 94jgk398DSod305jdDGFIO39DJ934mjnKDNGIE34 : Bug key length is 40 */
    /* Key : 94jgk398DSod305jdDGFIO39DJ934mjnKDNGIE34dDJ : Safe key length is over 40 */
    /* Key : 94jgk398DSod305jdDGFIO39DJ934mjnKDNG : Safe key length is under 40 */

    /**
     * Method
     * @return 94jgk398DSod305jdDGFIO39DJ934mjnKDNGIE34dDJ
     */
    public test() {
        // This is a password : a!2@3b4a
        // This is not a password : aa !2@3 b4a
        /* password : a1#cd5 */
        /* password : a1d5 */
        /* password : a#5 */
    }
}
