#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//find the position that the distance is shortest
int mindist(vector<int> distance, vector<int> checker) {
	int min = INT_MAX, pos, n = distance.size();

	for (int i = 0; i < n; i++) {
		if (checker[i] == 0 && distance[i] < min) {
			min = distance[i];
			pos = i;
		}
	}

	return pos;
}

//find the longest distance using Djkstra algorithm
int Dijkstra(vector<vector<int>> graph, int vertex) {
	int longest, n = graph.size();
	vector<int> distance(graph.size(), INT_MAX), checker(n, 0);
	distance[vertex] = 0;

	for (int i = 0; i < n; i++) {
		int u = mindist(distance, checker);

		//mark as visited
		checker[u] = 1;

		//update shortest path
		for (int j = 0; j < n; j++) {
			if (checker[j] == 0 && graph[u][j] && distance[u] != INT_MAX && distance[u] + graph[u][j] < distance[j])
				distance[j] = distance[u] + graph[u][j];
		}
	}
	
	longest = *max_element(distance.begin(), distance.end());

	return longest;
}

int main() {
	int n, m, res = 0;

	cin >> n >> m;

	vector<vector<int>> graph(n, vector<int>(n, 0));

	// build an undirected adjacency matrix
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		graph[x - 1][y - 1] = w;
		graph[y - 1][x - 1] = w;
	}

	//performing Dijkstra on each vertex to find diameter
	for (int v = 0; v < n; v++) {
		int temp = Dijkstra(graph, v);
		if (temp > res)
			res = temp;
	}

	//retrun diameter
	cout << res;
}