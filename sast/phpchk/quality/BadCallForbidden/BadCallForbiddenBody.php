<?
class Clazz {

    static function forbiddenStatic($var) {
        return $var - 2;
    }

    function forbiddenInClass($var) {
        return $var - 1;
    }
}

function forbidden($var) {
    // Do something ...
    return $var;
}

$var2 = forbidden(0); // @violation
$obj = new Clazz();
$var3 = $obj->forbiddenInClass(0); // @violation
$var4 = Clazz::forbiddenStatic(1); // @violation

namespace NM {
    function forbiddenInNamespace($var) {
       // Do something ...
       return $var + 1;
   }

   $varNm = forbiddenInNamespace(1); // @violation
}
?>
