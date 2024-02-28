from collections import defaultdict

def dfs(node, graph, visited):
    visited[node] = True
    max_distance = 0
    farthest_node = node

    for neighbor, distance in graph[node]:
        if not visited[neighbor]:
            temp_distance, temp_node = dfs(neighbor, graph, visited)
            temp_distance += distance
            if temp_distance > max_distance:
                max_distance = temp_distance
                farthest_node = temp_node

    return max_distance, farthest_node

def diameter_of_tree(n, edges):
    graph = defaultdict(list)

    for edge in edges:
        u, v, w = edge
        graph[u].append((v, w))
        graph[v].append((u, w))

    visited = [False] * (n + 1)
    distance, node = dfs(1, graph, visited)
    visited = [False] * (n + 1)
    diameter, _ = dfs(node, graph, visited)

    return diameter

# Input reading
n = int(input())
edges = []

for _ in range(n - 1):
    u, v, w = map(int, input().split())
    edges.append((u, v, w))

# Calculating the diameter of the tree
print(diameter_of_tree(n, edges))