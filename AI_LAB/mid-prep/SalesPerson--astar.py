from heapq import heappush, heappop

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


def heuristic(current_city, unvisited):
    if not unvisited:
        # Distance back to start (city 0)
        return tsp[current_city][0]

    # Simple heuristic: distance to the nearest unvisited city
    # plus the minimum distance to return to start from any unvisited city
    min_to_unvisited = min(tsp[current_city][city] for city in unvisited)
    min_to_start = min(tsp[city][0] for city in unvisited)

    return min_to_unvisited + min_to_start


def astar():
    start_city = 0
    # State: (priority, cost_so_far, current_city, visited_tuple)
    # Using a tuple for visited cities to make it hashable and easy to track
    initial_visited = (start_city,)
    initial_unvisited = set(range(1, num_cities))

    priority_queue = []
    initial_priority = heuristic(start_city, initial_unvisited)

    # (priority, cost_so_far, current_city, visited_tuple)
    heappush(priority_queue, (initial_priority, 0, start_city, initial_visited))

    print("Starting A* Search for TSP...")
    print(f"Number of cities: {num_cities}")
    print(f"Start city: {start_city}\n")

    step = 0
    while priority_queue:
        step += 1
        priority, cost_so_far, current_city, visited = heappop(priority_queue)

        unvisited = set(range(num_cities)) - set(visited)

        print(
            f"Step={step} | visited={visited} | current={current_city} | "
            f"cost={cost_so_far} | priority={priority}"
        )

        # Goal state: all cities visited and returned to start
        if len(visited) == num_cities:
            final_cost = cost_so_far + tsp[current_city][start_city]
            final_path = visited + (start_city,)
            print("\nGoal reached!")
            return final_path, final_cost

        for next_city in unvisited:
            new_visited = visited + (next_city,)
            new_cost = cost_so_far + tsp[current_city][next_city]
            new_unvisited = unvisited - {next_city}
            new_priority = new_cost + heuristic(next_city, new_unvisited)

            print(
                f"  Adding city {next_city} | new_cost={new_cost} | priority={new_priority}"
            )
            heappush(priority_queue, (new_priority, new_cost, next_city, new_visited))

        print()

    return None, -1


# Execution
path, total_cost = astar()

if path:
    print("-" * 30)
    print(f"Best Tour: {' -> '.join(map(str, path))}")
    print(f"Minimum Cost: {total_cost}")
else:
    print("No solution found.")
