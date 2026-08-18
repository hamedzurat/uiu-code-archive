import random
import math


start_state = [
    [1, 2, 3],
    [4, 0, 6],
    [7, 5, 8],
]

goal_state = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 0],
]

rows = 3
cols = 3

moves = [(1, 0), (-1, 0), (0, 1), (0, -1)]


def copy_state(state):
    new_state = []

    for row in state:
        new_state.append(row[:])

    return new_state


def print_state(state):
    for row in state:
        print(row)
    print()


def find_tile(state, tile):
    for row in range(rows):
        for col in range(cols):
            if state[row][col] == tile:
                return row, col

    raise ValueError(f"Could not find tile {tile}")


def manhattan_distance(row, col, target_row, target_col):
    return abs(row - target_row) + abs(col - target_col)


def heuristic(state):
    total_distance = 0

    for tile in range(1, 9):
        current_row, current_col = find_tile(state, tile)
        target_row, target_col = find_tile(goal_state, tile)

        total_distance += manhattan_distance(
            current_row, current_col, target_row, target_col
        )

    return total_distance


def is_goal(state):
    return state == goal_state


def get_neighbors(state):
    neighbors = []

    blank_row, blank_col = find_tile(state, 0)

    for row_change, col_change in moves:
        next_row = blank_row + row_change
        next_col = blank_col + col_change

        inside_board = 0 <= next_row < rows and 0 <= next_col < cols
        if not inside_board:
            continue

        new_state = copy_state(state)

        new_state[blank_row][blank_col] = new_state[next_row][next_col]
        new_state[next_row][next_col] = 0

        neighbors.append(new_state)

    return neighbors


def simulated_annealing(
    initial_temperature=10.0, cooling_rate=0.95, min_temperature=0.01, max_steps=500
):
    current_state = copy_state(start_state)
    path = [current_state]

    temperature = initial_temperature
    steps = 0

    print("Start state:")
    print_state(start_state)

    print("Goal state:")
    print_state(goal_state)

    print("Starting Simulated Annealing search...\n")

    while temperature > min_temperature and steps < max_steps:
        print(
            f"Step={steps} | "
            f"temperature={temperature:.4f} | "
            f"heuristic={heuristic(current_state)}"
        )

        print_state(current_state)

        if is_goal(current_state):
            print("Goal reached!")
            return steps, path

        neighbors = get_neighbors(current_state)

        if not neighbors:
            print("No valid neighbors.")
            return -1, path

        next_state = random.choice(neighbors)

        current_score = heuristic(current_state)
        next_score = heuristic(next_state)

        score_difference = next_score - current_score

        if score_difference <= 0:
            accept_move = True
        else:
            probability = math.exp(-score_difference / temperature)
            accept_move = random.random() < probability

        if accept_move:
            current_state = next_state
            path.append(current_state)
            steps += 1
            print("Accepted move.\n")
        else:
            print("Rejected move.\n")

        temperature *= cooling_rate

    if is_goal(current_state):
        print("Goal reached!")
        return steps, path

    print("Search ended before reaching goal.")
    return -1, path


distance, path = simulated_annealing()

print(f"\nSimulated Annealing distance: {distance}")
