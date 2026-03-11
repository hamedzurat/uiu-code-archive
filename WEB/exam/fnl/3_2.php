<?php

$conn = new mysqli('localhost', 'root', '', 'campus_library');
if ($conn->connect_error) {
    exit('Conn failed');
}

$sql = "UPDATE `book_loans` SET `Status`='Grace Period', `PenaltyFee`=0 WHERE `Status`='Overdue' AND `DaysOverdue`<7";
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
    <title>3 - 2</title>
</head>
<body></body>
</html>
