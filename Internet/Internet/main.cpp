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
	cin >> m;
	while (in.eof() == false) {
		in >> n >> cost;
		m = graph.getVertexPos(m);
		n = graph.getVertexPos(n);
		graph.insertEdge(m, n, cost);
		in >> m;
	}
	//graph.printShortestPath(m);
	in.close();
	//cout << graph;


	/*Graphlink<int> graph(20);
	int m, n = 0;
	char ch;
	cin >> m >> n;*/
	graph.RemoveEdge(m, n);
	cout << graph;
	


	return 0;
}