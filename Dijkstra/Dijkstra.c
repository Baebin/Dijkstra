#include "Dijkstra.h"

// 근접 노드 탐색
int findNearestNode(int cost[V], int pass[V]) {
	int min_cost = INT_MAX;
	int min_index = -1;

	for (int i = 0; i < V; i++) {
		if (pass[i] == 1) continue;
		if (cost[i] < min_cost) {
			min_cost = cost[i];
			min_index = i;
		}
	}

	return min_index;
}

// 다익스트라
void dijkstra(int map[V][V], int start) {
	// 초기값
	int cost[V];
	int pass[V];

	for (int i = 0; i < V; i++) {
		cost[i] = INT_MAX;
	}

	// 시작 지점
	cost[start] = 0;

	int stack = 0;
	for (int i = 0; i < V - 1; i++) {
		int newNode = findNearestNode(cost, pass);

		// 근처 노드 탐색
		for (int j = 0; j < V; j++) {
			if (pass[j] == 1) continue;
			if (map[newNode][j] == 0) continue;
			if (cost[newNode] == INT_MAX) continue;

			if (cost[j] > cost[newNode] + map[newNode][j])
				cost[j] = cost[newNode] + map[newNode][j];
			printf("\n\t\t%d. <%d -> %d>", ++stack, newNode+1, j+1);
		}
		pass[newNode] = 1;
	}

	printf("\n");
	for (int i = 0; i < V; i++)
		printCost(start+1, i+1, cost[i]);
}

void printCost(int start, int end, int cost) {
	printf("\n\t\t[%d -> %d]: %d cost", start, end, cost);
}