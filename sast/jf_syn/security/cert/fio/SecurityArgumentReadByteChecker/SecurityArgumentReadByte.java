public class SecurityArgumentReadByte {
    public static String readBytesBad2(InputStream in) throws IOException {
        byte[] data = new byte[1024];
        int offset = 0;
        if (in.read(data, offset, data.length - offset) != -1) {              // @violation
            throw new EOFException();
        }
        return new String(data, "UTF-8");
    }

    public static String readBytesBad(InputStream in) throws IOException {
        byte[] data = new byte[1024];
        if (in.read(data) == -1) {              // @violation
            throw new EOFException();
        }
        return new String(data, "UTF-8");
    }

    public static String readBytesGood(InputStream in) throws IOException {
        int offset = 0;
        int bytesRead = 0;
        byte[] data = new byte[1024];
        while ((bytesRead = in.read(data, offset, data.length - offset))        /* Safe */
                != -1) {
            offset += bytesRead;
            if (offset >= data.length) {
                break;
            }
        }
        String str = new String(data, "UTF-8");
        return str;
    }


}