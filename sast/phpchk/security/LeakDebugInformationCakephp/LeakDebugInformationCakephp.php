<?
include 'Configure.php';

Configure::write('debug', 1);
Configure::write('debug', 3); // @violation
Configure::write('arbitrary', 3);

$level = 3;
Configure::write('debug', $level); // @violation
Configure::write('debug', $level + 1); // @violation

function getDebugLevel() {
    return 3;
}

Configure::write('debug', getDebugLevel()); // @violation
?>
