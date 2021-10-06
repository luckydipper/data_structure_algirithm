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
        if (self.value > otherItem.value):
            return Compare.GREATER
        elif (self.value < otherItem.value):
            return Compare.LESS
        else:
            return Compare.EQUAL
    
    def __str__(self):
        return str(self.value)

class SortedType:
    """ Chapter 3: Sorted List """

    def __init__(self):
        self.info = []
        self.length = 0

    def make_empty(self):
        self.length = 0

    def length_is(self):
        return self.length

    def is_full(self):
        if self.length == MAX_ITEMS:
            return True
        return False

    def insert_item(self, item): 

        # self.length!=0
        for i, element in enumerate(self.info):
            # compared_to 보다 가독성이 좋을것 같아 직접 접근함
            if(element.value >= item.value): 
                self.info.insert(i,item)
                self.length += 1
                return

        # self.length==0
        self.info.append(item)
        self.length += 1
        return

    def retrieve_item(self, item): # Binary Search
        first = 0
        last = self.length
        while(first<=last):
            middle = int((first+last)/2)
            if(self.info[middle].value == item.value):
                return True
            elif(self.info[middle].value < item.value):
                first = middle + 1
            elif(self.info[middle].value > item.value):
                last = middle -1
        return False

    def delete_item(self, item):
        # 중복이 없다고 가정함.
        for i, elem in enumerate(self.info):
            if (elem.value == item.value):
                self.info.remove(self.info[i])#remove 쓰면 array에서 완전히 제거.
                self.length -= 1

    def reset_list(self):
        self.current_pos = -1

    def get_next_item(self):
        self.current_pos += 1
        return self.info[self.current_pos]

    def __str__(self):
        return str([item_.value for item_ in self.info])