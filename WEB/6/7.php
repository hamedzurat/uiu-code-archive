<?php
function bill($number_of_pipeapple, $home_delivery, $address, $tip)
{
    $price = 12.5;
    $bill = 0;

    if ($number_of_pipeapple < 10) {
        $bill = ($number_of_pipeapple * $price * .9);
    } elseif ($number_of_pipeapple < 20) {
        $bill = ($number_of_pipeapple * $price * .85);
    } else {
        $bill = ($number_of_pipeapple * $price * .8);
    }

    if ('yes' == $home_delivery) {
        $bill = $bill + 40;
    }

    if ('DHK' == $address) {
        $bill = $bill * 1.2;
    } elseif ('CHT' == $address) {
        $bill = $bill * 1.15;
    }

    return $bill + $tip;
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
    <form action="7.php" method="post" enctype="multipart/form-data">
        <label>
            Enter the number of pineapple:
            <input type="number" name="pipeapple" value="25" />
        </label>
        <p>Home Delivery:</p>
        <label>
            <input type="radio" name="home_delivery" value="yes">
            Yes
        </label>
        <label>
            <input type="radio" name="home_delivery" value="no" checked>
            No
        </label>
        <label for="city">
            Address:
            <select id="city" name="city">
                <option value="DHK">Dhaka</option>
                <option value="CHT" selected>Chittagong</option>
            </select>
        </label>

        <label>
            Tip: <input type="text" name="tip" value="2.5" />
        </label>
        <button>Calculate bill</button>
    </form>
    <h1>
    <?php
        echo bill(
            $_POST['pipeapple'] ?? 0,
            $_POST['home_delivery'] ?? 'no',
            $_POST['city'] ?? 'DHK',
            $_POST['tip'] ?? 0
        );
?>
    </h1>
</body>
</html>
