<template>
    <div>
        <h1>ForbiddenEditNativeObjectPrototype</h1>
    </div>
</template>

<script>
Array.prototype.count = function (value) { return 4; }; //@violation

Number.prototype.count = function (value) { return 4; }; //@violation
</script>

<style>
  #computer {
    width: 142px;
    height: 200px;
    background-position: 0 0;
  }
</style>
