function violation() {
    process.on("uncaughtException", (err) => { //@violation
       // log necessary error details to log files
       //process.exit();
    });
}

function good() {
    process.on("uncaughtException", (err) => {
       // log necessary error details to log files
       process.exit();
       sadfas.temp();
    });
}

let process2 = process;
process2.on("uncaughtException", function(err) { //@violation
   // log necessary error details to log files
   //process.exit();
});

process2.on("uncaughtException", function(err) {
   // log necessary error details to log files
   process.exit();
});

let process3 = process;
process3.on("other something", function(err) {
  console.error("other something\n", err);
  userMethod.exit();
});

process3.on("other something", function(err) {
  console.error("other something\n", err);
  process.exit();
});

process.on("other something", function(err) {
  console.error("other something\n", err);
  process3.exit();
});

let process4 = process;
process4.on("uncaughtException", function(err) {
    console.error("uncaughtException\n", err);
    userMethod.exit();
    process4.exit(); // process.on 내부에 있어야함.
});

process4.on("uncaughtException", function(err) { //@violation
    console.error("uncaughtException\n", err);
    userMethod.exit()
});