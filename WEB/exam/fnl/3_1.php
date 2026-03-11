<?php

$conn = new mysqli('localhost', 'root', '', 'campus_library');
if ($conn->connect_error) {
    exit('Conn failed');
}

$sql = 'SELECT `Status`, COUNT(*) as c FROM `book_loans` GROUP BY `Status` HAVING COUNT(*)>1 ORDER BY COUNT(*) DESC;';
$res = $conn->query($sql);
if (!$res) {
    exit('sql failed');
}

echo 'Status - count <br/>';
while ($row = $res->fetch_assoc()) {
    echo $row['Status'].' - '.$row['c'].'<br/>';
}

$conn->close();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>3 - 1</title>
</head>
<body></body>
</html>
