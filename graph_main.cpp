//Abdullah Ali Khan, CS163: inperson, 12/09/2025
//This file will take the input from the user and call all the functions

#include "graph.h"
#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter number of vertices (places + intersections): ";
    cin >> size;
    cin.ignore();

    table myGraph(size);

    int choice = 0;
    while (choice != 5) {
        cout << "\n--- Menu ---\n";
        cout << "1. Add a favorite place or intersection\n";
        cout << "2. Add an edge (connection) between places\n";
        cout << "3. Display path from a place\n";
        cout << "4. Display all vertices and edges\n";
        cout << "5. Quit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); 

        if (choice == 1) {
            string name, info;
            cout << "Enter place/intersection name: ";
            getline(cin, name);
            cout << "Enter additional info about this place: ";
            getline(cin, info);
            if (myGraph.insert_vertex(name, info))
                cout << "Vertex added successfully.\n";
            else
                cout << "Failed to add vertex.\n";
        }
        else if (choice == 2) {
            string from, to;
            cout << "Enter starting place name: ";
            getline(cin, from);
            cout << "Enter destination place name: ";
            getline(cin, to);
            if (myGraph.insert_edge(from, to))
                cout << "Edge added successfully.\n";
            else
                cout << "Failed to add edge.\n";
        }
        else if (choice == 3) {
            string start;
            cout << "Enter starting place for traversal: ";
            getline(cin, start);
            myGraph.display_path(start);
        }
        else if (choice == 4) {
            myGraph.display_all();
        }
        else if (choice == 5) {
            cout << "Thank You.\n";
        
	}
        else {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}

