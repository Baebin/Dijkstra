#include <stdio.h>
#include <limits.h>

// λΈλ κ°μ
#define V 6

int findNearestNode(int cost[V], int pass[V]);
void dijkstra(int map[V][V], int start);
void printCost(int start, int end, int cost);
