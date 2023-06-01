
#include <iostream>
using namespace std;
#include <limits.h>

#define V 6  //this is the number of nodes given

int minDistance(int dist[], bool isSet[])
{


	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (isSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}




void dijkstra(int graph[V][V], int src)
{
	int dist[V];

	bool isSet[V];
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, isSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++) {

		int u = minDistance(dist, isSet);

		// Mark the picked vertex as processed
		isSet[u] = true;


		for (int v = 0; v < V; v++)


			if (!isSet[v] && graph[u][v]
				&& dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	// print the constructed distance array
	cout << "Vertex \t Distance from Source : " << endl;
	for (int i = 0; i < 6; i++)
		cout << i << " \t\t\t\t" << dist[i] << endl;
}


int main()
{

	/* Let us create the example graph discussed above */
	int graph[V][V] =  {{0,10,0,0,15,5} , {10,0,10,30,0,0} , {0,10,0,12,5,0}, {0,30,12,0,0,20}, {15,0,5,0,0,0},{5,0,0,20,0,0}  };
    cout<<"The sorce is 5:"<<endl;

	dijkstra(graph, 5);

	return 0;
}


