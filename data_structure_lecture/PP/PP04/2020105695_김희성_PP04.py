MAX_ITEMS = 100

class StackType:
    def __init__(self):
        #lenght과 같은 attribute이 없어도 내부 함수로 구현 가능 
        self.info = []

    def is_empty(self):
        if(len(self.info) == 0):
            return True
        else:
            return False
        
    def is_full(self):
        if(len(self.info) < MAX_ITEMS):
            return False
        else:
            return True
        
    def push(self, item):
        self.info.append(item)

    def pop(self):
        if(self.is_full()):
            return "Stack is full"
        return self.info.pop()

    def top(self):
        if(self.is_empty()):
            return "Stack is Empty"
        return self.info[-1]