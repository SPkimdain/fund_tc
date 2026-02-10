final class Wrap {
    private char[] dataArray;

    public Wrap() {
        dataArray = new char[10];
        // Initialize
    }

    public CharBuffer getBufferCopy() {
        CharBuffer ch = CharBuffer.wrap(dataArray);
        return ch;                  // @violation
    }

    public CharBuffer getBufferCopy2() {

        return CharBuffer.wrap(dataArray);      // @violation
    }

    public CharBuffer getBufferCopy3() {
        return CharBuffer.wrap(dataArray).asReadOnlyBuffer();           /* Safe */
    }
}


final class Dup {
    CharBuffer cb;

    public Dup() {
        cb = CharBuffer.allocate(10);
        // Initialize
    }

    public CharBuffer getBufferCopy() {
        return cb.duplicate();              // @violation
    }

    public CharBuffer getBufferCopy() {
        return cb.asReadOnlyBuffer();       /* Safe */
    }
}