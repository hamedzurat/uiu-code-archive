<?php
function adder($a, $b)
{
    return $a + $b;
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
    <form action="6.php" method="get" enctype="multipart/form-data">
        <input type="number" name="num1" />
        <input type="number" name="num2" />
        <button>ADD</button>
    </form>

    <?php
      echo '<h1>'.adder($_GET['num1'] ?? 0, $_GET['num2'] ?? 0).'</h1>';
?>
</body>
</html>
