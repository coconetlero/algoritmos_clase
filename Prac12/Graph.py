class Vertex(object):

    def __init__(self, name):
        self.name = name
        self.adjacent = {}

    def __str__(self):
        return str(self.name) + "->" + str([x.name for x in self.adjacent])

    def add_neighbor(self, vertex, edge_weight):
        self.adjacent[vertex] = edge_weight

    def get_neighbors(self):
        return self.adjacent


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
        return self.nodes



if __name__ == '__main__':

    def Dijksrta(Graph, source, target):
        # creamos 
        Q = []
        dist = {}
        prev = {}

        # Sea V el conjunto de vertices de la grafica
        V = Graph.get_vertexes()

        # Para cada uno de los vertices "v" de la grafica inicializamos dist y prev
        # e ingresamos v a la lista Q.
        for name, v in V.items():
            dist[v.name] = float("inf")
            prev[v.name] = None
            Q.append(v)

        dist[source.name] = 0

        while len(Q) > 0:
            # print(dist)

            # obtenemos el vertice con menor valor de dist
            temp_dist = float("inf")
            temp_vertex = None

            for v in Q:
                # print(v.name, end=" ")

                if dist[v.name] < temp_dist:
                    temp_dist = dist[v.name]
                    temp_vertex = v.name

            # print()
            idx = Q.index(V[temp_vertex])
            u = Q.pop(idx)
            # print(u, "\n")

            # los vecinos de u
            neighbors = u.get_neighbors()

            # for v in neighbors:
            #     print("v = ", v, "dist to ", v.name, "is", neighbors[v])

            # para cada uno de los vecinos de u
            for v in neighbors:
                alt = dist[u.name] + neighbors[v]
                if alt < dist[v.name]:
                    dist[v.name] = alt
                    prev[v.name] = u

        return prev

    # end dijkstra

    # construimos una grafica
    g = Graph()

    # aniadimos los vertices
    g.add_vertex('0')
    g.add_vertex('1')
    g.add_vertex('2')
    g.add_vertex('3')
    g.add_vertex('4')
    g.add_vertex('5')
    g.add_vertex('6')
    g.add_vertex('7')

    # agregamos las aristas
    g.add_edge('0', '1', 5)
    g.add_edge('0', '7', 8)
    g.add_edge('0', '4', 9)
    g.add_edge('1', '3', 15)
    g.add_edge('1', '7', 4)
    g.add_edge('1', '2', 12)
    g.add_edge('2', '3', 3)
    g.add_edge('2', '6', 11)
    g.add_edge('3', '6', 9)
    g.add_edge('4', '6', 20)
    g.add_edge('4', '5', 4)
    g.add_edge('4', '7', 5)
    g.add_edge('5', '6', 13)
    g.add_edge('5', '2', 1)
    g.add_edge('7', '2', 7)
    g.add_edge('7', '5', 6)

    print("--------------- vertex 0 nad vertex 6 ----------------")
    print(g.nodes['0'])
    print(g.nodes['6'])
    print("--------------- Graph ----------------")
    # recorrer todos los vertices de la grafica G
    N = g.get_vertexes()
    for name, vertex in N.items():
        print(vertex)

    # llamada a la función Dijkstra con la grafica que acabamos de crear
    print("--------------- Dijkstra ----------------")
    prev = Dijksrta(g, g.nodes['0'], g.nodes['6'])

    for name, vertex in prev.items():
        if vertex is not None:
            print(name, "<-", vertex.name)
