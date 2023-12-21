#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Structure to represent an edge in the graph
struct Edge
{
    int destination;
    int weight;
};

// Structure to represent a vertex in the graph
struct Vertex
{
    int id;
    int distance;

    bool operator>(const Vertex &other) const
    {
        return distance > other.distance;
    }
};

class Graph
{
private:
    int vertices;
    vector<vector<Edge>> adjacencyList;

public:
    Graph(int v) : vertices(v), adjacencyList(v) {}

    // Function to add a directed edge to the graph
    void addDirectedEdge(int source, int destination, int weight)
    {
        adjacencyList[source].push_back({destination, weight});
    }

    // Function to perform Dijkstra's algorithm for single-source shortest paths
    vector<int> dijkstra(int startVertex)
    {
        // Initialize distances to all vertices as infinity
        vector<int> distances(vertices, numeric_limits<int>::max());

        // Set distance of the start vertex to itself as 0
        distances[startVertex] = 0;

        // Priority queue to store vertices based on their distances
        priority_queue<Vertex, vector<Vertex>, greater<Vertex>> pq;
        pq.push({startVertex, 0});

        while (!pq.empty())
        {
            Vertex current = pq.top();
            pq.pop();

            // Update distances for neighboring vertices
            for (const Edge &edge : adjacencyList[current.id])
            {
                int newDistance = current.distance + edge.weight;

                if (newDistance < distances[edge.destination])
                {
                    distances[edge.destination] = newDistance;
                    pq.push({edge.destination, newDistance});
                }
            }
        }

        return distances;
    }
};

int main()
{
    // Create a directed graph with 6 vertices
    Graph myGraph(6);

    // Add directed edges with weights to the graph
    myGraph.addDirectedEdge(0, 1, 2);
    myGraph.addDirectedEdge(0, 2, 4);
    myGraph.addDirectedEdge(1, 2, 1);
    myGraph.addDirectedEdge(1, 3, 7);
    myGraph.addDirectedEdge(2, 4, 3);
    myGraph.addDirectedEdge(3, 5, 1);
    myGraph.addDirectedEdge(4, 3, 2);
    myGraph.addDirectedEdge(4, 5, 5);

    // Perform Dijkstra's algorithm starting from vertex 0
    vector<int> shortestDistances = myGraph.dijkstra(0);

    // Display the shortest distances from vertex 0 to all other vertices
    cout << "Shortest Distances from Vertex 0:\n";
    for (int i = 0; i < shortestDistances.size(); ++i)
    {
        cout << "Vertex " << i << ": " << shortestDistances[i] << endl;
    }

    return 0;
}
