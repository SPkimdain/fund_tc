package cc;

public class Capital {
    protected class innerSmall {        // @violation
        private class InnerCapital {

        }
    }

}

private class smallLetter {             // @violation

}

public interface Person {

}

