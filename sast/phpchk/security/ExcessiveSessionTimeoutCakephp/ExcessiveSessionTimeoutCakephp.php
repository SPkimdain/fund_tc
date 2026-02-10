<?
include 'Configure.php';

Configure::write('Security.level', 'high');
Configure::write('Security.level', 'low'); // @violation
Configure::write('arbitrary', 'low');

$level = 'low';
Configure::write('Security.level', $level); // @violation
Configure::write('Security.level', $level . 'arbitrary');

function getDebugLevel() {
    if(check()) {
        return 'high';
    }
    else {
        return 'low';
    }
}

Configure::write('Security.level', getDebugLevel()); // @violation
?>
