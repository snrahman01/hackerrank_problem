from collections import defaultdict

class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = []
        self.parent = [-1] * (self.V)
        for i in range(self.V):
            self.parent[i] = i
        self.sz = [1]*(self.V)

    def addEdge(self, u, v, w):
        self.graph.append([u, v, w])

    def find_parent(self,  i):
        if self.parent[i] == i:
            return i
        return self.find_parent(self.parent[i])

    def union(self, x, y):
        x_set = self.find_parent(x)
        y_set = self.find_parent(y)
        if self.sz[x_set] < self.sz[y_set]:
            self.parent[x_set] = y_set
            self.sz[y_set] += self.sz[x_set]
        else:
            self.parent[y_set] = x_set
            self.sz[x_set] += self.sz[y_set]

    def kruskals(self, g_nodes, edges):

        result = []
        i = 0
        e = 0

        for k,l,w in edges:
            self.addEdge(k-1, l-1, w)


        self.graph = sorted(self.graph, key=lambda item: item[2])

        while e < self.V - 1:
            u, v, w = self.graph[i]
            i = i + 1
            x = self.find_parent(u)
            y = self.find_parent(v)
            if x != y:
                self.union(x, y)
                e = e + 1
                result.append([u, v, w])

        print("Following are the edges in the constructed MST")
        sum = 0;
        for u, v, weight in result:
            sum += weight
        return sum

g = Graph(4)
v1 = [1,1,4,2,3,3]
v2 = [2,3,1,4,2,4]
w = [5,3,6,7,4,5]
print(g.kruskals(4, v1, v2, w))

