#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Performs Depth-First Search traversal on a graph.
 * @param u The current vertex being visited.
 * @param adj The adjacency list of the graph.
 * @param visited A boolean vector to keep track of visited vertices.
 */
void findAllPathsDFS(int u,int target, vector<vector<int>>& adj, vector<bool>& visited,vector<int>& path) {
    visited[u] = true;
    path.push_back(u);

    if(u == target){
        for(int i=0; i< path.size();i++){
            cout << path[i] << (i== path.size() - 1 ? " " : " -> ");
        }
        cout << endl;
    } else {
        for (int v : adj[u]) {
        if (!visited[v]) {
            findAllPathsDFS(v,target, adj, visited, path);
        }
    }
    }
    path.pop_back();
    visited[u] = false;

}

// Main function to set up the graph and start the traversal
int main() {
    // Number of vertices
    int V = 5;

    // Adjacency list representation of the graph
    vector<vector<int>> adj(V);

    // Adding edges to the graph
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3); // Added for more path options
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(4);
    adj[3].push_back(2); // Example of a cycle

    // Define the source and target vertices
    int source = 0;
    int target = 4;

    cout << "All paths from " << source << " to " << target << ":" << endl;

    // Vector to store visited vertices for the current path
    vector<bool> visited(V, false);
    // Vector to store the current path
    vector<int> path;

    // Start DFS from the source vertex
    findAllPathsDFS(source, target, adj, visited, path);

    return 0;
}