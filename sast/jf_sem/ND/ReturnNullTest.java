package nd;

class ReturnNullTest {
    int globalvar = 0;
    public String getPath() {
        if(globalvar == 1) {
            return "zxcv";
        }
        return null;
    }
    public boolean isFromArchive() {
        String path = getPath();
        if(path == null) {
            return false;
        }
        String up = path.toUpperCase();
        return false;
    }
}