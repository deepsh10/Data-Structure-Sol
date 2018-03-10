#include <cstdlib>
#include <vector>
#include <list>
#include <array>
#include "iostream"
#include "string"

using namespace std;


class Graph{
    int vertices;
    
    vector<int> indegree;
    
    list<int> *adj;
    
public:

    Graph(int vertices);
    
    int getVertices();
    
    void displayIndegree();
    
    void addEdge(int u,int v); /* u -> v */
    
    void displayAdjcentNodes(int nodeIndex);
    
    void findPossibleTopologicalTraversal();
    
};


Graph::Graph(int vertices)
{
    this->vertices = vertices;
    
    adj = new list<int>[vertices];
    
    for(int i = 0 ; i < vertices; i++)
    {
        indegree.push_back(0);
    }
}

int Graph::getVertices()
{
    return this->vertices;
}

void Graph::displayIndegree() {
    string indegree="->";
    
    for(int a : this->indegree)
    {
        cout << a<<endl;
    }
    
}

void Graph::addEdge(int u, int v) {
    indegree[v]++;
    
    adj[v].push_back(u);
}

void Graph::findPossibleTopologicalTraversal() {

    int total_queue;
    for(int i = 0 ; i < this->vertices; i++)
    {
        if(indegree[i] == 0)
        {
            cout << "Create a new Queue\n" << i+1 << endl;
            
            
        }
    }
    
}

int main(int argc, char** argv) {

    Graph g(6);
    
    cout << "Initialized Values are " <<endl;
    
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    
    g.displayIndegree();
    
    cout << "All Topological sorts\n";
    
    g.findPossibleTopologicalTraversal();
    
    return 0;
}

