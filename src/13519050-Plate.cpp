/* driver for Grape.h */
#include "13519050-Grape.hpp"

void printChoice();

int main() {
    Grape G;
    int choice, choice2, choice3;
    
    G.print();

    cout << "/==== A Grape is constructed, what is your choice ====/\n";

    while (1) {
        printChoice();
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "What node to add: \n";
            cin >> choice2;
            G.addNode(choice2);
            break;

        case 2:
            cout << "what node to remove: \n";
            cin >> choice2;
            G.removeNode(choice2);
            break;

        case 3:
            cout << "what edge to add : \n";
            cin >> choice2; cin >> choice3;
            G.addEdge(choice2, choice3);
            break;

        case 4:
            cout << "What edge to remove: \n";
            cin >> choice2; cin >> choice3;
            G.removeEdge(choice2, choice3);
            break;

        case 99:
            exit(0);

        default:
            break;
        }

        G.print();
    }

    return 0;
}

void printChoice() {
    cout << "Menu : \n";
    cout << "1. Add node\n";
    cout << "2. Remove node\n";
    cout << "3. Add edge\n";
    cout << "4. Remove edge\n";
    cout << "99. exit\n";
}