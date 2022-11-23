#include "Main.h"
#include "Dijkstra.h"

int map[V][V] = {
	0, 7, 9, 0, 0, 0,
	7, 0, 10, 15, 0, 0,
	9, 10, 0, 11, 0, 2,
	0, 15, 11, 0, 6, 0,
	0, 0, 0, 6, 0, 9,
	14, 0, 2, 0, 9, 0
};

int main() {
	start();

	return 0;
}

void start() {
	int node;

	while (1) {
		printf("\n\n\t������: ");
		scanf_s("%d", &node);

		clear();
		printf("\n\n\t{ Start Node: %d }", node);

		if (node == 0) {
			clear();
			printf("\n\n\t���α׷��� ����˴ϴ�.\n");
			return;
		}

		if (node > V) {
			printf("\t\t����� ������ �ʰ��Ͽ����ϴ�.\n");
			continue;
		}

		dijkstra(map, node - 1);
	}
}

void clear() {
	system("cls");
}