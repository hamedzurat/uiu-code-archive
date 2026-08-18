import random
import math


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


def simulated_annealing(
    initial_temperature=10.0, cooling_rate=0.85, min_temperature=0.01, max_steps=100
):
    current = start
    fuel_left = max_fuel
    distance = 0
    path = [current]

    temperature = initial_temperature

    print(f"Start: {start}")
    print(f"Goal: {goal}")
    print(f"Max fuel: {max_fuel}")
    print("Starting Simulated Annealing search...\n")

    while temperature > min_temperature and distance < max_steps:
        row, col = current

        print(
            f"At {current} | "
            f"cell={maze[row][col]} | "
            f"distance={distance} | "
            f"fuel={fuel_left} | "
            f"temperature={temperature:.4f} | "
            f"heuristic={heuristic(row, col)}"
        )

        if current == goal:
            print("\nGoal reached!")
            return distance, path

        if maze[row][col] == "F":
            fuel_left = max_fuel
            print(f"Refueled at {current}. Fuel reset to {max_fuel}.")

        if fuel_left == 0:
            print("No fuel left.")
            return -1, path

        neighbors = get_directions(row, col)

        if not neighbors:
            print("No valid neighbors.")
            return -1, path

        next_cell = random.choice(neighbors)

        current_score = heuristic(row, col)
        next_row, next_col = next_cell
        next_score = heuristic(next_row, next_col)

        score_difference = next_score - current_score

        if score_difference <= 0:
            accept_move = True
        else:
            probability = math.exp(-score_difference / temperature)
            accept_move = random.random() < probability

        if accept_move:
            current = next_cell
            fuel_left -= 1
            distance += 1
            path.append(current)
            print(f"Accepted move to {current}\n")
        else:
            print(f"Rejected move to {next_cell}\n")

        temperature *= cooling_rate

    if current == goal:
        print("\nGoal reached!")
        return distance, path

    print("Search ended before reaching goal.")
    return -1, path


distance, path = simulated_annealing()
print(f"\nSimulated Annealing distance: {distance}")
print(f"Path: {path}")
