#include <iostream>
#include <vector>
#include <stack>
// Using standard namespace for simplicity
using namespace std;

/**
* @brief Performs Depth-First Search traversal on a graph.
* * @param u The current vertex being visited.
* @param adj The adjacency list of the graph.
* @param visited A boolean vector to keep track of visited vertices.
*/
void topologicalSortUtil(int u, vector<vector<int>>& adj, vector<bool>& visited,stack<int>& sorted) {
    // TODO: Complete the DFS logic here.
    // 1. Mark the current node as visited.
    visited[u] = true;
    // 3. Recursively call DFS for all unvisited neighbors.
    for(int v: adj[u]){
        if( !visited[v]){
            topologicalSortUtil(v,adj,visited);
        }
    }
    sorted.push(v);
}

// Main function to set up the graph and start the traversal
int main() {
    int V = 6;
    vector<vector<int>> adj(V);
    vector<bool> visited(V, false);
    stack<int> sorted;

    // A Directed Acyclic Graph (DAG)
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    // Run the traversal for all components of the graph
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, adj, visited, sorted);
        }
    }

    cout << "Topological Sort:" << endl;
    while (!sorted.empty()) {
        cout << sorted.top() << " ";
        sorted.pop();
    }
    cout << endl;

    return 0;
}