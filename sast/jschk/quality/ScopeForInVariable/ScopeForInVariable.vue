<template>
    <div>
        <h1>ScopeForInVariable</h1>
    </div>
</template>

<script>
for(i = 0; i < 10; i++) { //@violation
    var a = 1;
}


for(i in p) { //@violation
    //Do something
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
