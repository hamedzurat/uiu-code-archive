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

$sql = 'SELECT DepartmentName, COUNT(DepartmentID) AS c FROM `employee_final` GROUP BY DepartmentName ORDER BY COUNT(DepartmentID) DESC;';

$result = $conn->query($sql);

echo 'DepartmentName:  - Count: <br>';
if ($result->num_rows > 0) {
    while ($row = $result->fetch_assoc()) {
        echo $row['DepartmentName'].' - '.$row['c'].'<br>';
    }
} else {
    echo '0 results';
}

$conn->close();
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>251 3 4</title>
</head>

<body>
</body>

</html>
