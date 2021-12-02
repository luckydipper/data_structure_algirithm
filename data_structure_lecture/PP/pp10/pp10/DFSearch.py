from GraphType import *

def depth_first_search(graph, startVertex, endVertex):
    stack = StackType()
    vertexQ = QueType()
    stack.push(startVertex)
    while(True):
        if stack.is_empty():
            graph.clear_marks()
            return False
        elif startVertex == endVertex:
            graph.clear_marks()
            return True
        else:
            iterate_node = stack.top()
            stack.pop()
            print(iterate_node)
            graph.mark_vertex(iterate_node)            
            graph.get_to_vertices(iterate_node, vertexQ)
            
            while not vertexQ.is_empty():
                child_node = vertexQ.dequeue()
                if graph.is_marked(child_node):
                    continue
                else:
                    graph.mark_vertex(child_node)
                    stack.push(child_node)
    
