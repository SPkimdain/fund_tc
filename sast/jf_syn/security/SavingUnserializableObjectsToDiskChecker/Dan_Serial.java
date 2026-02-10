package security;

public class Dan_Serial implements Serializable {
    private static final long serialVersionUID = 1L;
    private String message;

    private BoardDTO boardDTO;

    public Dan_Serial(String message, BoardDTO boardDTO){
        this.message = message;
        this.boardDTO = boardDTO;
    }

    public Dan_Serial(String message){
        this.message = message;
    }

    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }
}

