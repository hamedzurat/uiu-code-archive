maze = [
    "S . . . .".split(),
    "# # . # .".split(),
    ". F . # .".split(),
    "# # . # .".split(),
    ". . . . G".split(),
]

max_fuel = 7

rows = len(maze)
cols = len(maze[0])

moves = [(1, 0), (-1, 0), (0, 1), (0, -1)]


def find_cell(symbol):
    for row in range(rows):
        for col in range(cols):
            if maze[row][col] == symbol:
                return row, col
    raise ValueError(f"Could not find {symbol} in maze")


start = find_cell("S")
goal = find_cell("G")


def manhattan_distance(row, col, target_row, target_col):
    return abs(row - target_row) + abs(col - target_col)


def heuristic(row, col):
    return manhattan_distance(row, col, *goal)


def get_directions(row, col):
    valid_neighbors = []

    for row_change, col_change in moves:
        next_row = row + row_change
        next_col = col + col_change

        inside_maze = 0 <= next_row < rows and 0 <= next_col < cols
        if not inside_maze:
            continue

        if maze[next_row][next_col] == "#":
            continue

        valid_neighbors.append((next_row, next_col))

    return valid_neighbors


def hill_climbing():
    current = start
    fuel_left = max_fuel
    distance = 0
    path = [current]

    print(f"Start: {start}")
    print(f"Goal: {goal}")
    print(f"Max fuel: {max_fuel}")
    print("Starting Hill Climbing search...\n")

    visited = set()

    while current != goal:
        row, col = current

        print(
            f"At {current} | "
            f"cell={maze[row][col]} | "
            f"distance={distance} | "
            f"fuel={fuel_left} | "
            f"heuristic={heuristic(row, col)}"
        )

        if maze[row][col] == "F":
            fuel_left = max_fuel
            print(f"Refueled at {current}. Fuel reset to {max_fuel}.")

        if fuel_left == 0:
            print("No fuel left.")
            return -1, path

        visited.add(current)

        neighbors = get_directions(row, col)

        candidates = []
        for neighbor in neighbors:
            if neighbor not in visited:
                n_row, n_col = neighbor
                candidates.append((heuristic(n_row, n_col), neighbor))

        if not candidates:
            print("No unvisited neighbors available. Stuck.")
            return -1, path

        candidates.sort()
        best_heuristic, next_cell = candidates[0]

        current_heuristic = heuristic(row, col)

        if best_heuristic > current_heuristic:
            print("All available moves are worse. Hill climbing stopped.")
            return -1, path

        current = next_cell
        fuel_left -= 1
        distance += 1
        path.append(current)

        print(f"Moving to {current}\n")

    print("\nGoal reached!")
    return distance, path


distance, path = hill_climbing()
print(f"\nHill Climbing distance: {distance}")
print(f"Path: {path}")
