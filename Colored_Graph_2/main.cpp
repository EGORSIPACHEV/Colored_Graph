//
//  main.cpp
//  Colored_Graph_2
//

#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
#include <algorithm>

using namespace std;
namespace fs = filesystem;

vector<vector<int>> read_graph(const string& name_file, vector<pair<int, int>>& list_edges, vector<int>& edges_counter) {
    ifstream fin;
    fin.open(name_file);
    vector<vector<int>> graph;
    int vertex, edges;
    vector<pair<int, int>> pairs;
    list_edges.clear();
    edges_counter.clear();
}

int main() {

    
}
