<template>
    <div>
        <h1>ForbiddenBitwiseOperation</h1>
    </div>
</template>

<script>
  a^b // @violation
  ~a // @violation
  c &=a; // @violation
  d |=c; // @violation
</script>

<style>
  #computer {
    width: 142px;
    height: 200px;
    background-position: 0 0;
  }
</style>
