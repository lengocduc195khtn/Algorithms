#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[], int n, int pos)
{
    adj[n].push_back(pos);
    adj[pos].push_back(n);
}

int main()
{
    vector<int> adj[5];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    for (int i = 0; i < 5; i++)
    {
        for (auto x : adj[i])
            cout << x << " ";
        cout << endl;
    }
}