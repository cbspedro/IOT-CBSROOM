<?php
include ("conectready.php");
$consulta ="SELECT * FROM esp where id='0'";
$con = $conn->query($consulta);
while ($dado = $con->fetch_array()) {
echo "{\"luz\":\"",($dado ["luz"]),"\",";
echo "\"pc\":\"",($dado ["pc"]),"\",";
echo "\"monitor\":\"",($dado ["monitor"]),"\",";
echo "\"tomadas\":\"",($dado ["tomadas"]),"\"}";
}
?>