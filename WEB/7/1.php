<?php
function series($N)
{
    if (1 == $N) {
        return 1;
    }
    if (2 == $N) {
        return 4;
    }

    return fib($N) + fib($N - 1);
}

function fib($N)
{
    if (1 == $N) {
        return 1;
    }
    if (2 == $N) {
        return 3;
    }

    return fib($N - 1) + fib($N - 2);
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
    <form action=1.php method=post enctype=multipart/form-data>
        <label>
            N: <input type="number" name="n" value=<?php echo $_POST['n']; ?> />
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