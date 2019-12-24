#include<iostream>
#include<fstream>
#include"all.h"
int main() 
{
	cout << "     ����·���������ϵͳ" << endl;
	cout << "*******************************" << endl;
	cout << " 1.�����" << endl;
	cout << " 2.�����" << endl;
	cout << " 3.ɾ����" << endl;
	cout << " 4.ɾ����" << endl;
	cout << " 5.��ʾ·�ɱ�" << endl;
	cout << " 6.��ʾ·����·��ͼ" << endl;
	cout << "*******************************" << endl;
	cout << "������ָ��ѡ�񷽰�:" << endl;

	Graphlink<int> graph(20);
	int m, n = 0, cost;
	char ch = 'c';
	ifstream in;
	in.open("input.txt");
	int key;
	cin >> key;
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
	while (true) 
	{
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
			cout << "������Ҫ��ӱߵ�����·����" << endl;
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
			cout << "��ʾ·�ɱ�" << endl;
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