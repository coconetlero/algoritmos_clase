class Vertex(object):

    def __init__(self, name):
        self.name = name
        self.adjacent = {}
    
    def __str__(self):
        return str(self.name) + "->" + str([x.name for x in self.adjacent])
    
    def add_neighbor(self, vertex, edge_weight):
        self.adjacent[vertex] = edge_weight


class Graph(object):
    
    def __init__(self):
        self.nodes = {}

    def add_vertex(self, name):
        self.nodes[name] = Vertex(name)

    def add_edge(self, from_node, to_node, edge_weight):
        v1 = self.nodes[from_node]
        v2 = self.nodes[to_node]
        v1.add_neighbor(v2, edge_weight)
        
    def get_vertexes(self):
        return nodes
        
if __name__ == '__main__':

    g = Graph()
    g.add_vertex('0')
    g.add_vertex('1')
    g.add_vertex('2')
    g.add_vertex('3')
    g.add_vertex('4')
    g.add_vertex('5')
    g.add_vertex('6')
    g.add_vertex('7')

    g.add_edge('0', '1', 5)
    g.add_edge('0', '7', 8)
    g.add_edge('0', '4', 9)
    g.add_edge('1', '3', 15)
    g.add_edge('1', '7', 4)
    g.add_edge('1', '2', 2)
    g.add_edge('2', '3', 3)
    g.add_edge('2', '6', 11)
    g.add_edge('3', '6', 9)
    g.add_edge('4', '6', 20)
    g.add_edge('4', '5', 4)
    g.add_edge('4', '7', 5)
    g.add_edge('5', '6', 13)
    g.add_edge('5', '2', 1)
    g.add_edge('7', '2', 7)
    g.add_edge('7', '6', 5)
    
    print(g.nodes['0'])
    print(g.nodes['6'])   