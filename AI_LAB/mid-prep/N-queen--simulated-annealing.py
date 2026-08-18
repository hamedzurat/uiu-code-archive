import random
import math

N = 8


def create_board():
    board = list(range(N))
    random.shuffle(board)
    return board


def calculate_conflict(board):
    conflict = 0
    for i in range(N):
        for j in range(i + 1, N):
            if abs(board[i] - board[j]) == j - i:
                conflict += 1
    return conflict


def generate_neighbors(board):
    neighbors = []
    for row in range(N):
        for col in range(N):
            if col != board[row]:
                new_board = board.copy()
                new_board[row] = col
                neighbors.append(new_board)
    return neighbors


def simulated_annealing(board, temp, cooling, steps):
    i = 0
    for _ in range(steps):
        i += 1

        current_conflict = calculate_conflict(board)
        if current_conflict == 0:
            return board, i

        neighbors = generate_neighbors(board)
        new_board = random.choice(neighbors)
        new_conflict = calculate_conflict(new_board)

        delta = new_conflict - current_conflict
        if delta < 0 or random.random() < math.exp(-delta / temp):
            board = new_board
        temp *= cooling

    return None, i


for _ in range(100):
    board = create_board()
    temp = 100
    cooling = 0.95
    steps = 1000
    solution, i = simulated_annealing(board, temp, cooling, steps)

    if solution:
        print(i, " <> ", solution)
    else:
        print(i, " <> ", "Failed")
