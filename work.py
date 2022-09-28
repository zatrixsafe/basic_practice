
import sys

class Graph():
    def __init__(self, N):
        self.size = N
        self.adj = [[] for _ in range(N)]
        self.visited = set()
        self.can_find = False

    def add_adge(self, x, y):
        self.adj[x].append(y)
        self.adj[y].append(x)
    
    def find(self, x, y, z):
        # DFS找x到y的所有路径，只要z在路径上就认为是可以到达的
        self.visited.add(x)
        for node in self.adj[x]:
            if node == y:
                if z in self.visited:
                    self.can_find = True
                #self.visited.remove(x)
            if node not in self.visited:
                self.find(node, y, z)
        self.visited.remove(x)



if __name__ == '__main__':
        N = int(input("Node size: "))
        
        d = Graph(N)

        while N > 0:
            raw_input = input()
            r = raw_input.split(" ")
            a, b = int(r[0]), int(r[1])
            d.add_adge(a, b)
            N -= 1
        
        M = int(input("Question size: "))

        while M > 0:
            raw_input = input()
            r = raw_input.split(" ")
            a, b, c = int(r[0]), int(r[1]), int(r[2])
            # 每次查询都需要重新DFS
            d.visited = set()
            d.can_find = False
            d.find(a, b, c)
            print(d.can_find)
            M -= 1




