#ifndef EDGEVERTEX_H_
#define EDGEVERTEX_H_
#include"using.h"
struct Edge {//边结点的定义
	int dest;	//边的另一顶点位置
	int cost;
	Edge* link;//下一条边链指针
	Edge() : dest(0), cost(0), link(nullptr) {}//默认构造函数
	Edge(int num,int cost, Edge* p) : dest(num),cost(cost), link(p) {}//构造函数
	int getWeight() { return cost; }
	bool operator != (Edge& R)const { return dest != R.dest; }//不等于比较运算符重载
};
struct Vertex {//顶点的定义
	int data;//顶点内容
	Edge* adj;//边链表的头指针
	Vertex() :adj(nullptr) {}//默认构造函数
	Vertex(int x) :data(x), adj(nullptr) {}//构造函数
};
ostream& operator << (ostream& os, Edge& e);
ostream& operator << (ostream& os, Vertex& v);
#endif // !EDGEVERTEX_H_