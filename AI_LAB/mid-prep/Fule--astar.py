from heapq import heappush, heappop
from math import sqrt


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


def euclidean_distance(row, col, target_row, target_col):
    return sqrt((row - target_row) ** 2 + (col - target_col) ** 2)


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

        is_wall = maze[next_row][next_col] == "#"
        if is_wall:
            continue

        valid_neighbors.append((next_row, next_col))

    return valid_neighbors


def astar():
    best_fuel_seen = [[-1 for _ in range(cols)] for _ in range(rows)]

    start_row, start_col = start
    start_fuel = max_fuel
    start_distance = 0
    start_priority = start_distance + heuristic(start_row, start_col)

    priority_queue = []
    heappush(priority_queue, (start_priority, start_distance, start_fuel, start))

    best_fuel_seen[start_row][start_col] = start_fuel

    print(f"Start: {start}")
    print(f"Goal: {goal}")
    print(f"Max fuel: {max_fuel}")
    print("Starting A* search...\n")

    while priority_queue:
        priority, distance_so_far, fuel_left, (row, col) = heappop(priority_queue)

        print(
            f"Visiting {(row, col)} | "
            f"cell={maze[row][col]} | "
            f"distance={distance_so_far} | "
            f"fuel={fuel_left} | "
            f"priority={priority}"
        )

        if (row, col) == goal:
            print("\nGoal reached!")
            return distance_so_far

        if maze[row][col] == "F":
            fuel_left = max_fuel
            print(f"Refueled at {(row, col)}. Fuel reset to {max_fuel}.")

        if fuel_left == 0:
            print(f"No fuel left at {(row, col)}. Skipping.")
            continue

        for next_row, next_col in get_directions(row, col):
            next_fuel = fuel_left - 1

            if best_fuel_seen[next_row][next_col] >= next_fuel:
                print(
                    f"  Skipping {(next_row, next_col)}: "
                    f"already reached before with fuel "
                    f"{best_fuel_seen[next_row][next_col]}."
                )
                continue

            best_fuel_seen[next_row][next_col] = next_fuel

            next_distance = distance_so_far + 1
            next_priority = next_distance + heuristic(next_row, next_col)

            print(
                f"  Adding {(next_row, next_col)} | "
                f"distance={next_distance} | "
                f"fuel={next_fuel} | "
                f"priority={next_priority}"
            )

            heappush(
                priority_queue,
                (
                    next_priority,
                    next_distance,
                    next_fuel,
                    (next_row, next_col),
                ),
            )

        print()

    print("No path found.")
    return -1


shortest_distance = astar()
print(f"\nShortest distance: {shortest_distance}")
