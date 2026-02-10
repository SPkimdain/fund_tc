<body>
<form id = "first_form" method="get"> <!-- //@violation -->
<br />
<p>hello</p>
<!-- Some tags here ... -->
</form>
<?
  // Do something for PHP
?>
<form method="get"> <!-- //@violation -->
<!-- Some tags here ... -->
</form>
<?php
  // Do something for PHP
?>
<form method="post">
<!-- Some tags here ... -->
</form>
<!-- commented
  <form method="get">
  </form>
-->
</body>
<?php
