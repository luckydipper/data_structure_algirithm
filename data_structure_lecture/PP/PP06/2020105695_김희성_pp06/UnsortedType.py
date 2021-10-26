class NodeType:
    """ Node Type """
    def __init__(self, item):
        self.info = item
        self.next = None

class UnsortedType:
    def __init__(self):
        self.listData = None
        self.length = 0
        self.currentPos = None

    def is_full(self):
        try:
            location = NodeType("test")
            return False
        except:
            return True

    def length_is(self):
        return self.length

    def make_empty(self):
        while self.listData != None:
            tempPtr = self.listData.next
            del self.listData
            self.listData = tempPtr
        self.length = 0

    def retrieve_item(self, item):
        location = self.listData
        found = False
        moreToSearch = location != None

        while moreToSearch and not found:
            if item == location.info:
                found = True
            else:
                location = location.next
                moreToSearch = location != None
        return found

    def insert_item(self, item):
        inserted_item = NodeType(item)

        if(self.length == 0):
            self.listData = inserted_item
            self.length += 1
        else:
            iterator = self.listData
            while(iterator.next != None):
                iterator = iterator.next
            iterator.next = inserted_item
            self.length += 1


    def delete_item(self, item):

        if(self.length == 0):
            return

        iterator = self.listData

        if(iterator.info == item):
            self.listData = self.listData.next
            self.length -=1
        
        while(iterator.next != None):
            if(iterator.next.info == item):
                iterator.next = iterator.next.next
                self.length -=1
            iterator = iterator.next


    def reset_list(self):
        self.currentPos = None

    def get_next_item(self):
        if self.currentPos == None:
            self.currentPos = self.listData
        else:
            self.currentPos = self.currentPos.next
        return self.currentPos.info

    def __str__(self):
        self.reset_list()
        items = []
        for i in range(0, self.length):
            t = self.get_next_item()
            items.append(str(t))
        return " ".join(items)
