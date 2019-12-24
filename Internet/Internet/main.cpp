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
	in >> m;
	while (in.eof() == false) {
		in >> n >> cost;
		graph.insertEdge(m, n, cost);
		in >> m;
	}
	//graph.printShortestPath(m);
	in.close();
	cout << graph;


	///*Graphlink<int> graph(20);
	//int m, n = 0;
	//char ch;
	cin >> m >> n;
	if(graph.RemoveEdge(m, n));
	cout << graph;
	cin >> m;
	if (graph.RemoveVertex(m));
	cout << graph;
	return 0;
}