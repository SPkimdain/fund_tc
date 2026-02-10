
var productid = document.URL.indexOf(eid+4);

var name = $("#name").val();
var rollNo = $("#rollno").val();
var transaction = db.transaction([productid],"readwrite"); //@violation
transaction.oncomplete = function(event) {
    console.log("Success :)");
    $("#result").html("Add : Success");
};
transaction.onerror = function(event) {
    console.log("Error :(");
    $("#result").html("Add : Error");
};
var objectStore = transaction.objectStore("students");

objectStore.add({rollNo: rollNo, name: name});