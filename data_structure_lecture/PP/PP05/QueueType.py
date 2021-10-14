MAX_ITEMS = 100

class QueueType():
    def __init__(self):
        self.info = []

    def enqueue(self, data):
        self.info.append(data)

    def dequeue(self):
        result = self.info[0]
        del self.info[0]
        return result

    def is_empty(self):
        if(len(self.info) == 0):
            return True
        else:
            return False

    def is_full(self):
        if(len(self.info) >=MAX_ITEMS):
            return True
        else:
            return False

    def make_empty(self):
        self.info = []