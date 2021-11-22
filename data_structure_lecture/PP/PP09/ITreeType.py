
from TreeType import TreeNode


class NodeType:
    def __init__(self, data):
        self.info = data
        self.left = None
        self.right = None

class IterBST():
    def __init__(self):
        self.root = None
        self.order_list = []

    def insert(self, data):
        node = TreeNode(data)
        
        if(self.root == None):
            self.root = node
            return
        
        iterator = self.root
        while(True):
            if(iterator.right == None and iterator.info < node.info):
                iterator.right = node
                break
            elif(iterator.left == None and iterator.info >= node.info):
                iterator.left = node
                break
            elif(iterator.info < node.info):
                parent = iterator
                iterator = iterator.right
            else:
                parent = iterator
                iterator = iterator.left
                
            
            

    def find(self, key):
        self.find_node(self.root, key)

    def find_node(self, root, key):
        
        iterator = root
        while(True):
            if(iterator == None):
                return False
            elif(iterator.info == key):
                return True
            elif(iterator.info < key):
                iterator = iterator.right
            elif(iterator.info > key):
                iterator = iterator.left
            

    def delete(self, key):
        self.delete_node(self.root, key)

    def delete_node(self, node, key):
        curr = node
        prev = None
    
        # First check if the key is
        # actually present in the BST.
        # the variable prev points to the
        # parent of the key to be deleted
        while(curr != None and curr.info != key):
            prev = curr
            if curr.info < key:
                curr = curr.right
            else:
                curr = curr.left
    
        if curr == None:
            print("Key % d not found in\
               the provided BST." % key)
            return node
    
        # Check if the node to be
        # deleted has atmost one child
        if curr.left == None or\
                curr.right == None:
    
            # newCurr will replace
            # the node to be deleted.
            newCurr = None
    
            # if the left child does not exist.
            if curr.left == None:
                newCurr = curr.right
            else:
                newCurr = curr.left
    
            # check if the node to
            # be deleted is the node.
            if prev == None:
                return newCurr
    
            # Check if the node to be
            # deleted is prev's left or
            # right child and then
            # replace this with newCurr
            if curr == prev.left:
                prev.left = newCurr
            else:
                prev.right = newCurr
    
            curr = None
    
        # node to be deleted
        # has two children.
        else:
            p = None
            temp = None
    
            # Compute the inorder
            # successor of curr.
            temp = curr.right
            while(temp.left != None):
                p = temp
                temp = temp.left
    
            # check if the parent of the
            # inorder successor is the node or not.
            # if it isn't, then make the left
            # child of its parent equal to the
            # inorder successor's right child.
            if p != None:
                p.left = temp.right
    
            else:
            
                # if the inorder successor was
                # the node, then make the right child
                # of the node to be deleted equal
                # to the right child of the inorder
                # successor.
                curr.right = temp.right
    
            curr.info = temp.info
            temp = None
    
        return node


    def inorder(self, node):
        current = self.root
        stack = []
        while(True):
            if current is not None:
                stack.append(current)
                current = current.left
            elif(len(stack) != 0):#element 있을 때 까지
                current = stack.pop()
                self.order_list.append(current.info)
                current = current.right
            else:
                break
    
    def preorder(self, node):
        current = self.root
        stack = []
        while(True):
            if current is not None:
                stack.append(current)
                self.order_list.append(current.info)
                current = current.left
            elif(len(stack) != 0) :#element 있을 때 까지
                current = stack.pop()
                current = current.right
            else:
                break
    
    def postorder(self, node):
        stack = []
        root = self.root
        while(True):
            while(root != None):
                stack.append(root)
                stack.append(root)
                root = root.left
    
            # Check for empty stack
            if (len(stack) == 0):
                return
            
            root = stack.pop()
    
            if (len(stack) > 0 and stack[-1] == root):
                root = root.right
            else:
                self.order_list.append(root.info)
                root = None


    def     get_predecessor(tree, data):
        '''[18]'''

