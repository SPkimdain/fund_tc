process.on("uncaughtException", (err) => { //@violation
console.error("uncaughtException\n", err);
userMethod.exit();
//process.exit();
});

// throw에러는 프로세스를 멈추게 한다
// 즉, 미처 try/catch로 처리하지 못한 에러
setInterval(() => {
throw new Error("error occurred");
}, 1000);

// uncaughtException 이벤트가 없다면 setTimeout은 실행되지 않는다
setTimeout(() => {
console.log("setTimeout run");
}, 2000);