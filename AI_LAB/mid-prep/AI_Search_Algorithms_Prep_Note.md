# AI Search Algorithms Prep Note

This guide provides a universal blueprint for solving any problem using **A\* Search**, **Hill Climbing**, and **Simulated Annealing**. Based on your `mid-prep` repository, here is how you can abstract the logic to apply to _any_ problem.

---

## The Core Blueprint

For _any_ of these algorithms, you must first define three things based on the problem (e.g., TSP, N-Queens, 8-Puzzle, Fuel Routing):

1. **State Representation:** How do you represent a single snapshot of the problem?
   - _TSP/Routing:_ A tuple of visited cities `(0, 1, 3)` and the current city.
   - _N-Queens:_ A list where index is row and value is column `[2, 0, 3, 1]`.
2. **Evaluation Function:**
   - _A_:\* `f(n) = g(n) + h(n)` (cost so far + heuristic estimate to goal).
   - _Hill Climbing / SA:_ Objective/Conflict function (e.g., number of attacking queens, total distance). You want to minimize this.
3. **Neighbor Generation:**
   - _TSP/Routing:_ Moving to any unvisited city.
   - _N-Queens:_ Moving one queen to a different column in its row.

---

## 1. A\* Search (A-Star)

A\* uses a priority queue to always explore the most promising path first.

### Key Concepts:

- **Priority Queue (`heapq`):** Keeps states sorted by their priority `f(n)`.
- **`g(n)`:** The exact cost to reach the current state from the start.
- **`h(n)`:** The heuristic function. Must not overestimate the cost to reach the goal.

### Universal Code Template:

```python
from heapq import heappush, heappop

def heuristic(current_state, unvisited_or_goal):
    # TODO: Estimate the cost from current_state to the goal
    return estimated_cost

def astar():
    start_state = ... # Initialize start

    # Priority Queue elements: (priority, cost_so_far, current_state, extra_tracking_data)
    priority_queue = []

    initial_priority = heuristic(start_state, initial_targets)
    heappush(priority_queue, (initial_priority, 0, start_state, initial_path))

    while priority_queue:
        priority, cost_so_far, current_state, path = heappop(priority_queue)

        # 1. Check Goal Condition
        if is_goal(current_state, path):
            return path, cost_so_far

        # 2. Generate Neighbors
        for neighbor in generate_neighbors(current_state):
            new_cost = cost_so_far + transition_cost(current_state, neighbor)
            new_path = path + (neighbor,)
            new_priority = new_cost + heuristic(neighbor, remaining_targets)

            # 3. Push to queue
            heappush(priority_queue, (new_priority, new_cost, neighbor, new_path))

    return None, -1 # No solution
```

---

## 2. Hill Climbing

Hill Climbing looks at immediate neighbors and strictly moves to the one that improves the objective the most. It is prone to getting stuck in local optima.

### Key Concepts:

- **Steepest Ascent/Descent:** Evaluates _all_ neighbors and picks the absolute best one.
- **Stopping Condition:** If the best neighbor is worse than or equal to the current state, the algorithm stops (stuck).
- **Random Restarts:** Often put inside a `for _ in range(100):` loop to retry with new random initial states if it fails.

### Universal Code Template:

```python
import random

def objective_function(state):
    # TODO: Calculate cost/conflicts (e.g., attacking queens). Lower is better.
    return conflicts

def generate_neighbors(state):
    # TODO: Return a list of all possible valid neighbor states
    return neighbors_list

def hill_climbing(initial_state):
    current_state = initial_state

    while True:
        current_cost = objective_function(current_state)

        # 1. Check if perfect solution
        if current_cost == 0: # or target goal
            return current_state

        # 2. Generate and evaluate all neighbors
        neighbors = generate_neighbors(current_state)

        # Find the neighbor with the minimum cost
        best_neighbor = min(neighbors, key=objective_function)
        best_neighbor_cost = objective_function(best_neighbor)

        # 3. Check if we are stuck (local minimum)
        if best_neighbor_cost >= current_cost:
            return None # Failed, need to restart

        # 4. Move to best neighbor
        current_state = best_neighbor

# Execution (with restarts)
for _ in range(100):
    state = create_random_state()
    solution = hill_climbing(state)
    if solution:
        print("Found:", solution)
        break
```

---

## 3. Simulated Annealing (SA)

SA is similar to Hill Climbing but it introduces **temperature**. It occasionally accepts _worse_ states to escape local minima. As time goes on, the temperature cools down, and it behaves more like strict Hill Climbing.

### Key Concepts:

- **Random Neighbor:** Instead of evaluating all neighbors, you pick _one_ at random.
- **Delta (`ΔE`):** `new_cost - current_cost`.
  - If `ΔE < 0`, the new state is better -> **Always Accept**.
  - If `ΔE > 0`, the new state is worse -> **Accept with probability `e^(-ΔE / Temp)`**.
- **Cooling Schedule:** Temperature decreases every step (`Temp = Temp * cooling_rate`).

### Universal Code Template:

```python
import random
import math

def objective_function(state):
    # Calculate cost/conflicts (lower is better)
    return conflicts

def simulated_annealing(initial_state, temp=100, cooling=0.95, steps=1000):
    current_state = initial_state

    for _ in range(steps):
        current_cost = objective_function(current_state)

        # 1. Goal Check
        if current_cost == 0:
            return current_state

        # 2. Pick ONE random neighbor
        neighbors = generate_neighbors(current_state)
        new_state = random.choice(neighbors)
        new_cost = objective_function(new_state)

        # 3. Calculate difference
        delta = new_cost - current_cost

        # 4. Acceptance Probability
        # If delta < 0, math.exp() check is bypassed because delta < 0 is explicitly checked
        if delta < 0 or random.random() < math.exp(-delta / temp):
            current_state = new_state

        # 5. Cool down
        temp *= cooling

    return None # Failed to find perfect solution within steps
```

## Summary Comparison

| Feature             | A\* Search                            | Hill Climbing                        | Simulated Annealing                   |
| :------------------ | :------------------------------------ | :----------------------------------- | :------------------------------------ |
| **Completeness**    | Optimal & Complete (finds best path)  | Incomplete (can get stuck)           | Incomplete (probabilistic)            |
| **Memory Usage**    | High (keeps states in Priority Queue) | Low (only keeps current & neighbors) | Very Low (keeps current & 1 neighbor) |
| **State Selection** | Popped from PQ based on `g(n) + h(n)` | Best among ALL neighbors             | One random neighbor                   |
| **Worse Moves?**    | Explores alternative paths if needed  | Never                                | Yes, based on `e^(-ΔE/T)`             |
