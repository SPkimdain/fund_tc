<template>
    <div>
        <h1>EmptyCatchBlock</h1>
    </div>
</template>

<script>
try {
	var a = 1;
} catch(e) { //@violation
	//Dom
}

try {
	var c = 2;
} catch(e) { //@Safe
	var d = 1;
	c();
}
</script>

<style>
  #computer {
    width: 142px;
    height: 200px;
    background-position: 0 0;
  }
</style>
