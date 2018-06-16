#include <iostream>
#include <list>
using namespace std;

// https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/


Graphs can be represented in two ways:
- Adjacency Matrix: for this one, its a V*V 2d matrix, where adj[i][j] represents an edge from i to j, so set that bit 1. 
Pros: Removing an edge only takes O(1) time and quering whether there is an edge between i to j, takes only O(1) time. 
COns: Adding a vertex takes O(n^2) and the fact that it consumes way more space. 

- Adjacency List: Creates an array of Linked lists, 
Pros: Saves space : O(V+E), addign a vertex is easier.
COns: Queries like whether there is a link from node i to j, will take O(V) time becuase traverse through the lists. 



// All the things DFS is used for
// - Detecting a cycle in the graph 
// - Path Finding 
// - Topological Sorting
// - To test if the graph is bipartite 
// - FInding Strongly Connected Components of a graph 
// - Solving puzzzles with only one solution.

// Breadth First Traversal Applications 
// Shortest Path and Minimum Spanning tree for unweighted graphs
// Peer to Peer Network : FInd all neighbour nodes
// Crawlers in Search Engines 
// Social Networking Websites 
// GPS navigation systems: BFS is used to find all neighbouring locations
// Broadcasting in Networks
// In Garbage Collection
// Cycle Detection in undirected graph 


class Graph{
	int v; //No.of vertices 
	list<int> *adj; //Pointer to an array containing adjacency lists
	void DFSUtil(int v, bool visited[]);
public:
	Graph(int v);
	void addEdge(int v, int w);
	void DFS(int v);
	void BFS(int s);
}

// Depth First Search 

Graph::Graph(int v){
	this->v = v;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}

// Depth First Search Implementation
void Graph::DFSUtil(int n, bool visited[]){
	visited[n] = true;
	cout << n << " ";
	list<int>::iterator i;
	for(i = adj[n].begin(); i != adj[n].end(); ++i){
		if(!visited[*i]){
			DFSUtil(*i,visited);
		}
	}
}

void Graph::DFS(Nodes* n){
	bool *visited = new bool[V];
	//Mark all bool as not visited 
	for(int i = 0; i < V; i++){
		visited[i] = false;
	}
	DFSUtil(n, visited)
}

// Breadth First Search Implementation
void BFS(int s){
	bool *visited = new bool[V];
	//Mark all bool as not visited 
	for(int i = 0; i < v; i++){
		visited[i] = false;
	}
	list<int> queue;
	visited[s] = true;
	queue.push_back(s);
	list<int>::iterator i;
	
	while(!queue.empty()){
		s = queue.front();
		cout << s << " " <<;
		queue.pop_front();
		for(i = adj[s].begin(); i != adj[s].end(); ++i){
			if(!visited[*i]){
			visited[*i] = true;
			queue.push_back(*i);
			}
		}
	}
}

// Detection of a cycle in a graph: this is a simple modification to the DFS algorithm. 
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if(visited[v] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;
 
        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }
 
    }
    recStack[v] = false;  // remove the vertex from recursion stack
    return false;
}
 
// Returns true if the graph contains a cycle, else false.
// This function is a variation of DFS() in https://www.geeksforgeeks.org/archives/18212
bool Graph::isCyclic()
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
 
    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for(int i = 0; i < V; i++)
        if (isCyclicUtil(i, visited, recStack))
            return true;
 
    return false;
}
// Djikstra's algorithm: 



//

