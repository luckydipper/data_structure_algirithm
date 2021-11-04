class NodeType:
    """ Node Type """
    def __init__(self, item):
        self.info = item
        self.next = None
        self.back = None

class DoublyLL:
    def __init__(self):
        self.head = NodeType('head')
    
    def find_item(self, item):
        iterator = self.head
        while(iterator != None):
            if(iterator.info == item):
                return iterator
            iterator = iterator.next
    
    def insert_item(self, item, new):
        #item 뒤에 new 붙이란 뜻으로 이해했습니다. 
        #맨 앞엔 붙지 않습니다.
        append_location = self.find_item(item)
        new_node = NodeType(new)
        
        #마지막에 연결 
        if(append_location.next == None):
            new_node.back = append_location
            append_location.next = new_node
        else:
            new_node.back = append_location
            new_node.front = append_location.next
            append_location.front.back = new_node
            append_location.front = new_node
        
        

    def delete_item(self, item):
        iterator = self.head
        while(iterator != None):
            if(iterator.info == item):
                iterator.back.next = iterator.next
                iterator.next.back = iterator.back
            iterator = iterator.next
            
    def __str__(self):
        cur_node = self.head
        items = []
        while cur_node is not None:
            items.append("(" + str(cur_node.info) + ")\n")
            cur_node = cur_node.next
        return "".join(items)

