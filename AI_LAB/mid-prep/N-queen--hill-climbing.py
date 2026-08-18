import random

N = 32


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


def hill_climbing(board):
    i = 0
    while True:
        i += 1

        current_conflict = calculate_conflict(board)
        if current_conflict == 0:
            return board, i

        neighbors = generate_neighbors(board)
        best_board = min(neighbors, key=calculate_conflict)
        best_conficts = calculate_conflict(best_board)
        if best_conficts >= current_conflict:
            return None, i

        board = best_board


for _ in range(100):
    board = create_board()
    solution, i = hill_climbing(board)

    if solution:
        print(i, " <> ", solution)
    else:
        print(i, " <> ", "Failed")
