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
