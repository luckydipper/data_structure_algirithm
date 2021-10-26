class NodeType:
    """ Node Type """
    def __init__(self, item):
        self.info = item
        self.next = None

class QueType:
    def __init__(self):
        self.front = None
        self.rear = None

    def make_empty(self):
        while self.front != None:
            tempPtr = self.front
            self.front = self.front.next
            del tempPtr
        self.rear = None

    def is_full(self):
        try:
            location = NodeType("test")
            del location
            return False
        except:
            return True

    def is_empty(self):
        return self.front == None

    def enqueue(self, item):
        if(self.front == None and self.rear == None):
            self.front = NodeType(item) #포인터가 없는데 같은 객체를 어떻게 가르키냐.
        elif(self.front != None and self.rear == None):
            self.rear=NodeType(item)
            self.front.next = self.rear
        else:
            self.rear.next = NodeType(item)
            self.rear = self.rear.next

    def dequeue(self):
        if(self.front == None):
           return
        front_val = self.front
        self.front = self.front.next
        return front_val.info

        
