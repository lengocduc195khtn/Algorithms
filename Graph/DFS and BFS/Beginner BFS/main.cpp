#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[], int n, int pos)
{
    adj[n].push_back(pos);
    adj[pos].push_back(n);
}

void printGraph(vector<int> adj[], int V)
{
    for (int i = 0; i < V; i++)
    {
        cout << "head -> ";
        for (auto x : adj[i])
            cout << x << " ";
        cout << endl;
    }
}

void printBFS(vector<int> adj)
{
    for (auto x : adj)
        cout << x << " ";
    cout << endl;
}

void CurcuitBFS(vector<int> adj[], int V, vector<int> line, bool *arrVisited, int n)
{
    bool visit = 0;
    for (auto x : adj[n])
    {
        if (arrVisited[x] == 0)
        {
            line.push_back(x);
            visit = 1;
            arrVisited[x] = 1;
            CurcuitBFS(adj, V, line, arrVisited, x);
        }
    }
    if (visit == 0)
        printBFS(line);
}

int main()
{
}