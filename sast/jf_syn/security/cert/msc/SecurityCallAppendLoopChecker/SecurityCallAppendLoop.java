public class SecurityCallAppendLoop {
    private Vector<String> names = new Vector<String>();
    private final InputStreamReader input;
    private final BufferedReader reader;

    public ReadNames(String filename) throws IOException {
        this.input = new FileReader(filename);
        this.reader = new BufferedReader(input);
    }

    public void addNames() throws IOException {
        try {
            String newName;
            while (((newName = reader.readLine()) != null) &&        // @violation
                    !(newName.equalsIgnoreCase("quit"))) {
                names.addElement(newName);                          // @violation
                System.out.println("adding " + newName);
            }
        } finally {
            input.close();
        }
    }

    public static void main(String[] args) throws IOException {
        if (args.length != 1) {
            System.out.println("Arguments: [filename]");
            return;
        }
        ReadNames demo = new ReadNames(args[0]);
        demo.addNames();
    }
}