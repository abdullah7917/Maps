//Abdullah Ali Khan, CS163: inperson, 12/09/2025
//This file will have the structs , classes and the fuction prototype

#include <string>
#include <vector>
using namespace std;

struct edge {
    int adjacent;          // index of adjacent vertex
    edge *next;            // next edge in LLL
};

struct vertex {
    string name;           // favorite place 
    string info;           
    edge *head;            

    vertex();              
    ~vertex();             
};

// Graph table adt
class table {
public:
    table(int size);        
    ~table();               

    bool insert_vertex(const string &name, const string &info);
    bool insert_edge(const string &from, const string &to);
    bool display_path(const string &start);
    void display_all();

private:
    vertex *adjacency_list;   
    int list_size;             // number of vertices
    int vertex_count;          // how many have been added
    int find_location(const string &key);
    void display_path_recursive(int index, vector<bool> &visited);
};

