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
	while (ch != '\n') {//����ڵ�
		in >> m;
		if (!graph.insertVertex(m))
			cerr << "���󣡣���";
		in.get(ch);
	}
	in >> m;
	while (in.eof() == false) {
		in >> n >> cost;
		graph.insertEdge(m, n, cost);
		in >> m;
	}
	in.close();
	cout << "     ����·���������ϵͳ" << endl;
	cout << "*******************************" << endl;
	cout << " 1.�����" << endl;
	cout << " 2.�����" << endl;
	cout << " 3.ɾ����" << endl;
	cout << " 4.ɾ����" << endl;
	cout << " 5.��ʾ·�ɱ�" << endl;
	cout << " 6.��ʾ·����·��ͼ" << endl;
	cout << "*******************************" << endl;
	int key;
	while (cin) 
	{
		cout << "������ָ��ѡ�񷽰�:" << endl;
		cin >> key;
		switch (key)
		{
		case 0:
			break;
		case 1:
			cout << "������Ҫ��ӵ�·����" << endl;
			cin >> m;
			graph.insertVertex(m);
			break;
		case 2:
			cout << "������Ҫ��ӱߵ�����·����������" << endl;
			cin >> m >> n >> cost;
			graph.insertEdge(m, n, cost);
			graph.insertEdge(n, m, cost);
			break;
		case 3:
			cout << "������Ҫɾ����·����" << endl;
			cin >> m;
			graph.RemoveVertex(m);
			break;
		case 4:
			cout << "������Ҫɾ���ߵ�����·����" << endl;
			cin >> m >> n;
			graph.RemoveEdge(m, n);
			break;
		case 5:
			cout << "���������·����" << endl;
			cin >> m;
			graph.printShortestPath(m);
			break;
		case 6:
			cout << "��ʾ·����·��ͼ" << endl;
			cout << graph;
			break;
		default:
			break;
		}
	}
	return 0;
}