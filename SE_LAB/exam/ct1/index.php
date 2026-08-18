<?php
$conn = new mysqli("localhost", "root", "", "ct");

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

if (isset($_GET['deleteMovieReview'])) {
    $id = $_GET['deleteMovieReview'];
    $conn->query("DELETE FROM reviews WHERE id=$id");

    header("Location: index.php");
    exit();
}

if (isset($_POST['updateGenre'])) {
    $id = $_POST['id'];
    $genre = $_POST['genre'];

    $conn->query("UPDATE movies SET genre='$genre' WHERE id=$id");

    header("Location: index.php");
    exit();
}

?>


<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <title>CRUD App</title>
    <!-- <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/skeleton/2.0.4/skeleton.min.css"> -->
</head>

<body class="container">
    <h1>Movies</h1>
    <table class="u-full-width">
        <thead>
            <tr>
                <th>ID</th>
                <th>title</th>
                <th>genre</th>
                <th>release_year</th>
                <th>update genre</th>
            </tr>
        </thead>
        <tbody>
            <?php
            $result = $conn->query("SELECT * FROM movies");
            $rows = $result->fetch_all(MYSQLI_ASSOC);

            foreach ($rows as $row):
            ?>
                <tr>
                    <td><?= $row['id'] ?></td>
                    <td><?= $row['title'] ?></td>
                    <td><?= $row['genre'] ?></td>
                    <td><?= $row['release_year'] ?></td>
                    <td>
                        <form method="POST">
                            <input type="hidden" name="id" value="<?= $row['id'] ?? '' ?>">
                            <input type="text" name="genre" placeholder="genre" required value="<?= $row['genre'] ?? '' ?>">
                            <button type="submit" name="updateGenre">Update</button>
                        </form>
                    </td>
                </tr>
            <?php endforeach; ?>

        </tbody>
    </table>
    <h1>actor</h1>
    <table class="u-full-width">
        <thead>
            <tr>
                <th>ID</th>
                <th>name</th>
                <th>age</th>
                <th>movie_title</th>
            </tr>
        </thead>
        <tbody>
            <?php
            $result = $conn->query("SELECT * FROM actor");
            $rows = $result->fetch_all(MYSQLI_ASSOC);

            foreach ($rows as $row):
            ?>
                <tr>
                    <td><?= $row['id'] ?></td>
                    <td><?= $row['name'] ?></td>
                    <td><?= $row['age'] ?></td>
                    <td><?= $row['movie_title'] ?></td>
                </tr>
            <?php endforeach; ?>

        </tbody>
    </table>
    <h1>reviews</h1>
    <table class="u-full-width">
        <thead>
            <tr>
                <th>ID</th>
                <th>movie_title</th>
                <th>reviewer_name</th>
                <th>rating</th>
            </tr>
        </thead>
        <tbody>
            <?php
            $result = $conn->query("SELECT * FROM reviews");
            $rows = $result->fetch_all(MYSQLI_ASSOC);

            foreach ($rows as $row):
            ?>
                <tr>
                    <td><?= $row['id'] ?></td>
                    <td><?= $row['movie_title'] ?></td>
                    <td><?= $row['reviewer_name'] ?></td>
                    <td><?= $row['rating'] ?></td>
                    <td>
                        <a href="?deleteMovieReview=<?= $row['id'] ?>">Delete</a>
                    </td>
                </tr>
            <?php endforeach; ?>

        </tbody>
    </table>
</body>

</html>