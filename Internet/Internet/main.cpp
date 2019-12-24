#include<iostream>
#include<fstream>
#include"all.h"
int main() 
{
	Graphlink<int> graph(20);
	int m, n = 0, cost;
	char ch = 'c';
	ifstream in;
	in.open("input.txt");
	while (ch != '\n') {//输入节点
		in >> m;
		if (!graph.insertVertex(m))
			cerr << "错误！！！";
		in.get(ch);
	}
	in >> m;
	while (in.eof() == false) {
		in >> n >> cost;
		graph.insertEdge(m, n, cost);
		in >> m;
	}
	in.close();
	cout << "     网络路由器表操作系统" << endl;
	cout << "*******************************" << endl;
	cout << " 1.插入点" << endl;
	cout << " 2.插入边" << endl;
	cout << " 3.删除点" << endl;
	cout << " 4.删除边" << endl;
	cout << " 5.显示路由表" << endl;
	cout << " 6.显示路由器路线图" << endl;
	cout << "*******************************" << endl;
	int key;
	while (cin) 
	{
		cout << "请输入指定选择方案:" << endl;
		cin >> key;
		switch (key)
		{
		case 0:
			break;
		case 1:
			cout << "请输入要添加的路由器" << endl;
			cin >> m;
			graph.insertVertex(m);
			break;
		case 2:
			cout << "请输入要添加边的两个路由器及代价" << endl;
			cin >> m >> n >> cost;
			graph.insertEdge(m, n, cost);
			graph.insertEdge(n, m, cost);
			break;
		case 3:
			cout << "请输入要删除的路由器" << endl;
			cin >> m;
			graph.RemoveVertex(m);
			break;
		case 4:
			cout << "请输入要删除边的两个路由器" << endl;
			cin >> m >> n;
			graph.RemoveEdge(m, n);
			break;
		case 5:
			cout << "请输入起点路由器" << endl;
			cin >> m;
			graph.printShortestPath(m);
			break;
		case 6:
			cout << "显示路由器路线图" << endl;
			cout << graph;
			break;
		default:
			break;
		}
	}
	return 0;
}