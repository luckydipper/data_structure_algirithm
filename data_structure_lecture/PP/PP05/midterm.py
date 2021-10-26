class CircularQueue():
    def __init__(self, size=None):
        if size == None:
            size = 5
            self.max_que = size + 1         
        else:
            self.max_que = size + 1
        self.items = [0] * (self.max_que)
        self.front = self.max_que-1
        self.rear = self.max_que-1
 

    def make_empty(self):
        self.items = [ ]
        self.front = self.max_que-1
        self.rear = self.max_que-1
   

    def is_empty(self):
        return (self.rear == self.front)
 

    def is_full(self):
        return ((self.rear + 1) % self.max_que == self.front)
   

    def enqueue(self, newItem):
        if self.is_full():
            print("Queue is Full")
        else:
            self.rear = (self.rear + 1) % self.max_que
            self.items[self.rear] = newItem
 

    def dequeue(self):
        if self.is_empty():
            print("Queue is Empty")
        else:
            self.front = (self.front + 1) % self.max_que
            return self.items[self.front]

    def __str__(self):
            print_items = []
            if self.front < self.rear:
                for idx in range(self.front+1, self.rear+1):
                    print_items.append(self.items[idx])
            else:
                for idx in range(self.front+1,self.max_que):
                    print_items.append(self.items[idx])
                for idx in range(0, self.rear+1):
                    print_items.append(self.items[idx])
            return str(print_items).replace(',', ' ')


if __name__ == '__main__':
    q = CircularQueue()
   

    q.enqueue(1)
    q.enqueue(3)
    q.enqueue(5)
    q.enqueue(7)
    q.enqueue(9)
    print(q)
 

    q.dequeue()
    q.dequeue()
    q.dequeue()
    print(q)
 

    q.enqueue(2)
    q.enqueue(4)
    print(q)