<?php

$conn = new mysqli('localhost', 'root', '', 'campus_library');
if ($conn->connect_error) {
    exit('Conn failed');
}

$sql = 'UPDATE `book_loans` SET `PenaltyFee`=`PenaltyFee`+(`PenaltyFee`*.1) WHERE `PenaltyFee`>20 AND (`PenaltyFee`+(`PenaltyFee`*.1))<50;';
$res = $conn->query($sql);
if (!$res) {
    exit('sql failed');
}

echo 'Updated rows: '.$conn->affected_rows;

$conn->close();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>3 - 3</title>
</head>
<body></body>
</html>
