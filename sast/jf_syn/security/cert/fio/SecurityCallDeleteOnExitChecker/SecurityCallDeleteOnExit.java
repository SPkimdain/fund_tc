class SecurityCallDeleteOnExit {
    public static void main(String[] args) throws IOException {
        File f = File.createTempFile("tempnam",".tmp");
        FileOutputStream fop = null;
        try {
            fop = new FileOutputStream(f);
            String str = "Data";
            fop.write(str.getBytes());
            fop.flush();
        } finally {
            // Stream/file still open; file will
            // not be deleted on Windows systems
            f.deleteOnExit();                   // @violation

            if (fop != null) {
                try {
                    fop.close();
                } catch (IOException x) {
                    // handle error
                }
            }
        }
    }
}