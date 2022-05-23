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

vector<vector<int>> obxod_grapha(const string& filename, vector<pair<int, int>>& edges_matrix, vector<int>& edges_schet) {
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

vector<int> painting(vector<vector<int>>& graph, const vector<int>& edges_schet) {
    vector<int> vecOfColors(graph.size(), -1);
    for(auto it : edges_schet) { //Запускаю автоитератор по ребрам
        int i = it;
        vector<bool> iscolored(graph.size(), false);
        for (int j = 0; j < graph.size(); j++) {
            if (graph[i][j] == 1) {
                if(vecOfColors[j] > -1){
                    iscolored[vecOfColors[j]] = true;
                }
            }
        }
        for (int k = 0; k < graph.size(); k++) {
            if (!iscolored[k]) {
                vecOfColors[i] = k;
                break;
            }
        }
    }
    return vecOfColors;
}

int main () {
    char path[] = "/Users/egorsipachev/МГУУЧЕБА/программирование/semestr4/colored_graph/tests";
    auto it = fs::directory_iterator(path);
    vector<fs::path> array_path;
    copy_if(fs::begin(it), fs::end(it), std::back_inserter(array_path),
        [](const auto& entry) {
            return fs::is_regular_file(entry);
    });
    
    
    for (auto & j : array_path) {
        vector<int> edges_mass;
        vector<pair<int, int>> edges_pairs;
        vector<vector<int>> graph = obxod_grapha(j.string(), edges_pairs, edges_mass);
        vector<int> Graph_colored = painting(graph, edges_mass);
        int max = -1;
        for (int i = 0; i < Graph_colored.size(); i++) {
            if (Graph_colored[i] > max) {
                max = Graph_colored[i];
            }
        }
        cout << j.string() << " " << max + 1 << endl;
       
        cout << endl;
        for (auto i : edges_pairs) {
            if (Graph_colored[i.first] == Graph_colored[i.second]) {
                cout << "Error! Try test: " << j.string() << endl;
                cout << i.first << " " << i.second << endl;
                break;
            }
        }
    }
    return 0;
}
