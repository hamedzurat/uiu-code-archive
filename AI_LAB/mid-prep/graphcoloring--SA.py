import random
import math


# Graph represented as an adjacency list
graph = {
    0: [1, 2],
    1: [0, 2, 3],
    2: [0, 1, 3],
    3: [1, 2, 4],
    4: [3],
}

nodes = list(graph.keys())

num_colors = 3

colors = list(range(num_colors))


def create_coloring():
    coloring = {}

    for node in nodes:
        coloring[node] = random.choice(colors)

    return coloring


def calculate_conflict(coloring):
    conflict = 0

    for node in graph:
        for neighbor in graph[node]:
            if coloring[node] == coloring[neighbor]:
                conflict += 1

    # Each conflict is counted twice:
    # once from node -> neighbor
    # once from neighbor -> node
    return conflict // 2


def generate_neighbors(coloring):
    neighbors = []

    for node in nodes:
        current_color = coloring[node]

        for color in colors:
            if color != current_color:
                new_coloring = coloring.copy()
                new_coloring[node] = color
                neighbors.append(new_coloring)

    return neighbors


def print_coloring(coloring):
    for node in coloring:
        print(f"Node {node} -> Color {coloring[node]}")
    print()


def simulated_annealing(coloring, temp, cooling, steps):
    i = 0

    for _ in range(steps):
        i += 1

        current_conflict = calculate_conflict(coloring)

        print(f"Step={i} | temperature={temp:.4f} | conflict={current_conflict}")

        if current_conflict == 0:
            return coloring, i

        neighbors = generate_neighbors(coloring)
        new_coloring = random.choice(neighbors)

        new_conflict = calculate_conflict(new_coloring)

        delta = new_conflict - current_conflict

        if delta < 0:
            accept_move = True
        else:
            probability = math.exp(-delta / temp)
            accept_move = random.random() < probability

        if accept_move:
            coloring = new_coloring
            print("Accepted move.\n")
        else:
            print("Rejected move.\n")

        temp *= cooling

    return None, i


coloring = create_coloring()

temp = 100
cooling = 0.95
steps = 1000

solution, i = simulated_annealing(coloring, temp, cooling, steps)

if solution:
    print("Solved!")
    print(i, " <> ", solution)
    print_coloring(solution)
else:
    print(i, " <> ", "Failed")
