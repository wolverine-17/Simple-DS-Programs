#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

class Graph
{
private:
    int vertices;
    std::vector<std::vector<int>> adjacencyList;

public:
    Graph(int v) : vertices(v), adjacencyList(v) {}

    // Function to add an edge to the graph
    void addEdge(int u, int v)
    {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }

    // Function to perform Depth-First Search traversal
    void dfs(int startVertex)
    {
        std::unordered_set<int> visited;
        std::cout << "DFS Traversal starting from vertex " << startVertex << ": ";
        dfsRecursive(startVertex, visited);
        std::cout << std::endl;
    }

    // Function to perform Breadth-First Search traversal
    void bfs(int startVertex)
    {
        std::unordered_set<int> visited;
        std::queue<int> queue;
        visited.insert(startVertex);
        queue.push(startVertex);

        std::cout << "BFS Traversal starting from vertex " << startVertex << ": ";

        while (!queue.empty())
        {
            int currentVertex = queue.front();
            std::cout << currentVertex << " ";
            queue.pop();

            for (int neighbor : adjacencyList[currentVertex])
            {
                if (visited.find(neighbor) == visited.end())
                {
                    visited.insert(neighbor);
                    queue.push(neighbor);
                }
            }
        }

        std::cout << std::endl;
    }

private:
    // Recursive function for Depth-First Search traversal
    void dfsRecursive(int currentVertex, std::unordered_set<int> &visited)
    {
        visited.insert(currentVertex);
        std::cout << currentVertex << " ";

        for (int neighbor : adjacencyList[currentVertex])
        {
            if (visited.find(neighbor) == visited.end())
            {
                dfsRecursive(neighbor, visited);
            }
        }
    }
};

int main()
{
    // Create a graph with 6 vertices
    Graph myGraph(6);

    // Add edges to the graph
    myGraph.addEdge(0, 1);
    myGraph.addEdge(0, 2);
    myGraph.addEdge(1, 3);
    myGraph.addEdge(2, 4);
    myGraph.addEdge(2, 5);

    // Perform DFS and BFS traversals
    myGraph.dfs(0);
    myGraph.bfs(0);

    return 0;
}
