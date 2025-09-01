#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief A recursive utility function to detect a cycle using DFS.
 * * @param u The current vertex being visited.
 * @param adj Adjacency list representation of the graph.
 * @param visited A boolean vector to keep track of visited vertices.
 * @param recursionStack A boolean vector to track vertices in the current recursion stack.
 * @return true if a cycle is found, false otherwise.
 */
bool isCyclicUtil(int u, vector<int> adj[], vector<bool>& visited, vector<bool>& recursionStack) {
    // Mark the current node as visited and part of the recursion stack.
    visited[u] = true;
    recursionStack[u] = true;

    // Recur for all adjacent vertices.
    for (int v : adj[u]) {
        // If an adjacent vertex is not visited, recur on it.
        if (!visited[v] && isCyclicUtil(v, adj, visited, recursionStack)) {
            return true;
        }
        // If an adjacent vertex is already in the recursion stack, a cycle is found.
        else if (recursionStack[v]) {
            return true;
        }
    }

    // Backtrack: remove the vertex from the recursion stack.
    recursionStack[u] = false;
    return false;
}

/**
 * @brief The main function to check if a directed graph contains a cycle.
 * * @param V The number of vertices in the graph.
 * @param adj Adjacency list representation of the graph.
 * @return true if the graph contains a cycle, false otherwise.
 */
bool isCyclic(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    vector<bool> recursionStack(V, false);

    // Call the recursive helper for all vertices to handle disconnected graphs.
    for (int i = 0; i < V; i++) {
        if (!visited[i] && isCyclicUtil(i, adj, visited, recursionStack)) {
            return true;
        }
    }
    return false;
}

// Driver code to test the implementation.
int main() {
    const int V = 4;
    vector<int> adj[V];

    // Creating a graph with a cycle
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0); // This edge creates the cycle 0 -> 1 -> 2 -> 0
    adj[2].push_back(3);

    if (isCyclic(V, adj)) {
        cout << "Graph contains a cycle" << endl;
    } else {
        cout << "Graph doesn't contain a cycle" << endl;
    }

    return 0;
}