import random
import math

# Cost matrix representing distances between cities
# tsp[i][j] is the distance from city i to city j
tsp = [
    [0, 400, 500, 300, 200],
    [400, 0, 300, 500, 450],
    [500, 300, 0, 400, 350],
    [300, 500, 400, 0, 250],
    [200, 450, 350, 250, 0],
]

num_cities = len(tsp)


def create_initial_tour():
    tour = list(range(num_cities))
    random.shuffle(tour)
    return tour


def calculate_cost(tour):
    total_cost = 0
    for i in range(num_cities):
        city1 = tour[i]
        city2 = tour[(i + 1) % num_cities]
        total_cost += tsp[city1][city2]
    return total_cost


def generate_neighbors(tour):
    neighbors = []
    # Generate neighbors by swapping two cities
    for i in range(num_cities):
        for j in range(i + 1, num_cities):
            new_tour = tour.copy()
            new_tour[i], new_tour[j] = new_tour[j], new_tour[i]
            neighbors.append(new_tour)
    return neighbors


def simulated_annealing(tour, temp, cooling, steps):
    current_tour = tour
    current_cost = calculate_cost(current_tour)

    best_tour = current_tour
    best_cost = current_cost

    for i in range(1, steps + 1):
        neighbors = generate_neighbors(current_tour)
        next_tour = random.choice(neighbors)
        next_cost = calculate_cost(next_tour)

        delta = next_cost - current_cost

        if delta < 0 or random.random() < math.exp(-delta / temp):
            current_tour = next_tour
            current_cost = next_cost
            if current_cost < best_cost:
                best_cost = current_cost
                best_tour = current_tour

        temp *= cooling

        if temp < 0.01:
            break

    return best_tour, best_cost, i


initial_tour = create_initial_tour()
temp = 100
cooling = 0.95
steps = 500
solution, final_cost, i = simulated_annealing(initial_tour, temp, cooling, steps)

if solution:
    print(i, " <> ", solution, " | Cost:", final_cost)
else:
    print(i, " <> ", "Failed")
