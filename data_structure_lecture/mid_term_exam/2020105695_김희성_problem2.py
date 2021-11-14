class NodeType:
    """ Node Type """
    def __init__(self, _name, _id):
        self.name = _name
        self.id = _id
        self.next = None

class SortedType:
    def __init__(self):
        self.listData = None
        self.length = 0
        self.currentPos = None

    def length_is(self):
        return self.length

    def reset_list(self):
        self.currentPos = None

    def get_next_item(self):
        if self.currentPos == None:
            self.currentPos = self.listData
        name, id = self.currentPos.name, self.currentPos.id
        self.currentPos = self.currentPos.next

        return name, id

    def __str__(self):
        self.reset_list()
        items = []
        for i in range(0, self.length):
            name, id = self.get_next_item()
            items.append("(" +name + ", " + str(id) + ")\n")
        return "".join(items)

    def insert_item(self, name, id):
        added_node = NodeType(name,id)
        self.length += 1

        if(self.length == 1):
            self.listData = added_node
        
        #처음 node 앞에 붙힐 수 있는지 check.
        else:
            if(added_node.name < self.listData.name):
                added_node.next = self.listData
                self.listData = added_node
                return
            elif(added_node.name == self.listData.name):
                if(added_node.id < self.listData.id):
                    added_node.next = self.listData
                    self.listData = added_node
                    return

            #처음 노드 뒤에 붙히기
            iterator = self.listData
            while(iterator.next!=None):
                if(added_node.name < iterator.next.name):
                    added_node.next = iterator.next
                    iterator.next = added_node
                    return
                elif(added_node.name == iterator.next.name):
                    if(added_node.id < iterator.next.id):
                        added_node.next = iterator.next
                        iterator.next = added_node
                        return
                    else:
                        added_node.next = iterator.next.next
                        iterator.next.next = added_node
                        return
                iterator = iterator.next
            iterator.next = added_node
                    
        


