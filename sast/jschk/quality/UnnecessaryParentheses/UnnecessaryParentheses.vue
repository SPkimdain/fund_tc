<template>
    <div>
        <h1>UnnecessaryParentheses</h1>
    </div>
</template>

<script>
var x = 1; // Ok
var y = (1 + 1); // Ok
var z = ((1 + 1) + 2); //no @violation
var xy = (((2))) + (1+1); // @violation
var z = ((1 + 1)); // @violation
</script>

<style>
  #computer {
    width: 142px;
    height: 200px;
    background-position: 0 0;
  }
</style>
