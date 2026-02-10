@{
var message="";
var weekday=DateTime.Now.DayOfWeek;
var day=weekday.ToString()
}
<html>
<head>
<SCRIPT type="text/vbscript">
     <!--
       Sub foo()
        ...
       End Sub
     ' -->
     eval();
</SCRIPT>
<script type="text/javascript">
  forbidden(); //@violation
  document.write("Hello World!");
</script>

</head>
<body>
@switch(day)
{
case "Monday":
    message="This is the first weekday.";
    break;
case "Thursday":
    message="Only one day before weekend.";
    break;
case "Friday":
    message="Tomorrow is weekend!";
    break;
default:
    message="Today is " + day;
    break;
}
<p>@message</p>
</body>
</html>