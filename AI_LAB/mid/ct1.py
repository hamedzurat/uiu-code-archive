from heapq import heappush, heappop

G = {
    'A': [('B', 4), ('C', 5)],
    'B': [('D', 4)],
    'C': [('D',1),('F', 10)],
    'D': [('E',3)],
    'E': [('F',2)],
    'F': [],    
}

start = "A"
goal = "F"

h = {
    'A': 10,
    'B': 8,
    'C': 5,
    'D': 3,
    'E': 1,
    'F': 0
}



def astar(G):
    priority_queue = []
    D = {start:0}
    parent = {}
    step = 1


    heappush(priority_queue, (0, start))

    while priority_queue:
        step+=1

        priority, N = heappop(priority_queue)

        print(
            f"Step {step} | Priority: {priority} | Node: {N}"
        )

        # 1. Check Goal Condition
        if N == goal:
            print(f"Goal reached in {step} steps!\n\n")
            break

        for neighbor, W in G[N]:
            # Calculate exact cost to reach the neighbor (g)
            step_cost = D[N]
            new_cost = W + step_cost

            if neighbor not in D or D[neighbor] > new_cost:
                D[neighbor] = new_cost
                parent[neighbor] = N

                heappush(priority_queue, (new_cost + h[neighbor], neighbor))
        
    traversal = []
    node = goal

    while node != start:
        traversal.append(node)
        node = parent[node]

    traversal.append(start)
    traversal.reverse()

    return step, traversal, D[goal]



steps, tpath, cost = astar(G)

print("Path: ", tpath)
print("Cost:", cost)
print("Explored:", steps)