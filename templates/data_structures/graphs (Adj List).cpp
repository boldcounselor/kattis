//Credit to geeksforgeeks.org for the original implementations of the graph.
#include <bits/stdc++.h> 

using namespace std;
# define INF 0x3f3f3f3f 

//Typedefs
typedef pair<int, float> pif;
typedef pair<float, int> pfi;

//Directed graph w/ adj list representation
class Graph {
    private:
        //no. of vertices
        int V;
        //adj list
        list<pif> *adj;
    public: 
        //constructor
        Graph(int V);
        // function to add an edge to graph 
        void addEdge(int u, int v, float w); 
        // finds shortest path from s and saves it in dist
        void shortestPath(int s); 
        vector<float> dist;

}; 
  
// Allocates memory for adjacency list 
Graph::Graph(int V) 
{ 
    this -> V = V; 
    adj = new list<pif> [V]; 
    dist.assign(V,INF);
} 

void Graph::addEdge(int u, int v, float w) 
{ 
    adj[u].push_back(make_pair(v, w)); 
} 
  
// Prints shortest paths from src to all other vertices 
void Graph::shortestPath(int src) 
{ 
    // Create a priority queue to store vertices that 
    // are being preprocessed. This is weird syntax in C++. 
    // Refer below link for details of this syntax 
    // https://www.geeksforgeeks.org/implement-min-heap-using-stl/ 
    priority_queue<pfi, vector <pfi> , greater<pfi>> pq; 

    // Insert source itself in priority queue and initialize 
    // its distance as 0. 
    pq.push(make_pair(float(0), src)); 
    dist[src] = float(0); 

    /* Looping till priority queue becomes empty (or all 
      distances are not finalized) */
    while (!pq.empty()) 
    { 
        // The first vertex in pair is the minimum distance 
        // vertex, extract it from priority queue. 
        // vertex label is stored in second of pair (it 
        // has to be done this way to keep the vertices 
        // sorted distance (distance must be first item 
        // in pair) 
        int u = pq.top().second; 
        pq.pop(); 
  
        // 'i' is used to get all adjacent vertices of a vertex 
        list<pif>::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 
            // Get vertex label and weight of current adjacent 
            // of u. 
            int v = (*i).first; 
            float weight = (*i).second; 
  
            //  If there is shorted path to v through u. 
            if (dist[v] > dist[u] + weight) 
            { 
                // Updating distance of v 
                dist[v] = dist[u] + weight; 
                pq.push(make_pair(dist[v], v)); 
            } 
        } 
    } 
  
    /* Print shortest distances stored in dist[] 
    printf("Vertex   Distance from Source\n"); 
    for (int i = 0; i < V; ++i) 
        printf("%d \t\t %d\n", i, dist[i]);
    */
} 
