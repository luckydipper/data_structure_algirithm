#include "GraphType.h"
#include "QueType.h"
#include <iostream>
using namespace std;

int main()
{
    GraphType<const char*> ZooGraph(20);
    ZooGraph.AddVertex("dog");
    ZooGraph.AddVertex("cat");
    ZooGraph.AddVertex("animal");
    ZooGraph.AddVertex("vertebrate");
    ZooGraph.AddVertex("oyster");
    ZooGraph.AddVertex("shellfish");
    ZooGraph.AddVertex("invertebrate");
    ZooGraph.AddVertex("crab");
    ZooGraph.AddVertex("poodle");
    ZooGraph.AddVertex("monkey");
    ZooGraph.AddVertex("banana");
    ZooGraph.AddVertex("dalmatian");
    ZooGraph.AddVertex("dachshund");

    ZooGraph.AddEdge("vertebrate","animal",10);
    ZooGraph.AddEdge("invertebrate", "animal", 20);
    ZooGraph.AddEdge("dog", "vertebrate", 30);
    ZooGraph.AddEdge("cat", "vertebrate", 40);
    ZooGraph.AddEdge("monkey", "vertebrate", 50);
    ZooGraph.AddEdge("shellfish", "invertebrate", 60);
    ZooGraph.AddEdge("crab", "shellfish", 70);
    ZooGraph.AddEdge("oyster", "invertebrate", 80);
    ZooGraph.AddEdge("poodle", "dog", 90);
    ZooGraph.AddEdge("dalmatian", "dog", 100);
    ZooGraph.AddEdge("dachshund", "dog", 110);

    cout << "Weight of vertebrate to animl is " << ZooGraph.WeightIs("vertebrate", "animal") << endl;
    cout << "Weight of poodle to dog is  " << ZooGraph.WeightIs("poodle", "dog") << endl;
    ZooGraph.DeleteEdge("poodle", "dog");
    cout << "Weight of poodle to dog is  " << ZooGraph.WeightIs("poodle", "dog") << endl;

    cout << endl << "GetToVertices(dog,queue)" << endl;


    QueType<const char*> queue;
    ZooGraph.GetToVertices("poodle", queue);
    //BFS
    while (!queue.IsEmpty())
    {
        const char* item;
        queue.Dequeue(item);
        cout << item << endl;
    }
    return 0;
}
