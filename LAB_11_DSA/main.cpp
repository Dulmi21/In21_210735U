#include <bits/stdc++.h>
using namespace std;


#define V 6  // 6 vertices in the given grapg


int minimumKey(int key[], bool isMST[])
{
	// this function finds the intial key with minimum value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (isMST[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}




void primMST(int graph[V][V])
{

	int parent[V];
	int key[V];
	bool isMST[V];


	for (int i = 0; i < V; i++)  // intializing all keys to INT_MAX
		key[i] = INT_MAX, isMST[i] = false;

	key[0] = 0;


	parent[0] = -1;  // TAKE 0 AS THE ROOT


	for (int count = 0; count < V - 1; count++) {


		int u = minimumKey(key, isMST);

		// Add the picked vertex to the MST Set
		isMST[u] = true;


		for (int v = 0; v < V; v++ )

			    if (graph[u][v] && isMST[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	// Print
	cout << "Edge \t\tWeight\n\n";
	for (int i = 1; i < V; i++)
		cout << parent[i] << " - " << i << " \t\t"
			<< graph[i][parent[i]] << " \n\n";

}


int main(){
int graph[V][V] = { { 0, 3, 0, 0,0, 1 },
                       { 3, 0,2, 1,10, 0  },
						{ 0, 2, 0,3,0,5  },
						{ 0, 1, 3, 0,5, 0  },
						{  0, 10, 0, 5,0, 4  },
						{ 1, 0, 5, 0,4, 0 } };



	primMST(graph);



	return 0;
}

