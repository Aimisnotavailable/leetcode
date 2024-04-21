#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
     bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination) {
        std::unordered_map<int, std::vector<int>> graph;
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
       
        std::unordered_set<int> visited;
        return dfs(source, destination, graph, visited);
    }
    
    bool dfs(int node, int destination, std::unordered_map<int, std::vector<int>>& graph, std::unordered_set<int>& visited) {
        if (node == destination) {
            return true;
        }
        
        visited.insert(node);
        for (int neighbor : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                if (dfs(neighbor, destination, graph, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};