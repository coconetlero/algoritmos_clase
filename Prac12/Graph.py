class Vertex:
    def __init__(self, node):
        self.id = node
        self.adjacent = {}

    def __str__(self):
        return str(self.id) + ' adjacent: ' + str([x.id for x in self.adjacent])

    def add_neighbor(self, neighbor, weight=0):
        self.adjacent[neighbor] = weight

    def get_connections(self):
        return self.adjacent.keys()

    def get_weight(self, neighbor):
        return self.adjacent[neighbor]

    def get_id(self):
        return self.id


class Graph:
    def __init__(self):
        self.vert_dict = {}
        self.num_vertices = 0

    def __iter__(self):
        return iter(self.vert_dict.values())

    def add_vertex(self, node):
        self.num_vertices = self.num_vertices + 1
        new_vertex = Vertex(node)
        self.vert_dict[node] = new_vertex
        return new_vertex

    def get_vertex(self, n):
        if n in self.vert_dict:
            return self.vert_dict[n]
        else:
            return None

    def add_edge(self, frm, to, cost=0):
        if frm not in self.vert_dict:
            self.add_vertex(frm)
        if to not in self.vert_dict:
            self.add_vertex(to)

        self.vert_dict[frm].add_neighbor(self.vert_dict[to], cost)
        self.vert_dict[to].add_neighbor(self.vert_dict[frm], cost)

    def get_vertices(self):
        return self.vert_dict.keys()

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

    for v in g:
        for w in v.get_connections():
            vid = v.get_id()
            wid = w.get_id()
            print(vid, wid, v.get_weight(w))

    for v in g:
        print(v.get_id(), g.vert_dict[v.get_id()])
