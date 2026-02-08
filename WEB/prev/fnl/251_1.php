<?php

function pass($password)
{
    $len = strlen($password);
    $chars = str_split($password);
    $score = 0;
    $uppercase = 0;
    $lowercase = 0;
    $number = 0;
    $special = 0;

    foreach ($chars as $char) {
        if ($char >= 'A' && $char <= 'Z') {
            $uppercase = 15;
        } elseif ($char >= 'a' && $char <= 'z') {
            $lowercase = 15;
        } elseif ($char >= '0' && $char <= '9') {
            $number = 20;
        } elseif ('!' == $char || '@' == $char || '#' == $char || '$' == $char || '%' == $char || '^' == $char || '&' == $char || '*' == $char) {
            $special = 25;
        }
    }

    if ($len > 5) {
        $score = floor($len / 2) * 10;
    }

    $score += $uppercase + $lowercase + $number + $special;

    // echo $score;

    if ($score < 31) {
        return 'Very weak';
    }
    if ($score < 51) {
        return 'Weak';
    }
    if ($score < 71) {
        return 'Medium';
    }
    if ($score < 91) {
        return 'Srong';
    }
    if ($score < 101) {
        return 'Very Strong';
    }

    return 'Perfect Password!';
}

?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>251 1</title>
</head>

<body>
    <form action="251_1.php" method="get">
        <label for="password">password</label>
        <input type="text" name="password" id="password">
        <button>Check Strength</button>
    </form>
    <h1><?php echo pass($_GET['password'] ?? ''); ?></h1>
</body>

</html>
