#include <vector>
#include <queue>

using namespace std;

class Graph
{
    int n;   // nr noduri
    vector<vector<int>> adj;   // liste de adiacenta

    void rec(int v, bool visited[]);   // DFS-ul propriu-zis
public:
    Graph(int n);   // Constructor
    void addEdge(int v, int w);   // adauga muchia (v,w)
    void DFS(int v);
    void BFS(int v);
    void afis();
};

Graph::Graph(int n)
{
    this->n = n;
    adj.resize(n);
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::BFS(int v)
{
    // inițializări
    int i, u;
    bool visited[n];
    queue<int> Q;

    for (i=0; i<n; i++)
    {
        visited[i] = false;
    }

    Q.push(v); // punem nodul sursă în coada Q

    // algoritmul propriu-zis
    while (!Q.empty())
    {
         // extragem nodul v din coadă
        v = Q.front();
        Q.pop();
        cout<<v<<" ";

        for (vector<int>::iterator it=adj[v].begin(); it!=adj[v].end(); it++)
        {
            u = *it;
            if (!visited[u])
            {
                visited[u] = true;
                Q.push(u);
            }
        }
        visited[v] = true; // am terminat de explorat toți vecinii lui v
    }
    cout<<endl;
}

void Graph::DFS(int v)
{
    // initializari
    bool visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    // DFS rec
    rec(v, visited);
    cout<<endl;
}

void Graph::rec(int v, bool visited[])
{
    visited[v] = true;
    cout<<v<<" ";
    vector<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            rec(*i, visited);
}
