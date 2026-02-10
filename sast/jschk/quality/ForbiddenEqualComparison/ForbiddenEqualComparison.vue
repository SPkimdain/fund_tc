<template>
    <div>
        <h1>ForbiddenEqualComparison</h1>
    </div>
</template>

<script>
if ( a == 1 ) { } // @violation

for( x = 1; x !=2 ; x ++) {} // @violation

if (a === 'c') {} // @no violation
</script>

<style>
  #computer {
    width: 142px;
    height: 200px;
    background-position: 0 0;
  }
</style>
