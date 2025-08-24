    #include <iostream>
    #include <vector>

    // Using standard namespace for simplicity
    using namespace std;

    /**
     * @brief Performs Depth-First Search traversal on a graph.
     * * @param u The current vertex being visited.
     * @param adj The adjacency list of the graph.
     * @param visited A boolean vector to keep track of visited vertices.
     */
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
        // TODO: Complete the DFS logic here.
        // 1. Mark the current node as visited.
        visited[u] = true;
        // 2. Print the current node.
        cout << u<< " ";
        // 3. Recursively call DFS for all unvisited neighbors.
        for(int v: adj[u]){
            if( !visited[v]){
                dfs(v,adj,visited);
            }
        }
        
    }

    // Main function to set up the graph and start the traversal
    int main() {
        // Number of vertices
        int V = 5; 
        
        // Adjacency list representation of the graph
        vector<vector<int>> adj(V);
        
        // Vector to store visited vertices
        vector<bool> visited(V, false);

        // Adding edges to the graph
        adj[0].push_back(1);
        adj[0].push_back(2);
        adj[1].push_back(3);
        adj[2].push_back(4);
        adj[3].push_back(0); // Example of a cycle
        adj[4].push_back(1);

        cout << "Depth-First Traversal starting from vertex 0:" << endl;
        
        // Start DFS from the first vertex (vertex 0)
        dfs(0, adj, visited);
        
        cout << endl;

        return 0;
    }