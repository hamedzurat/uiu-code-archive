import random
import math
# from common_helpers import create_random_1d_board # Import helpers


# ==========================================
# PROBLEM-SPECIFIC FUNCTIONS (MODIFY THESE)
# ==========================================
def objective_function(state):
    """
    Calculate the cost/conflicts of the state.
    Lower is always better.
    """
    # TODO: Implement cost calculation
    return 0


def generate_neighbors(state):
    """
    Return a list of ALL possible valid neighbor states.
    (SA will pick just one at random from this list)
    """
    # TODO: Implement neighbor generation
    return []


def create_initial_state():
    """Create and return a random valid initial state."""
    # TODO: Randomly initialize state
    return []


def is_perfect_solution(cost):
    """Define what makes a solution 'perfect' to stop early."""
    return cost == 0


# ==========================================
# SIMULATED ANNEALING ALGORITHM (KEEP THIS AS IS)
# ==========================================
def simulated_annealing(
    initial_state, initial_temp=100, cooling_rate=0.95, max_steps=1000
):
    current_state = initial_state
    temp = initial_temp

    for step in range(max_steps):
        current_cost = objective_function(current_state)

        # 1. Goal Check
        if is_perfect_solution(current_cost):
            return current_state, step

        # 2. Pick ONE random neighbor
        neighbors = generate_neighbors(current_state)
        if not neighbors:
            return None, step  # Dead end

        new_state = random.choice(neighbors)
        new_cost = objective_function(new_state)

        # 3. Calculate difference (Delta E)
        delta = new_cost - current_cost

        # 4. Acceptance Probability
        # If delta < 0 (better state), we always accept
        # If delta >= 0 (worse state), we accept with probability e^(-delta / temp)
        if delta < 0 or random.random() < math.exp(-delta / temp):
            current_state = new_state

        # 5. Cool down
        temp *= cooling_rate

    # Failed to find perfect solution within max_steps
    # Return the last state reached (often useful for optimization problems like TSP)
    return current_state, max_steps


# ==========================================
# EXECUTION BOILERPLATE
# ==========================================
def run_sa(restarts=1):
    """SA is less reliant on restarts than HC, but multiple runs can still help."""
    print("Starting Simulated Annealing...")

    for i in range(restarts):
        state = create_initial_state()
        solution, steps = simulated_annealing(
            state, initial_temp=100, cooling_rate=0.95, max_steps=1000
        )

        final_cost = objective_function(solution) if solution else float("inf")

        if is_perfect_solution(final_cost):
            print(
                f"Found perfect solution on attempt {i + 1} after {steps} steps: {solution}"
            )
            return solution
        else:
            print(f"Finished attempt {i + 1}. Best cost achieved: {final_cost}")

    return solution


if __name__ == "__main__":
    run_sa(restarts=10)
