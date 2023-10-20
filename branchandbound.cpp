#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const int INF = INT_MAX;

int n;
vector<vector<int>> graph;
vector<int> path;
vector<bool> visited;

int lowerBound(int v) {
    int lb = 0;
    int min1 = INF, min2 = INF;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && i != v) {
            if (graph[v][i] < min1) {
                min2 = min1;
                min1 = graph[v][i];
            } else if (graph[v][i] < min2) {
                min2 = graph[v][i];
            }
        }
    }
    lb = min1 + min2;
    return lb;
}

void tsp(int v, int cost, int level) {
    if (level == n - 1) {
        cout << "Path: ";
        for (int i = 0; i < n; i++) {
            cout << path[i] << " -> ";
        }
        cout << path[0];
        cout << "\nCost: " << cost + graph[v][0] << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int newCost = cost + graph[v][i];
            int bound = newCost + lowerBound(i);

            if (bound < INF) {
                visited[i] = true;
                path[level + 1] = i;
                tsp(i, newCost, level + 1);
                visited[i] = false;
            }
        }
    }
}

int main() {
    cout << "Enter the number of cities: ";
    cin >> n;

    // Initialize the graph
    graph.resize(n, vector<int>(n));
    visited.resize(n, false);
    path.resize(n);

    cout << "Enter the adjacency matrix (0 for unreachable):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    // Start from the first city (0)
    visited[0] = true;
    path[0] = 0;

    cout << "LC Branch and Bound TSP Solution:\n";
    tsp(0, 0, 0);

    return 0;
}
