process.stdin.on('readable', function(){
    var s = process.stdin.read();
    if (s != null){
      process.stdout.write(s); //@violation
    }

    process.stdout.stderr("error"); //@violation
});