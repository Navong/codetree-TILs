from collections import defaultdict

def find_diameter(n, edges):
  """
  Finds the diameter of a tree using depth-first search.

  Args:
      n: The number of vertices in the tree.
      edges: A list of tuples where each tuple represents an edge (vertex1, vertex2, distance).

  Returns:
      The diameter of the tree.
  """
  # Create an adjacency list representation of the tree
  graph = defaultdict(list)
  for u, v, dist in edges:
    graph[u].append((v, dist))
    graph[v].append((u, dist))

  # Perform depth-first search from any vertex
  max_dist, farthest_node = dfs(graph, 1, 0, None)

  # Perform another DFS from the farthest node found in the first DFS
  diameter = dfs(graph, farthest_node, 0, farthest_node)[0]
  return diameter

def dfs(graph, node, current_dist, parent):
  """
  Performs depth-first search on a tree and returns the maximum distance and farthest node from the starting node.

  Args:
      graph: The adjacency list representation of the tree.
      node: The current node being visited.
      current_dist: The current distance from the starting node.
      parent: The parent node of the current node.

  Returns:
      A tuple containing the maximum distance and the farthest node found.
  """
  max_dist_from_here = current_dist
  farthest_node_from_here = node

  for neighbor, dist in graph[node]:
    if neighbor != parent:
      child_dist, child_farthest = dfs(graph, neighbor, current_dist + dist, node)
      if child_dist > max_dist_from_here:
        max_dist_from_here = child_dist
        farthest_node_from_here = child_farthest

  return max_dist_from_here, farthest_node_from_here

# Read input
n = int(input())
edges = []
for _ in range(n - 1):
  u, v, dist = map(int, input().split())
  edges.append((u, v, dist))

# Find and print the diameter
diameter = find_diameter(n, edges)
print(diameter)