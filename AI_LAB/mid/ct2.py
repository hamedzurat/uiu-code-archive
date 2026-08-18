import random
import math

def calculate_cost(x):
    return (x*x*x*x) - (2*(x*x*x)) - x*x + 1

def generate_neighbors(currnt_x, step):
    neighbors = []
    neighbors.append(currnt_x+step)
    neighbors.append(currnt_x-step)
    return neighbors


def simulated_annealing(temp, cooling, x, step_size, max):
    print("SA")
    i = 0
    for _ in range(max):
        i += 1

        current_cost = calculate_cost(x)
        if current_cost == 0:
            return x, i

        neighbors = generate_neighbors(x, step_size)
        new_x = random.choice(neighbors)
        new_cost = calculate_cost(new_x)

        delta = new_cost - current_cost
        if delta < 0 or random.random() < math.exp(-delta / temp):
            x = new_x
        temp *= cooling

        print(
            f"x: {x} | ",
            f"current_cost: {current_cost} | ",
            f"neighbors: {neighbors} | ",
            f"new_x: {new_x} | ",
            f"delta: {delta} | ",
        )

    return None, i

def hill_climbing(x, step_size, max):
    print("Hill")
    i = 0
    for _ in range(max):
        i += 1

        current_cost = calculate_cost(x)
        if current_cost == 0:
            return x, i

        neighbors = generate_neighbors(x, step_size)
        best_x = min(neighbors, key=calculate_cost)
        best_cost = calculate_cost(best_x)

        print(
            f"x: {x} | ",
            f"current_cost: {current_cost} | ",
            f"neighbors: {neighbors} | ",
            f"best_x: {best_x} | ",
            f"best_cost: {best_cost} | ",
        )

        if best_cost >= current_cost:
            return None, i

        x = best_x
    return None, i
    

temp = 100
cooling = 0.95

x = 1
step_size = 0.25
max = 100

solution_hill, i_hill = hill_climbing(x, step_size, max)
solution_SA, i_SA = simulated_annealing(temp, cooling, x, step_size, max)

if solution_hill:
    print(i_hill, " <> ", solution_hill)
else:
    print(i_hill, " <> ", "Failed")

if solution_SA:
    print(i_SA, " <> ", solution_SA)
else:
    print(i_SA, " <> ", "Failed")