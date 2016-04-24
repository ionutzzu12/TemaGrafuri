#include <iostream>
#include <vector>
#include "Graph.h"
#include "BinaryTree.h"

using namespace std;

int main()
{
    Tree t;
    int n=0,i,x;

    // adauga n elemente in arbore
    cin>>n;
    for (i=0;i<n;i++)
        cin>>x, t.insert(x);
    //parcurgeri
    t.inorder();
    t.preorder();
    //find
    t.find(1);
    t.find(7);


    //graf cu n elem
    int j,k,m;
    cin>>n;
    Graph g(n);

    //adauga m muchii
    cin>>m;
    for (i=1; i<=m; i++)
    {
        cin>>j>>k;
        g.addEdge(j,k);
        g.addEdge(k,j); //neorientat
    }

    cout << "BFS: \n";
    g.BFS(0);

    cout << "DFS: \n";
    g.DFS(0);

    return 0;
}
