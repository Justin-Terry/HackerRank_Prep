class MyQueue(object):

    def __init__(self):
        self.enStack = []
        self.deStack = []        
    
    def peek(self):
        if not self.deStack:
            while self.enStack:
                self.deStack.append(self.enStack.pop())
        return self.deStack[-1]
        
    def pop(self):
        if not self.deStack:
            while self.enStack:
                self.deStack.append(self.enStack.pop())
        return self.deStack.pop()
        
    def put(self, value):
        self.enStack.append(value)
        
queue = MyQueue()
t = int(input())
for line in range(t):
    values = map(int, input().split())
    values = list(values)
    if values[0] == 1:
        queue.put(values[1])        
    elif values[0] == 2:
        queue.pop()
    else:
        print(queue.peek())

