class Node:
    def __init__(self, info): 
        self.info = info  
        self.left = None  
        self.right = None 
        self.level = None 

    def __str__(self):
        return str(self.info) 

class BinarySearchTree:
    def __init__(self): 
        self.root = None

    def create(self, val):  
        if self.root == None:
            self.root = Node(val)
        else:
            current = self.root
         
            while True:
                if val < current.info:
                    if current.left:
                        current = current.left
                    else:
                        current.left = Node(val)
                        break
                elif val > current.info:
                    if current.right:
                        current = current.right
                    else:
                        current.right = Node(val)
                        break
                else:
                    break

# Enter your code here. Read input from STDIN. Print output to STDOUT
'''
class Node:
      def __init__(self,info): 
          self.info = info  
          self.left = None  
          self.right = None 
           

       // this is a node of the tree , which contains info as data, left , right
'''

def lca(root, v1, v2):
    #Enter your code here
    pathToV1 = getPath(root, v1)
    pathToV2 = getPath(root, v2)

    if(len(pathToV1) > len(pathToV2)):
        return findAncestor(pathToV1, pathToV2)
    else:
        return findAncestor(pathToV2, pathToV1)


def findAncestor(longPath, shortPath):
    for i in range(0, len(shortPath)):
        if(shortPath[i] != longPath[i]):
            return shortPath[i-1]
    return shortPath[len(shortPath) - 1]

def getPath(n, val):
    path = []
    path.append(n)
    while n.info != val:
        if(n.info > val):
            n = n.left
        else:
            n = n.right
        path.append(n)
    return path


tree = BinarySearchTree()
t = int(input())

arr = list(map(int, input().split()))

for i in range(t):
    tree.create(arr[i])

v = list(map(int, input().split()))

ans = lca(tree.root, v[0], v[1])
print (ans.info)
