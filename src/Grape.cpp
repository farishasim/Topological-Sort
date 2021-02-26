#include "Grape.hpp"

Grape::Grape()
{
    n = 0;
    size = 10;
    isNode = new bool[size];
    for (int i = 0; i < size; i++) {
        isNode[i] = false;
    }

    adjMatrix = new bool[size*size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            this->set(i, j, false);
        }
    }
}

Grape::Grape(int nodes)
/* nodes >= 0 */
{
    int i;
    n = nodes;
    if (n < 10) {
        size = 10;
    } else {
        size = n;
    }

    isNode = new bool[size];
    for (i = 0; i < n; i++) {
        isNode[i] = true;
    }
    for (; i < size; i++) {
        isNode[i] = false;
    }

    adjMatrix = new bool[size*size];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            this->set(i, j, false);
        }
    }
}

Grape::~Grape()
{
    delete[] isNode;
    delete[] adjMatrix;
}

bool Grape::get(int i, int j) 
{
    return adjMatrix[i*size + j];
}

void Grape::set(int i, int j, bool val) 
{
    adjMatrix[i*size+j] = val;
}

bool Grape::isValid(int x) 
{
    return x >= 0 && x < size;
}

int Grape::getSize() {
    return this->size;
}

bool Grape::isEmpty() 
{
    return n == 0;
}

void Grape::addNode(int x) 
{
    if (this->isValid(x) && !isNode[x]) {
        isNode[x] = true;
        n++;
    }
}

void Grape::removeNode(int x) 
{
    int i = 0, node_count = 0;
    if (this->isValid(x)) {
        if (isNode[x]) {
            /* remove all edge from x */
            while (node_count < n) {
                if (isNode[i]) {
                    this->removeEdge(x, i);
                    node_count++;
                }
                i++;
            }
            /* remove all edge to x */
            i = 0; node_count = 0;
            while (node_count < n) {
                if (isNode[i]) {
                    this->removeEdge(i, x);
                    node_count++;
                }
                i++;
            }
            /* remove node x */
            isNode[x] = false;
            n--;
        }
    }
}

void Grape::addEdge(int n1, int n2) 
{
    if (this->isValid(n1) && this->isValid(n2)) {
        if (isNode[n1] && isNode[n2]) {
            set(n1, n2, true);
        }
    }
}

void Grape::removeEdge(int n1, int n2) 
{
    if (this->isValid(n1) && this->isValid(n2)) {
        if (isNode[n1] && isNode[n2]) {
            set(n1, n2, false);
        }
    }
}

bool Grape::isEdge(int n1, int n2) 
{
    return this->isValid(n1) && this->isValid(n2) && isNode[n1] && isNode[n2] && this->get(n1, n2);
}

void Grape::print() 
{
    int i = 0, count = 0;
    while (count < n) {
        if (isNode[i]) {
            this->printNode(i);
            count++;
        }
        i++;
    }
}

int Grape::getNumFrom(int x) 
{
    int i = 0, node_count = 0, count = 0;

    if (!this->isValid(x) || !isNode[x]) {
        return -1;
    } 

    while (node_count < n) {
        if (isNode[i]) {
            if (this->isEdge(x, i)) {
                count++;
            }
            node_count++;
        }
        i++;
    }

    return count;
}

int Grape::getNumTo(int x) 
{
    int i = 0, node_count = 0, count = 0;

    if (!this->isValid(x) || !isNode[x]) {
        return -1;
    } 

    while (node_count < n) {
        if (isNode[i]) {
            if (this->isEdge(i, x)) {
                count++;
            }
            node_count++;
        }
        i++;
    }

    return count;
}


void Grape::printNode(int node) 
{
    printPrecNode(node);
    cout << " -> " << node << " -> ";
    printSuccNode(node);
    cout << "\n";
}

void Grape::printSuccNode(int x) 
{
    int i, count;
    i = 0; count = 0;

    cout << "{ ";
    while (count < n) {
        if (isNode[i]) {  //  if there is node i
            if (isEdge(x, i)) {  //  if there is edge from x to i 
                cout << i << " "; 
            }
            count++;
        }
        i++;
    }
    cout << "}";
}

void Grape::printPrecNode(int x) 
{
    int i, count;
    i = 0; count = 0;

    cout << "{ ";
    while (count < n) {
        if (isNode[i]) {  //  if there is node i
            if (isEdge(i, x)) {  //  if there is edge from i to x 
                cout << i << " "; 
            }
            count++;
        }
        i++;
    }
    cout << "}";
}