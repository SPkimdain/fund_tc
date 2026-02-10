package test.com.fasoo.javafinch.syn.rule.basic.privatecollection;

import java.util.Collection;

/**
 * PRIVATE_COLLECTION Test case 6 : Array type test
 * Private 배열 검출 여부 검사
 * @author jwyoon
 *
 */
public class PrivateCollection6 {
    class PrivateCollection {
        private String[] privateArray;
        public String[] publicArray;
        private static final String[] FORMAT_NAMES = {
                "JPEG", "GIF", "PNG", "BMP", "PCX", "IFF", "RAS", "PBM", "PGM", "PPM", "PSD", "SWF"
        };

        private String[] getFormatNames() {
            return FORMAT_NAMES;
        }

        public String getFormatName(int format) {
            if (format >= 0 && format < FORMAT_NAMES.length) {
                return FORMAT_NAMES[format]; // Not bug
            } else {
                return "?";
            }
        }

        public String getFormatName2(int format) {
            if (format >= 0 && format < FORMAT_NAMES.length) {
                return getFormatNames()[format]; // Not bug
            } else {
                return "?";
            }
        }

        private String[] getArrayPrivate() {
            return this.privateArray;
        }

        public String[] getArray(int x) {
            if(x > 10)
                return this.privateArray; // @violation
            else
                return this.publicArray; // Not bug
        }

        public String[] getArray2(int x) {
            return getArrayPrivate(); // @violation
        }

        public boolean isSame() {
            return this.privateArray == this.publicArray; // Not bug
        }
    }
}
