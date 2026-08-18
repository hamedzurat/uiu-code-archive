from heapq import heappush, heappop
# from common_helpers import manhattan_distance # Import your needed helpers here


# ==========================================
# PROBLEM-SPECIFIC FUNCTIONS (MODIFY THESE)
# ==========================================
def heuristic(current_state, unvisited_or_goal):
    """
    Estimate the cost from current_state to the goal.
    Must NOT overestimate the true cost.
    """
    # TODO: Implement your heuristic logic
    return 0


def is_goal(current_state, path, targets):
    """Check if the current state is the goal."""
    # TODO: e.g., if len(path) == total_nodes or current_state == goal_state
    return False


def generate_neighbors(state):
    """Return a list of valid neighbors for the state."""
    # TODO: Implement neighbor generation
    return []


def transition_cost(state1, state2):
    """The exact cost of moving from state1 to state2."""
    # TODO: Return distance, weight, or 1 for uniform cost
    return 1


# ==========================================
# A* ALGORITHM TEMPLATE (KEEP THIS AS IS)
# ==========================================
def astar(start_state, targets=None):
    # Priority Queue elements: (priority, cost_so_far, current_state, path)
    priority_queue = []

    # Track the path taken
    initial_path = (start_state,)

    # Calculate initial priority: f(start) = g(start) + h(start) = 0 + h(start)
    initial_priority = heuristic(start_state, targets)

    # Push initial state to the queue
    heappush(priority_queue, (initial_priority, 0, start_state, initial_path))

    step = 0
    while priority_queue:
        step += 1

        # Pop the state with the lowest priority (lowest f(n))
        priority, cost_so_far, current_state, path = heappop(priority_queue)

        print(
            f"Step {step} | Cost: {cost_so_far} | Priority: {priority} | State: {current_state}"
        )

        # 1. Check Goal Condition
        if is_goal(current_state, path, targets):
            print(f"\nGoal reached in {step} steps!")
            return path, cost_so_far

        # 2. Generate and Process Neighbors
        neighbors = generate_neighbors(current_state)

        for neighbor in neighbors:
            # Calculate exact cost to reach the neighbor (g)
            step_cost = transition_cost(current_state, neighbor)
            new_cost = cost_so_far + step_cost

            # Update path
            new_path = path + (neighbor,)

            # Calculate heuristic for neighbor (h) and final priority (f = g + h)
            new_priority = new_cost + heuristic(neighbor, targets)

            # 3. Push to queue
            heappush(priority_queue, (new_priority, new_cost, neighbor, new_path))

    print("\nNo solution found.")
    return None, -1


# ==========================================
# EXECUTION BOILERPLATE
# ==========================================
if __name__ == "__main__":
    start = "START_NODE"  # Define your starting node/state
    path, total_cost = astar(start)

    if path:
        print("-" * 30)
        print(f"Best Tour: {' -> '.join(map(str, path))}")
        print(f"Minimum Cost: {total_cost}")
