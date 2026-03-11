<?php

$conn = new mysqli('localhost', 'root', '', 'campus_library');
if ($conn->connect_error) {
    exit('Conn failed');
}

$sql = 'SELECT `BookTitle`, SUM(`PenaltyFee`) as owed FROM `book_loans` GROUP BY `BookTitle` ORDER BY SUM(`PenaltyFee`) DESC; ';
$res = $conn->query($sql);
if (!$res) {
    exit('sql failed');
}

echo 'BookTitle - owed <br/>';
while ($row = $res->fetch_assoc()) {
    echo $row['BookTitle'].' - '.$row['owed'].'<br/>';
}

$conn->close();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>3 - 4</title>
</head>
<body></body>
</html>
