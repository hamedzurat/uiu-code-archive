import random
import math

# Distance matrix where index 0 is the Depot
# dist[i][j] is the distance from location i to location j
dist = [
    [0, 10, 15, 20, 25],
    [10, 0, 35, 25, 30],
    [15, 35, 0, 30, 20],
    [20, 25, 30, 0, 15],
    [25, 30, 20, 15, 0],
]

num_locations = len(dist)
num_customers = num_locations - 1


def create_initial_route():
    # Customers are locations 1 to num_locations-1
    customers = list(range(1, num_locations))
    random.shuffle(customers)
    return customers


def calculate_cost(route):
    total_cost = 0
    prev = 0  # Start at Depot

    for location in route:
        total_cost += dist[prev][location]
        prev = location

    total_cost += dist[prev][0]  # Return to Depot
    return total_cost


def generate_neighbors(route):
    neighbors = []
    # Generate neighbors by swapping two customers in the route
    for i in range(len(route)):
        for j in range(i + 1, len(route)):
            new_route = route.copy()
            new_route[i], new_route[j] = new_route[j], new_route[i]
            neighbors.append(new_route)
    return neighbors


def simulated_annealing(route, temp, cooling, steps):
    current_route = route
    current_cost = calculate_cost(current_route)

    best_route = current_route
    best_cost = current_cost

    for i in range(1, steps + 1):
        neighbors = generate_neighbors(current_route)
        next_route = random.choice(neighbors)
        next_cost = calculate_cost(next_route)

        delta = next_cost - current_cost

        if delta < 0 or random.random() < math.exp(-delta / temp):
            current_route = next_route
            current_cost = next_cost
            if current_cost < best_cost:
                best_cost = current_cost
                best_route = current_route

        temp *= cooling

        if temp < 0.01:
            break

    return best_route, best_cost, i


# Execution
initial_route = create_initial_route()
temp = 100
cooling = 0.95
steps = 500

solution, final_cost, i = simulated_annealing(initial_route, temp, cooling, steps)

if solution:
    print(i, " <> ", [0] + solution + [0], " | Cost:", final_cost)
else:
    print(i, " <> ", "Failed")
