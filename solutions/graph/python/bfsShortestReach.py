from collections import defaultdict

class Graph:

    def __init__(self):
        self.graph = defaultdict(list)
    def addEdge(self, u, v):
        self.graph[u].append(v)
        self.graph[v].append(u)

    def bfs(self, n, edges, u):

        for m, k in edges:
            self.addEdge(m-1, k-1)

        queue = []
        queue.append(u-1)
        visitWt = [-1]*n
        visitWt[u-1] = 0

        while queue:
            s = queue.pop(0)
            for i in self.graph[s]:
                if visitWt[i] == -1:
                    queue.append(i)
                    visitWt[i] = 6+visitWt[s]

        visitWt.remove(visitWt[u-1])
        return  visitWt

if __name__ == '__main__':
    fptr = open("F:/out.txt", 'w')
    f1 = open("F:/tst.txt", 'r')

    q = int(f1.readline())

    for q_itr in range(q):
        nm = f1.readline().split()

        n = int(nm[0])

        m = int(nm[1])

        edges = []

        for _ in range(m):
            edges.append(list(map(int, f1.readline().rstrip().split())))

        s = int(f1.readline())
        g = Graph()
        result = g.bfs(n, edges, s)

        fptr.write(' '.join(map(str, result)))
        fptr.write('\n')

    fptr.close()
    f1.close()
