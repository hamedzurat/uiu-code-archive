import math
import random
from copy import deepcopy


# ==========================================
# DISTANCE & HEURISTIC FUNCTIONS (TSP, Routing, A*)
# ==========================================
def euclidean_distance(x1, y1, x2, y2):
    """Straight-line distance between two points"""
    return math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)


def manhattan_distance(x1, y1, x2, y2):
    """Grid-based distance (useful for 8-puzzle and grids)"""
    return abs(x1 - x2) + abs(y1 - y2)


# ==========================================
# 1D ARRAY / COMBINATORIAL HELPERS (N-Queens, TSP)
# ==========================================
def create_random_1d_board(N):
    """Creates a random 1D board [0, 1, ..., N-1] shuffled."""
    board = list(range(N))
    random.shuffle(board)
    return board


def calculate_nqueens_conflict(board):
    """Calculates attacking pairs for N-Queens in a 1D board.
    Assumes row-per-index representation (no horizontal/vertical clashes possible by design).
    Only checks diagonal conflicts.
    """
    conflict = 0
    N = len(board)
    for i in range(N):
        for j in range(i + 1, N):
            if abs(board[i] - board[j]) == j - i:
                conflict += 1
    return conflict


def generate_nqueens_neighbors(board):
    """Generates all neighbors by moving one queen to a different column in its row."""
    neighbors = []
    N = len(board)
    for row in range(N):
        for col in range(N):
            if col != board[row]:
                new_board = board.copy()
                new_board[row] = col
                neighbors.append(new_board)
    return neighbors


def generate_swap_neighbors(board):
    """Generates all neighbors by swapping two elements.
    Highly useful for TSP, Vehicle Routing, and Scheduling.
    """
    neighbors = []
    N = len(board)
    for i in range(N):
        for j in range(i + 1, N):
            new_board = board.copy()
            new_board[i], new_board[j] = new_board[j], new_board[i]
            neighbors.append(new_board)
    return neighbors


# ==========================================
# 2D GRID HELPERS (8-Puzzle, Maze Routing)
# ==========================================
def find_in_2d_grid(board, target_value=0):
    """Finds the (row, col) coordinates of a target value (like the blank tile '0')."""
    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j] == target_value:
                return i, j
    return -1, -1


def generate_sliding_puzzle_neighbors(board, blank_value=0):
    """Generates neighbors for a sliding puzzle (e.g., 8-Puzzle).
    Swaps the blank tile with adjacent tiles (Up, Down, Left, Right).
    """
    neighbors = []
    r, c = find_in_2d_grid(board, blank_value)
    if r == -1:
        return []  # Blank not found

    rows, cols = len(board), len(board[0])
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]  # Up, Down, Left, Right

    for dr, dc in directions:
        nr, nc = r + dr, c + dc
        # If the move is within grid bounds
        if 0 <= nr < rows and 0 <= nc < cols:
            new_board = deepcopy(board)
            # Swap blank with adjacent tile
            new_board[r][c], new_board[nr][nc] = new_board[nr][nc], new_board[r][c]
            neighbors.append(new_board)

    return neighbors


def calculate_misplaced_tiles(board, goal_board):
    """Simple heuristic for 8-puzzle: counts tiles not in goal position."""
    count = 0
    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j] != 0 and board[i][j] != goal_board[i][j]:
                count += 1
    return count
