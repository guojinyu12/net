#include<iostream>
#include<fstream>
#include"all.h"
int main() {
	Graphlink<int> graph(20);
	int m, n=0, cost;
	char ch=0;
	ifstream in;
	in.open("input.TXT");
	while (ch != '\n') {//ÊäÈë½Úµã
		in >> m;
		graph.insertVertex(m);
		ch=cin.get();
	}
	while (in.eof() == false) {
		in >> m >> n >> cost;
		m = graph.getVertexPos(m);
		n = graph.getVertexPos(n);
		graph.insertEdge(m, n, cost);
	}
	
	graph.RemoveVertex(m);
	graph.RemoveEdge(m, n);
	return 0;
}