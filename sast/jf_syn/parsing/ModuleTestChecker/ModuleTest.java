//MODULE_PARSING
module expenses.readers {    // @violation
    requires java.base; // 모듈명

    exports com.example.expenses.readers;
    exports com.example.expenses.readers.file;
    exports com.example.expenses.readers.http;
    // 패키지명
}