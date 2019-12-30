#ifndef EDGEVERTEX_H_
#define EDGEVERTEX_H_
#include"using.h"
struct Edge {//�߽��Ķ���
	int dest;	//�ߵ���һ����λ��
	int cost;
	Edge* link;//��һ������ָ��
	Edge() : dest(0), cost(0), link(nullptr) {}//Ĭ�Ϲ��캯��
	Edge(int num,int cost, Edge* p) : dest(num),cost(cost), link(p) {}//���캯��
	int getWeight() { return cost; }
	bool operator != (Edge& R)const { return dest != R.dest; }//�����ڱȽ����������
};
struct Vertex {//����Ķ���
	int data;//��������
	Edge* adj;//�������ͷָ��
	Vertex() :adj(nullptr) {}//Ĭ�Ϲ��캯��
	Vertex(int x) :data(x), adj(nullptr) {}//���캯��
};
ostream& operator << (ostream& os, Edge& e);
ostream& operator << (ostream& os, Vertex& v);
#endif // !EDGEVERTEX_H_