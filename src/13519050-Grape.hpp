#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

#include <iostream>
#include <vector>

using namespace std;

class Grape
{
private:
    /* data */
    bool* adjMatrix; /* matrix of bool */
    int n; // node count
    int size; // container size

    bool* isNode; /* array of valid nodes */

    bool get(int i, int j);
    void set(int i, int j, bool val);

    bool isValid(int x);

public:
    Grape();
    Grape(int n);
    ~Grape();

    int getSize();

    bool isEmpty(); // 0 nodes

    void addNode(int n);
    void removeNode(int n);

    void addEdge(int n1, int n2);
    void removeEdge(int n1, int n2);

    bool isEdge(int n1, int n2); // true if there is edge n1 -> n2

    int getNumFrom(int x);  
    int getNumTo(int x); 

    void print();

    void printNode(int node);
    void printSuccNode(int node);
    void printPrecNode(int node);

    void configure(vector<vector<int> > );
};


#endif