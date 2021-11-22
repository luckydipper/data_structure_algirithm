class TreeNode:

    def __init__(self, info):
        self.info = info
        self.left = None
        self.right = None
    
class BST():

    def __init__(self):
        self.root = None
        self.order_list = []
    
    def is_empty(self):
        return (self.root == None)
    
    def count_nodes(self, tree):
        if(tree==None):
            return 0
        return self.count_nodes(tree.right) + self.count_nodes(tree.left) + 1
        
    def length_is(self):
        return self.count_nodes(self.root)

    def insert(self, item):
        find_node = TreeNode(item)
        if(self.root == None):
            self.root = find_node
            return
        self.insert_item(self.root, find_node)

    # node return
    def insert_item(self, node, item):# call by reference가 안 돼서... ? 
        if(node.right == None  and  item.info >= node.info):
            node.right = item
        elif(node.left == None  and item.info < node.info):
            node.left = item
        elif(node.info <= item.info):
            self.insert_item(node.right, item)
        elif(node.info > item.info):
            self.insert_item(node.left, item)
        
        
        
            
        

    def inorder(self, node):
        if(node == None):
            return 
        self.inorder(node.left)
        self.order_list.append(node.info)
        self.inorder(node.right)
    
    def preorder(self, node):
        if(node == None):
            return 
        self.order_list.append(node.info)
        self.preorder(node.left)
        self.preorder(node.right)

    
    def postorder(self, node):
        if(node == None):
            return 
        self.postorder(node.left)
        self.postorder(node.right)
        self.order_list.append(node.info)

    def delete(self, item):
        self.delete_node(self.root, item)
    
    def delete_node(self, current, item):
        # pointer도 없고, 함수에서 받은 parameter 바꾸면, call by reference도 안 된다.
        # python에서는 새로운 객체를 만드는 것이 파이썬스러울 것 같다... 
        # parent node까지 찾아서 구현하는 것 보다는 전체를 복사하는게 이득일 수 있다.
        self.preorder(current)
        
        deleted_bst = BST()
        for node_info in self.order_list:
            if(node_info != item):
                deleted_bst.insert(node_info)
        
        self.root = deleted_bst.root
        self.order_list.clear()
        
        # if current is None:
        #     return current
        
        # if item < current.info:
        #     current.right = self.delete_node(current.left, item)
            
        # elif(item > current.info):
        #     current.right = self.delete_node(current.right, item)
        
        # else:
        #     if current.left is None:
        #         temp = current.right
        #         root = None
        #         return temp

        #     elif current.right is None:
        #         temp = current.left
        #         root = None
        #         return temp
        
        #     temp = self.get_predecessor(current.right)
        #     # Copy the inorder successor's
        #     # content to this node
        #     current.key = temp.key

        #    # Delete the inorder successor
        #     current.right = self.delete_node(current.right, temp.key)
        
            
    #이 함수를 써서 delete node를 찾는다 한들, parent node까지 찾아야 한다.
    def get_predecessor(self, tree, data):
        current = tree
 
    # loop down to find the leftmost leaf
        while(current.left is not None):
            current = current.left
 
        return current

        
