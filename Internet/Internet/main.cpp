#include<iostream>
#include<fstream>
#include"all.h"
int main() {
	Graphlink<int> graph(20);
	int m, n=0, cost;
	char ch='c';
	ifstream in;
	in.open("input.txt");
	while (ch != '\n') {//ÊäÈë½Úµã
		in >> m;
		if(!graph.insertVertex(m))
			cerr<<"´íÎó£¡£¡£¡";
		in.get(ch);
	}
	while (in.eof() == false) {
		in >> m >> n >> cost;
		m = graph.getVertexPos(m);
		n = graph.getVertexPos(n);
		graph.insertEdge(m, n, cost);
	}
	cin >> m;
	graph.printShortestPath(m);
	in.close();
	cout << graph;
	return 0;
}