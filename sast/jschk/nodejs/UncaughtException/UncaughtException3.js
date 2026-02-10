process.on('uncaughtException', (err, origin) => {  //@violation
  fs.writeSync(
    process.stderr.fd,
    'Caught exception: ${err}\n' +
    'Exception origin: ${origin}'
  );
  //process.exit();
});

setTimeout(() => {
  console.log('This will still run.');
}, 500);

// Intentionally cause an exception, but don't catch it.
nonexistentFunc();
console.log('This will not run.');