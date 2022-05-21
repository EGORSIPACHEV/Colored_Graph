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

vector<vector<int>> graph_obxod(const string& filename, vector<pair<int, int>>& edges_matrix, vector<int>& edges_schet) {
    ifstream fin;
    fin.open(filename);
    vector<vector<int>> graph_indexes;
    int indexes, edges_num;
    vector<pair<int, int>> pairs;
    edges_matrix.clear();
    edges_schet.clear();
    if (fin.is_open()) {
        fin >> indexes >> edges_num;
        vector <int> v(indexes, 0);
        graph_indexes.resize(indexes, v);
        auto zero = make_pair(0, 0);
        pairs.resize(graph_indexes.size(), zero);
        for (int k = 0; k < edges_num; k++) {
            int start, end;
            fin >> start >> end;
            auto p1 = make_pair(start, end);
            edges_matrix.push_back(p1);
            graph_indexes[start][end] = 1;
            graph_indexes[end][start] = 1;
            pairs[start].first += 1;
            pairs[end].first += 1;
            pairs[start].second = start;
            pairs[end].second = end;
        }
    } else {
        cout << "File do not exist!" << endl;
    }
    sort(pairs.begin(), pairs.end());
    for(long int i = pairs.size()-1;i >= 0; i--){
        edges_schet.push_back(pairs[i].second);
    }
    return graph_indexes;
}

int main() {

    
}
