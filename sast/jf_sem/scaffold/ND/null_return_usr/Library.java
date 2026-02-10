package scaffold.nd.null_return_usr;

import java.util.Random;

public class Library {
	// This method can return either null or string.
	public String getString() {
		int i = new Random().nextInt(100);
		if (i > 0) {
			return "More than zero";
		} else {
			return null;
		}
	}
}
