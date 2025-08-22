#include <iostream>
#include <vector>

using namespace std;

// Modify the Edge struct to hold both source and destination
struct Edge {
    int src;
    int dest;

    // Update the constructor to accept both values
    Edge(int s, int d) : src(s), dest(d) {}
};

int main() {
    int num_vertices = 4;
    vector<vector<Edge>> graph(num_vertices);

    // This now matches the structure from your image
    graph[0].push_back(Edge(0, 2));

    graph[1].push_back(Edge(1, 2));
    graph[1].push_back(Edge(1, 3));

    graph[2].push_back(Edge(2, 0));
    graph[2].push_back(Edge(2, 1));
    graph[2].push_back(Edge(2, 3));

    graph[3].push_back(Edge(3, 1));
    graph[3].push_back(Edge(3, 2));

    // Print the graph to verify
    cout << "Graph Adjacency List:\n";
    for (int i = 0; i < num_vertices; ++i) {
        cout << "Vertex " << i << " -> ";
        for (const auto& edge : graph[i]) {
            // We print the destination of the edge
            cout << edge.dest << " ";
        }
        cout << endl;
    }

    return 0;
}

// #include <iostream>
// #include <vector>

// using namespace std;

// struct Edge {
//     int destination;
//     Edge(int dest) : destination(dest) {}
// };

// int main() {
//     int num_vertices = 4;
//     vector<vector<Edge>> graph(num_vertices);

//     graph[0].push_back(Edge(1));
//     graph[1].push_back(Edge(2));
//     graph[2].push_back(Edge(0));
//     graph[2].push_back(Edge(3));

//     cout << "Graph Adjacency List:\n";
//     for (int i = 0; i < num_vertices; ++i) {
//         cout << "Vertex " << i << " -> ";
//         for (const auto& edge : graph[i]) {
//             cout << edge.destination << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }