<?php
$result = '';
$num = $_POST['num'] ?? null;

if (null !== $num) {
    if ($num <= 5) {
        $result = "it's small";
    } elseif ($num >= 6 && $num <= 8) {
        $result = "it's mid";
    } else {
        $result = "it's big";
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/skeleton/2.0.4/skeleton.min.css" integrity="sha512-EZLkOqwILORob+p0BXZc+Vm3RgJBOe1Iq/0fiI7r/wJgzOFZMlsqTa29UEl6v6U6gsV4uIpsNZoV32YZqrCRCQ==" crossorigin="anonymous" referrerpolicy="no-referrer" />
    <title>PHP test</title>
</head>
<body>
    <form action="4.php" method="post" enctype="multipart/form-data">
        <h1>Enter a number</h1>
        <input type="number" name="num" />
        <button>Send</button>
    </form>
    <h1><?php echo $result; ?></h1>
</body>
</html>
