import random
# from common_helpers import create_random_1d_board, generate_swap_neighbors # Import helpers


# ==========================================
# PROBLEM-SPECIFIC FUNCTIONS (MODIFY THESE)
# ==========================================
def objective_function(state):
    """
    Calculate the cost/conflicts of the state.
    Lower is always better. The goal is to reach 0 (or a minimum value).
    """
    # TODO: Implement cost calculation (e.g. number of attacking queens)
    return 0


def generate_neighbors(state):
    """
    Return a list of ALL possible valid neighbor states.
    """
    # TODO: Implement neighbor generation (e.g. move a queen, swap cities)
    return []


def create_initial_state():
    """
    Create and return a random valid initial state.
    """
    # TODO: Randomly initialize state
    return []


def is_perfect_solution(cost):
    """Define what makes a solution 'perfect' to stop early."""
    # TODO: e.g. cost == 0 for N-Queens. Return False if optimizing without a known 0 bound (like TSP)
    return cost == 0


# ==========================================
# HILL CLIMBING ALGORITHM (KEEP THIS AS IS)
# ==========================================
def hill_climbing(initial_state):
    current_state = initial_state
    steps = 0

    while True:
        steps += 1
        current_cost = objective_function(current_state)

        # 1. Check if perfect solution
        if is_perfect_solution(current_cost):
            return current_state, steps

        # 2. Generate and evaluate all neighbors
        neighbors = generate_neighbors(current_state)
        if not neighbors:
            return None, steps  # No moves left

        # Find the single best neighbor
        best_neighbor = min(neighbors, key=objective_function)
        best_neighbor_cost = objective_function(best_neighbor)

        # 3. Check if we are stuck (Local Minimum or Plateau)
        # If the best neighbor is worse than or equal to our current state, stop.
        if best_neighbor_cost >= current_cost:
            return None, steps  # Failed, algorithm is stuck

        # 4. Move to best neighbor
        current_state = best_neighbor


# ==========================================
# EXECUTION BOILERPLATE WITH RESTARTS
# ==========================================
def run_with_restarts(restarts=100):
    print(f"Starting Hill Climbing with up to {restarts} random restarts...")

    best_overall_state = None
    best_overall_cost = float("inf")

    for i in range(restarts):
        state = create_initial_state()
        solution, steps = hill_climbing(state)

        if solution:
            print(
                f"Found perfect solution on attempt {i + 1} after {steps} steps: {solution}"
            )
            return solution

        # Optional: track the best state found so far across all failed restarts (useful for TSP)
        # current_cost = objective_function(state)
        # if current_cost < best_overall_cost:
        #     best_overall_cost = current_cost
        #     best_overall_state = state

    print(f"Failed to find perfect solution after {restarts} restarts.")
    return best_overall_state


if __name__ == "__main__":
    run_with_restarts(100)
