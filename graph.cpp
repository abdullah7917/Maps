//Abdullah Ali Khan, CS163: inperson, 12/09/2025
//This file will define all the fuctions
#include "graph.h"
#include <iostream>
#include <vector>
using namespace std;

vertex::vertex() 
{
    name = "";
    info = "";
    head = nullptr;
}


vertex::~vertex() 
{
    edge *current = head;
    while (current) {
        edge *temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

table::table(int size) 
{
    list_size = size;
    adjacency_list = new vertex[list_size];
    vertex_count = 0;
}


table::~table() {
    delete[] adjacency_list;
    adjacency_list = nullptr;
}


int table::find_location(const string &key) {
    for (int i = 0; i < vertex_count; ++i) {
        if (adjacency_list[i].name == key) {
            return i;
        }
    }
    return -1; // not found
}


bool table::insert_vertex(const string &name, const string &info) 
{
    if (vertex_count >= list_size) {
        cout << "Error: vertex list full.\n";
        return false;
    }
    if (find_location(name) != -1) {
        cout << "Error: vertex already exists.\n";
        return false;
    }
    adjacency_list[vertex_count].name = name;
    adjacency_list[vertex_count].info = info;
    adjacency_list[vertex_count].head = nullptr;
    ++vertex_count;
    return true;
}

bool table::insert_edge(const string &from, const string &to) 
{
    int from_index = find_location(from);
    int to_index = find_location(to);
    if (from_index == -1 || to_index == -1) {
        cout << "Error: one or both vertices not found.\n";
        return false;
    }

    edge *new_edge = new edge;
    new_edge->adjacent = to_index;
    new_edge->next = adjacency_list[from_index].head;
    adjacency_list[from_index].head = new_edge;

    return true;
}

void table::display_path_recursive(int index, vector<bool> &visited) 
{
    if (visited[index]) return;

    visited[index] = true;
    cout << adjacency_list[index].name << " (" << adjacency_list[index].info << ")\n";

    edge *current = adjacency_list[index].head;
    while (current) {
        display_path_recursive(current->adjacent, visited);
        current = current->next;
    }
}

bool table::display_path(const string &start) 
{
    int start_index = find_location(start);
    if (start_index == -1) {
        cout << "Error: starting vertex not found.\n";
        return false;
    }

    vector<bool> visited(vertex_count, false);
    cout << "Traversing paths from " << start << ":\n";
    display_path_recursive(start_index, visited);
    return true;
}


void table::display_all() 
{
    cout << "All vertices and edges:\n";
    for (int i = 0; i < vertex_count; ++i) {
        cout << adjacency_list[i].name << " (" << adjacency_list[i].info << ") -> ";
        edge *current = adjacency_list[i].head;
        while (current) {
            cout << adjacency_list[current->adjacent].name;
            if (current->next) cout << ", ";
            current = current->next;
        }
        cout << "\n";
    }
}

