<?php
function series($n)
{
    if (1 == $n) {
        return 1;
    }

    $sum = series($n - 1);

    $term = 1;
    for ($i = 2; $i <= $n; ++$i) {
        $term = ($term * $term) + 2;
    }

    if (0 == $n % 2) {
        return $sum + $term;
    } else {
        return $sum - $term;
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
    <form action=2.php method=post enctype=multipart/form-data>
        <label>
            N: <input type="number" name="n" value=<?php echo $_POST['n'] ?? 1; ?> />
        </label>
        <button>Calculate bill</button>
    </form>
    <h1>
        <?php
        echo series($_POST['n'] ?? 1);
?>
    </h1>
</body>

</html>