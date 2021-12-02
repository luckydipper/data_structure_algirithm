from GraphType import *

def breadth_first_search(graph, startVertex, endVertex):
    queue = QueType()
    vertexQ = QueType()
    found = False
    
    queue.enqueue(startVertex)
    
    while(True):
        if queue.is_empty():
            graph.clear_marks()
            return False
        elif startVertex is endVertex:
            graph.clear_marks()
            return True
        else:
            iterate_node = queue.dequeue()
            print(iterate_node)
            graph.mark_vertex(iterate_node)
            graph.get_to_vertices(iterate_node,vertexQ)
            
            while not vertexQ.is_empty():
                child_node = vertexQ.dequeue()
                if graph.is_marked(child_node):
                    continue
                else:
                    graph.mark_vertex(child_node)
                    queue.enqueue(child_node)
