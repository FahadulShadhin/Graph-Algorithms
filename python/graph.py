class Graph:
    def __init__(self):
        self.graph = dict()

    def addEdge(self, node1, node2):
        if node1 not in self.graph:
            self.graph[node1] = []
        if node2 not in self.graph:
            self.graph[node2] = []

        self.graph[node1].append(node2)
        self.graph[node2].append(node1)

    
    def getGraph(self):
        return self.graph


    def printGraph(self):
        for source, destination in self.graph.items():
            print(f"{source}-->{destination}")