package cc;

public class UseTabBetweenTypeAndIdentifier {

    private float bField; // @violation
	private float	fField;
    public int		tField;

    public void func() {
        float bLocal; // @violation
		float	fLocal;
        int		tLocal;
    }
}
