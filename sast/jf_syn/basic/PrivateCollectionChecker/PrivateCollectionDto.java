class PrivateCollectionDto {
    private String[] privateArray;
    public String[] publicArray;

    private String[] getArrayPrivate() {
        return this.privateArray;
    }

    public String[] getArray(int x) {
        if(x > 10)
            return this.privateArray; // violation but Dto is exceptional class
        else
            return this.publicArray; // Not bug
    }

    public String[] getArray2(int x) {
        return getArrayPrivate(); // violation but Dto is exceptional class
    }

    public boolean isSame() {
        return this.privateArray == this.publicArray; // Not bug
    }
}