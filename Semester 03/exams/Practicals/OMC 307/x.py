def dfs_tree(graph, node, visited=None, level=0, is_last=True, prefix=""):
    if visited is None:
        visited = set()

    # Mark the current node as visited
    visited.add(node)

    # Print the node with proper tree structure symbols
    connector = "└── " if is_last else "├── "
    print(prefix + connector + node)

    # Update the prefix for children
    new_prefix = prefix + ("    " if is_last else "│   ")

    # Get neighbors and iterate
    neighbors = graph.get(node, [])
    for i, neighbor in enumerate(neighbors):
        if neighbor not in visited:
            dfs_tree(graph, neighbor, visited, level + 1, i == len(neighbors) - 1, new_prefix)

# Define the graph as an adjacency list
graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': ['F'],
    'F': []
}

# Perform DFS and print the graph as a directory tree
print("Graph as a Tree:")
dfs_tree(graph, 'A')
