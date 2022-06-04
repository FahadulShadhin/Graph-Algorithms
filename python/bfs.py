from graph import Graph

# Breadth-first serch algorithm 
def bfs(graph, source):
    visited = set()
    bfs_traversal = list()
    queue = list()

    queue.append(source)
    visited.add(source)
    
    while queue:
        # print(f"current queue: {queue}")
        current_node = queue.pop(0)
        bfs_traversal.append(current_node)

        for neighbour_node in graph[current_node]:
            if neighbour_node not in visited:
                visited.add(neighbour_node)
                queue.append(neighbour_node)

    return bfs_traversal


def main():
    g = Graph()

    """
    g.addEdge('A', 'B')
    g.addEdge('A', 'C')
    g.addEdge('B', 'D')
    g.addEdge('B', 'E')
    g.addEdge('C', 'D')
    g.addEdge('D', 'A')
    g.addEdge('D', 'E')
    """

    g.addEdge('A', 'B')
    g.addEdge('A', 'C')
    g.addEdge('B', 'D')
    g.addEdge('B', 'E')
    g.addEdge('C', 'F')
    g.addEdge('C', 'G')

    # g.printGraph()

    graph = g.getGraph()
    # print(graph)

    bfs_traversal = bfs(graph, 'C')
    print(f"BFS: {bfs_traversal}")

    
if __name__=='__main__':
    main()