#include "Grape.hpp"
#include <iostream>
#include <list>
#include <iterator>

using namespace std;

string label[7] = {"C1", "C2", "C3", "C4", "C5", "C6", "C7"};

void printSemester(list <int> l, int i) 
{ 
    list <int> :: iterator it; 
    cout << "Semester " << i << " : ";
    for(it = l.begin(); it != l.end(); ++it) 
        cout << ' ' << label[(*it)-1]; 
    cout << '\n'; 
} 

void printAllSemester(list<list<int>> l) 
{
    list<list<int>> :: iterator it;
    int i = 1;
    for (it = l.begin(); it != l.end(); it++) {
        printSemester(*it, i++);
    }
}

list<list<int>> topologicalSort(Grape& G) 
{
    list<list<int>> nextSemester;

    if (G.isEmpty()) {
        return nextSemester; // base-case, return empty list for empty graph
    }

    // recurrence-case
    list<int> thisSemester;
    list<int>::iterator it;

    for (int i = 0; i < G.getSize(); i++) {
        // for every node without prec
        // will be pushed to list
        if (G.getNumTo(i) == 0) {
            thisSemester.push_back(i);  
        }
    }

    for (it = thisSemester.begin(); it != thisSemester.end(); it++) {
        // for every node that is pushed to the list
        // will be removed from graph
        G.removeNode(*it);
    }

    nextSemester = topologicalSort(G);  //  recursively call for next semester

    nextSemester.push_front(thisSemester);
    
    return nextSemester;
}

int main() 
{
    Grape G;
    list<list<int>> college;

    G.addNode(1);
    G.addNode(2);
    G.addNode(3);
    G.addNode(4);
    G.addNode(5);
    G.addNode(6);
    G.addNode(7);

    G.addEdge(3,1);
    G.addEdge(1,2);
    G.addEdge(4,2);
    G.addEdge(1,4);
    G.addEdge(3,4);
    G.addEdge(2,5);
    G.addEdge(4,5);
    G.addEdge(6,1);
    G.addEdge(7,3);

    G.print();

    college = topologicalSort(G);

    printAllSemester(college);

    return 0;
}
