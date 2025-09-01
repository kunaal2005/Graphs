#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief A recursive utility function to detect a cycle using DFS.
 * @param u The current vertex being visited.
 * @param visited A boolean vector to keep track of visited vertices.
 * @param parent The parent vertex in the DFS tree.
 * @param adj Adjacency list representation of the graph.
 * @return true if a cycle is found, false otherwise.
 */
bool isCyclicUtil(int u, vector<bool>& visited, int parent, vector<int> adj[]) {
    // Mark the current node as visited.
    visited[u] = true;

    // Recur for all adjacent vertices.
    for (int v : adj[u]) {
        // If an adjacent vertex is not visited, then recur for it.
        if (!visited[v]) {
            if (isCyclicUtil(v, visited, u, adj)) {
                return true;
            }
        }
        // If an adjacent is visited and is not the parent of the current vertex,
        // then there is a cycle.
        else if (v != parent) {
            return true;
        }
    }
    return false;
}

/**
 * @brief The main function to check if an undirected graph contains a cycle.
 * @param V The number of vertices in the graph.
 * @param adj Adjacency list representation of the graph.
 * @return true if the graph contains a cycle, false otherwise.
 */
bool isCyclic(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);

    // Call the recursive helper for all vertices to handle disconnected graphs.
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(i, visited, -1, adj)) {
                return true;
            }
        }
    }
    return false;
}

// Helper function to add an edge for an undirected graph.
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Driver code to test the implementation.
int main() {
    const int V = 5;
    vector<int> adj[V];

    // Creating a graph with a cycle 1-2-4-1
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4); // This edge creates the cycle

    if (isCyclic(V, adj)) {
        cout << "Graph contains a cycle" << endl;
    } else {
        cout << "Graph doesn't contain a cycle" << endl;
    }

    return 0;
}