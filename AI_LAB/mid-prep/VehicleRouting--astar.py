from heapq import heappush, heappop

# Distance matrix where index 0 is the Depot
dist = [
    [0, 10, 15, 20, 25],
    [10, 0, 35, 25, 30],
    [15, 35, 0, 30, 20],
    [20, 25, 30, 0, 15],
    [25, 30, 20, 15, 0],
]

num_locations = len(dist)


def heuristic(current_loc, unvisited):
    if not unvisited:
        # Distance back to depot (location 0)
        return dist[current_loc][0]

    # Simple heuristic: distance to the nearest unvisited location
    # plus the minimum distance to return to depot from any unvisited location
    min_to_unvisited = min(dist[current_loc][loc] for loc in unvisited)
    min_to_depot = min(dist[loc][0] for loc in unvisited)

    return min_to_unvisited + min_to_depot


def astar():
    depot = 0
    # State: (priority, cost_so_far, current_loc, visited_tuple)
    initial_visited = (depot,)
    initial_unvisited = set(range(1, num_locations))

    priority_queue = []
    initial_priority = heuristic(depot, initial_unvisited)

    heappush(priority_queue, (initial_priority, 0, depot, initial_visited))

    print("Starting A* Search for Vehicle Routing...")
    print(f"Number of locations: {num_locations}")
    print(f"Depot: {depot}\n")

    step = 0
    while priority_queue:
        step += 1
        priority, cost_so_far, current_loc, visited = heappop(priority_queue)

        unvisited = set(range(num_locations)) - set(visited)

        print(
            f"Step={step} | visited={visited} | current={current_loc} | "
            f"cost={cost_so_far} | priority={priority}"
        )

        # Goal state: all locations visited and returned to depot
        if len(visited) == num_locations:
            final_cost = cost_so_far + dist[current_loc][depot]
            final_path = visited + (depot,)
            print("\nGoal reached!")
            return final_path, final_cost

        for next_loc in unvisited:
            new_visited = visited + (next_loc,)
            new_cost = cost_so_far + dist[current_loc][next_loc]
            new_unvisited = unvisited - {next_loc}
            new_priority = new_cost + heuristic(next_loc, new_unvisited)

            print(
                f"  Adding location {next_loc} | new_cost={new_cost} | priority={new_priority}"
            )
            heappush(priority_queue, (new_priority, new_cost, next_loc, new_visited))

        print()

    return None, -1


# Execution
path, total_cost = astar()

if path:
    print("-" * 30)
    print(f"Best Route: {' -> '.join(map(str, path))}")
    print(f"Minimum Distance: {total_cost}")
else:
    print("No solution found.")
