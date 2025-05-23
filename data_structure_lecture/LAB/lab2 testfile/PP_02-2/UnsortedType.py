from enum import Enum

MAX_ITEMS = 100

class Compare(Enum):
    LESS = 0
    GREATER = 1
    EQUAL = 2

class ItemType:
    """ Item Type """

    def __init__(self, val):
        self.value = val

    def compared_to(self, otherItem):
        if (self.value < otherItem.value): #''' [1] '''
            return Compare.LESS
        elif (self.value > otherItem.value): #''' [2] '''
            return Compare.GREATER
        return Compare.EQUAL 

    def __str__(self):
        return str(self.value)

class UnsortedType:
    """ Chapter 3: Unsorted List """

    def __init__(self):
        self.length = 0
        self.info = []
        self.current_pos = -1

    def make_empty(self):
        self.length = 0

    def length_is(self):
        return self.length

    def is_full(self):
        if self.length == MAX_ITEMS:
            return True
        return False

    def insert_item(self, item):
        self.info.append(item)
        self.length += 1

    def retrieve_item(self, item):
        for elem in self.info:
            if(elem.value == item.value):
                return True
        #''' [3] '''

    def delete_item(self, item):
        for i, elem in enumerate(self.info):
            if elem.value == item.value:
                self.info[i] = self.info[self.length-1]
                self.length -= 1
                return self.delete_item(item)
        #''' [4] '''

    def reset_list(self):
        self.current_pos = -1

    def get_next_item(self):
        self.current_pos += 1
        return self.info[self.current_pos]

    def __str__(self):
        self.reset_list()
        
        print_list = []
        for i in range(self.length):
            print_list.append(str(self.get_next_item()))
        
        return str(" ".join(print_list))