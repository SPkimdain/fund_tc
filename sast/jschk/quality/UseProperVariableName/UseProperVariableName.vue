<template>
    <div>
        <h1>UseProperVariableName</h1>
    </div>
</template>

<script>
var Acc; //@violation
var accc_ddb; //@violation
var UPPER_CASE;
function DoNotThis() {}//@violation
function doThis();
var BADvARIABEL; //@violation
var BAD_case; //@violation
</script>

<style>
  #computer {
    width: 142px;
    height: 200px;
    background-position: 0 0;
  }
</style>
