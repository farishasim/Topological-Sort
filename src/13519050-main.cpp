// graph class
#include "13519050-Grape.hpp"

// i/o library
#include <iostream>
#include <fstream>
#include <sstream>

// array and list library
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

vector<string> label;

//****** String-support Function ******//
string removeChar(string str, char c) 
{
    // remove all occurrence of char c from string str
    string output;
    output.reserve(str.size()); 
    for(size_t i = 0; i < str.size(); ++i)
        if(str[i] != c) output += str[i];
    return output;
}

vector<string> splitString(string str, string separator)
{
    // split string by separator 
    // to collection of string
    vector<string> listString;
    size_t pos = 0;
    while ((pos = str.find(separator)) != -1) {
        listString.push_back(str.substr(0, pos));
        str.erase(0, pos + separator.length());
    }
    listString.push_back(str.substr(0, pos));
    return listString;
}

//****** Input/Output Function ******//
vector<vector<string> > inputFile() 
{
    string filename;
    vector<vector<string> > inputStream;

    cout << "Your input file name: ";
    cin >> filename;

    filename = "../test/" + filename;

    ifstream infile(filename);
    string line;

    while (getline(infile, line)) {
        line = removeChar(line, '.');
        inputStream.push_back(splitString(line, ", "));
    }

    return inputStream;
}

void printSemester(list <int> l, int i) 
{ 
    list <int> :: iterator it; 
    cout << "Semester " << i << " : ";
    for(it = l.begin(); it != l.end(); ++it) 
        cout << ' ' << label[(*it)]; 
    cout << '\n'; 
} 

void printAllSemester(list<list<int> > l) 
{
    list<list<int> > :: iterator it;
    int i = 1;
    for (it = l.begin(); it != l.end(); it++) {
        printSemester(*it, i++);
    }
}

//****** Setup Function ******//
void setupLabel(vector<vector<string> > inputStream) 
{
    // setup for label
    vector<vector<string> >:: iterator it;

    for (it = inputStream.begin(); it != inputStream.end(); it++) {
        label.push_back(it->at(0));
    }
}

vector<vector<int> > setupConfig(vector<vector<string> > inputStream)
{
    // setup for graph configuration
    vector<vector<int> > graphConfig;
    vector<string> thisLine;
    string prereq;
    int i, j;
    for (i = 0; i < inputStream.size(); i++) {
        thisLine = inputStream.at(i);
        vector<int> nodeConfig;
        for (j = 1; j < thisLine.size(); j++) {
            prereq = thisLine.at(j);
            int idx = distance(label.begin(), find(label.begin(), label.end(), prereq));
            nodeConfig.push_back(idx);
        }
        graphConfig.push_back(nodeConfig);
    }

    return graphConfig;
}

vector<vector<int> > setup() 
{
    // setup function
    vector<vector<string> > inputStream = inputFile();

    setupLabel(inputStream);

    return setupConfig(inputStream);
}

//****** Solving Algorithm ******//
list<list<int> > topologicalSort(Grape& G) 
{
    list<list<int> > nextSemester;

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

//****** Main Function ******//
int main() 
{
    Grape G;

    vector<vector<int> > graphConfig = setup();

    G.configure(graphConfig);

    list<list<int> > college = topologicalSort(G);

    printAllSemester(college);

    return 0;
}
