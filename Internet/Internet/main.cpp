#include<iostream>
#include"all.h"
int main() {
	Graphlink<int> graph(20);
	int m, n, cost;
	cin >> m;
	graph.insertVertex(m);
	cin >> m >> n >> cost;
	m = graph.getVertexPos(m);
	m = graph.getVertexPos(n);
	graph.insertEdge(m, n, cost);
	return 0;
}