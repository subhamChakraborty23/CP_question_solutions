/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<iostream>
#include <list>
#include<vector>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isReachable(int s, int d);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

bool Graph::isReachable(int s, int d)
{
    // Base case
    if (s == d)
        return true;

    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    list<int> queue;

    visited[s] = true;
    queue.push_back(s);

    list<int>::iterator i;

    while (!queue.empty())
    {

        s = queue.front();
        queue.pop_front();

        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {

            if (*i == d)
                return true;


            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }

    return false;
}

int main()
{
    // Create a graph given in the above diagram

    int n;
    cin >> n;
    Graph g(n);
    vector<int>nodes(n);
    for (int i = 0; i < n; i++) {
        cin >> nodes[i];
    }
    int e;
    cin >> e;
    // vector<pair<int,int>>edge(e);
    for (int i = 0; i < e; i++) {
        // cin>>edge[i].first;
        // cin>>edge[i].second;

        int u, v;
        cin >> u >> v;

        g.addEdge(u, v);
    }
    int follower;
    int following;
    cin >> follower;
    cin >> following;

    if (g.isReachable(follower, following))
        cout << 1;
    else
        cout << 0;
    return 0;
}