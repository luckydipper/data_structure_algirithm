from QueType import *
from StackType import *

NULL_EDGE = 0

def index_is(vertices, vertex):
    index = 0

    while index < len(vertices) and vertex != vertices[index]:
        index += 1

    if not index < len(vertices):
        return -1
    else:
        return index

class GraphType:
    def __init__(self, maxV=50):
        self.numVertices = 0
        self.maxVertices = maxV
        self.vertices = [None] * maxV
        self.edges = [[NULL_EDGE] * maxV for _ in range(maxV)]
        self.marks = [None] * maxV

    def add_vertex(self, vertex):
        self.vertices[self.numVertices] = vertex
        self.numVertices+=1

    def add_edge(self, fromVertex, toVertex, weight):
        from_index = index_is(self.vertices, fromVertex)
        to_index = index_is(self.vertices, toVertex)
        self.edges[from_index][to_index] = weight

    def weight_is(self, fromVertex, toVertex):
        from_index = index_is(self.vertices, fromVertex)
        to_index = index_is(self.vertices, toVertex)
        return self.edges[from_index][to_index]


    def get_to_vertices(self, vertex, adjVertices):
        finder_index = index_is(self.vertices,vertex)
        finding_list = self.edges[finder_index]
        
        for ind, weight in enumerate(finding_list):
            if weight is not NULL_EDGE:
                adjVertices.enqueue(self.vertices[ind])



    def clear_marks(self):
        self.marks = [None] * self.maxVertices


    def is_marked(self, vertex):
        index = index_is(self.vertices, vertex)
        if self.marks[index] is None:
            return False
        else:
            return True


    def mark_vertex(self, vertex):
        index = index_is(self.vertices, vertex)
        self.marks[index] = 1


    def delete_edge(self, fromVertex, toVertex):
        from_index = index_is(self.vertices, fromVertex)
        to_index = index_is(self.vertices, toVertex)
        self.edges[from_index][to_index] = NULL_EDGE

