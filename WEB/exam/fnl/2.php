<?php

$submitted = !empty($_GET);

$sold = $_GET['sold'] ?? 0;
$days = $_GET['days'] ?? 0;
$target = $_GET['target'] ?? 0;

$total = $sold * $days;
$diff = $target - $total;

$performance = '';
if ($total < 150) {
    $performance = 'Poor';
} elseif ($total < 300) {
    $performance = 'Average';
} elseif ($total < 500) {
    $performance = 'Good';
} else {
    $performance = 'Excellent';
}

$result = '';
if ($diff < 0) {
    $result = 'Above target by '.abs($diff);
} elseif ($diff > 0) {
    $result = 'Below target by '.abs($diff);
} else {
    $result = 'Target met exactly (0';
}

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>2</title>
</head>
<body>
    <form action="2.php" method="get">
       Items sold: <input type="number" name="sold" id="sold"/><br/>
       Days: <input type="number" name="days" id="days"/><br/>
       Target: <input type="number" name="target" id="target"/><br/>
       <button>Calculate</button>
    </form>


    <?php if ($submitted) { ?>
    
    <hr/>
    <span>Total items: <?php echo $total; ?></span><br/>
    <span>Performance: <?php echo $performance; ?></span><br/>
    <span>Result: <?php echo $result; ?></span><br/>

    <?php } ?>
</body>
</html>
