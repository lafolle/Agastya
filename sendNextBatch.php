<?php
$offset=$_GET["offset"];
$offset=(int)$offset;
$batchLimit=5;

$conn=mysql_connect("localhost", "root", "passwd");
if(!$conn){
	die('could not connect to database.', mysql_error());
}

mysql_select_db("songs");
$query="select sname from songs where sno>$offset and sno<$offset+$batchLimit";
$result=mysql_query($query);
if(!$result)
	die('cannot execute the query.', mysql_error());
$response="";
while($row=mysql_fetch_array($result))
	$response=$response . '^' . row['sname'];

mysql_close($conn);
echo $response . '^';

?>

