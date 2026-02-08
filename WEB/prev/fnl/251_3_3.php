<?php
$servername = 'localhost';
$username = 'root';
$password = '';
$dbname = 'uiutech_final';
$conn = new mysqli(
    $servername,
    $username,
    $password,
    $dbname
);
if ($conn->connect_error) {
    exit('Connection failed: '.$conn->connect_error);
}

$sql = 'UPDATE employee_final SET Salary = Salary+5000 WHERE Salary>50000 AND Salary<55000';

$result = $conn->query($sql);

if ($result) {
    $rowsUpdated = $conn->affected_rows;
    echo "Update successful! $rowsUpdated employees were updated to rating 'C'.";
} else {
    echo 'Error updating record: '.$conn->error;
}

$conn->close();
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>251 3 3</title>
</head>

<body>
</body>

</html>
