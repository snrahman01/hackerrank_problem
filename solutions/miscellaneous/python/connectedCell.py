class ConnectedGrid:
    def __init__(self, row, col):
        self.range = (row+2)*(col+2)
        self.m = row
        self.n = col
        self.parent = [-1] * (self.range)
        for i in range(self.range):
            self.parent[i] = i
        self.sz = [1]*(self.range)
        self.grid = []

    def find_parent(self,  i):
        while self.parent[i] != i:
            self.parent[i] = self.parent[self.parent[i]]
            i = self.parent[i]
        return i

    def union(self, x, y):
        x_set = self.find_parent(x)
        y_set = self.find_parent(y)
        if self.sz[x_set] < self.sz[y_set]:
            self.parent[x_set] = y_set
            self.sz[y_set] += self.sz[x_set]
        else:
            self.parent[y_set] = x_set
            self.sz[x_set] += self.sz[y_set]

    def getIndex(self, i, j):
        return (i*(self.n+2))+j

    def isConnected(self, i, j):
        return self.find_parent(i) == self.find_parent(j)

    def connect(self, i, j):
        if self.grid[i - 1][j - 1] == 1 and self.isConnected(self.getIndex(i,j), self.getIndex(i-1, j-1)) == False :
            self.union(self.getIndex(i,j), self.getIndex(i-1, j-1))
        if self.grid[i + 1][j + 1] == 1 and  self.isConnected(self.getIndex(i,j), self.getIndex(i+1, j+1)) == False :
            self.union(self.getIndex(i,j), self.getIndex(i+1, j+1))
        if self.grid[i - 1][j + 1] == 1 and  self.isConnected(self.getIndex(i,j), self.getIndex(i-1, j+1)) == False :
            self.union(self.getIndex(i,j), self.getIndex(i-1, j+1))
        if self.grid[i + 1][j - 1] == 1 and  self.isConnected(self.getIndex(i,j), self.getIndex(i+1, j-1)) == False :
            self.union(self.getIndex(i,j), self.getIndex(i+1, j-1))
        if self.grid[i - 1][j] == 1 and  self.isConnected(self.getIndex(i,j), self.getIndex(i-1, j)) == False :
            self.union(self.getIndex(i,j), self.getIndex(i-1, j))
        if self.grid[i + 1][j] == 1 and  self.isConnected(self.getIndex(i,j), self.getIndex(i+1, j)) == False :
            self.union(self.getIndex(i,j), self.getIndex(i+1, j))
        if self.grid[i][j - 1] == 1 and  self.isConnected(self.getIndex(i,j), self.getIndex(i, j-1)) == False :
            self.union(self.getIndex(i,j), self.getIndex(i, j-1))
        if self.grid[i][j + 1] == 1 and  self.isConnected(self.getIndex(i,j), self.getIndex(i, j+1)) == False :
            self.union(self.getIndex(i,j), self.getIndex(i, j+1))

    def createCells(self, lst):
        for i in range(self.m+2):
            a = []
            for j in range(self.n+2):
                if i == 0 or j == 0 or i == self.m+1 or j == self.n+1:
                    a.append(0)
                else:
                    a.append(lst[i-1][j-1])
            self.grid.append(a)

        for i in range(1, self.m+1):
            for j in range(1, self.n+1):
                if self.grid[i][j] == 1:
                    self.connect(i, j)
    def getMaxRegion(self):
        return max(self.sz)


m, n = 4, 4
l = [[1, 1, 0, 0],[0, 1, 1, 0],[0, 0, 1, 0],[1, 0, 0, 0]]

g = ConnectedGrid(m, n)
g.createCells(l)
s = g.isConnected(14, 15)
print(g.getMaxRegion())

