public class SecurityCallBigEndian {
    public void getInputStream() {
        try {
            DataInputStream dis = null;
            try {
                dis = new DataInputStream(new FileInputStream("data"));
                // Little-endian data might be read as big-endian
                int serialNumber = dis.readInt();           // @violation
            } catch (IOException x) {
                // handle error
            } finally {
                if (dis != null) {
                    try {
                        dis.close();
                    } catch (IOException e) {
                        // handle error
                    }
                }
            }
        }

        try {
            DataInputStream dis = null;
            try {
                dis = new DataInputStream( new FileInputStream("data"));
                byte[] buffer = new byte[4];
                int bytesRead = dis.read(buffer);                       /* Safe */
                if (bytesRead != 4) {
                    throw new IOException("Unexpected End of Stream");
                }
                int serialNumber =
                        ByteBuffer.wrap(buffer).order(ByteOrder.LITTLE_ENDIAN).getInt();
            } finally {
                if (dis != null) {
                    try {
                        dis.close();
                    } catch (IOException x) {
                        // handle error
                    }
                }
            }
        } catch (IOException x) {
            // handle error
        }
    }
}