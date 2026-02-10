<template>
    <div>
        <h1>UseBracesTest</h1>
    </div>
</template>

<script>
/**  if Stmt */

// Ok
if (foo) {
   x++;
}

// Bad
if (foo)
   x++;  Sleep(); y++; // @violation


// Ok
if (foo) {
   x++;
} else {
   y++;
}

// Bad Else
if (foo) {
   x++;
} else
   y++;  // @violation

/** for */

// Good
for (var i = 0; i < 42; i++) {
   foo();
}
// Bad
for (var i = 0; i < 42; i++)
   foo();  // @violation


// Ok
while (true) {
   x++;
}

// Bad
while (true)
   x++;  // @violation

</script>

<style>
  #computer {
    width: 142px;
    height: 200px;
    background-position: 0 0;
  }
</style>
