#include "Dijkstra.h"

// ���� ��� Ž��
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

// ���ͽ�Ʈ��
void dijkstra(int map[V][V], int start) {
	// �ʱⰪ
	int cost[V];
	int pass[V];

	for (int i = 0; i < V; i++) {
		cost[i] = INT_MAX;
	}

	// ���� ����
	cost[start] = 0;

	int stack = 0;
	for (int i = 0; i < V - 1; i++) {
		int newNode = findNearestNode(cost, pass);

		// ��ó ��� Ž��
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