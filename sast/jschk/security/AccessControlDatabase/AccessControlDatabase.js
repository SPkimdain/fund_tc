var id = document.forms.invoiceID.value;
var query = "SELECT * FROM invoices WHERE id = ?";
db.transaction(function (tx) {
    tx.executeSql(query, [id, "11"] ); //@violation
    }
)