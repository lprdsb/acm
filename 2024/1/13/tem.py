class Node:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    @staticmethod
    def fun():
        tem = Node(1, 2)
        print(tem.x)

tem = Node(2, 3)
tem.fun()