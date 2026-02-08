<?php

$attendees = $_GET['attendees'] ?? 0;
$cost = $_GET['cost'] ?? 1;
$capacity = $_GET['capacity'] ?? 0;
$perVenue = 15000;

$venues = ceil($attendees / $capacity);
$empty = ($venues * $capacity) - $attendees;
$wasted = $cost * $empty;

?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>251 2</title>
</head>

<body>
    <form action="251_2.php" method="get">
        <label for="attendees">attendees</label>
        <input type="number" name="attendees" id="attendees" value="<?php echo $attendees; ?>">
        <label for="cost">cost</label>
        <input type="number" name="cost" id="cost" value="<?php echo $cost; ?>">
        <label for="capacity">capacity</label>
        <input type="number" name="capacity" id="capacity" value="<?php echo $capacity; ?>">
        <button>Calculate</button>
    </form>
    <div>
        <h1>Total Venues: <?php echo $venues; ?></h1>
        <h1>Empty Seats: <?php echo $empty; ?></h1>
        <h1>Wasted Money: <?php echo $wasted; ?></h1>
    </div>
</body>

</html>
