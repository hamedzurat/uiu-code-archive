<?php

$submitted = !empty($_GET);

$ct1 = $_GET['ct1'] ?? 0;
$ct2 = $_GET['ct2'] ?? 0;
$ct3 = $_GET['ct3'] ?? 0;
$mid = $_GET['mid'] ?? 0;
$fnl = $_GET['fnl'] ?? 0;

$best = 0;
if ($ct1 > $ct2 && $ct1 > $ct3 && $ct2 > $ct3) {
    $best = $ct1 + $ct2;
} elseif ($ct2 > $ct1 && $ct2 > $ct3 && $ct1 > $ct3) {
    $best = $ct2 + $ct1;
} elseif ($ct3 > $ct1 && $ct3 > $ct2 && $ct1 > $ct2) {
    $best = $ct1 + $ct3;
} elseif ($ct1 > $ct3 && $ct1 > $ct2 && $ct3 > $ct2) {
    $best = $ct3 + $ct1;
} elseif ($ct3 > $ct1 && $ct3 > $ct2 && $ct2 > $ct1) {
    $best = $ct2 + $ct3;
} elseif ($ct2 > $ct1 && $ct2 > $ct3 && $ct3 > $ct1) {
    $best = $ct3 + $ct2;
}
$best = (float) $best / 2;

$total = $best + (int) $mid + (int) $fnl;

$status = '';
if ($total > 54) {
    $status = 'Passed';
} else {
    $status = 'Failed';
}

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>1</title>
</head>
<body>
    <form action="1.php" method="get">
       CT 1: <input type="number" name="ct1" id="ct1"/><br/>
       CT 2: <input type="number" name="ct2" id="ct2"/><br/>
       CT 3: <input type="number" name="ct3" id="ct3"/><br/>
       Midterm marks: <input type="number" name="mid" id="mid"/><br/>
       Final marks: <input type="number" name="fnl" id="fnl"/><br/>

       <button>Calculate total</button>
    </form>

    <?php if ($submitted) { ?>

    <hr/>
    <span>Best two CT's total: <?php echo $best; ?></span><br/>
    <span>Midterm marks: <?php echo $mid; ?></span><br/>
    <span>Final marks: <?php echo $fnl; ?></span><br/>
    <span><b>Total marks = <?php echo $total; ?></b></span><br/>
    <span>Status: <?php echo $status; ?></span><br/>

    <?php } ?>
</body>
</html>