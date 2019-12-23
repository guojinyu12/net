#ifndef GRAPHLINK_H_
#define GRAPHLINK_H_
#include"Edge-Vertex.h"
template <typename T>
class Graphlink;
template <typename T>
ostream& operator << (ostream& os, Graphlink<T>& G);
template <typename T>
class Graphlink {   //图的类定义
	int maxVertices;//最大顶点数，总地板数
	int numVertices;//黑色地板数
	int numEdges;//边数
	Vertex<T>* Table;//顶点表 (各边链表的头结点)
public:
	Graphlink(int sz);//构造函数
	~Graphlink();//析构函数
	int getE() { return numEdges; }//边数
	int getmaxVertices() { return maxVertices; }//最大点数
	int getnumVertices() { return numVertices; }//点数
	T getValue(int i) { return Table[i].data; }//取位置为i的顶点的值
	int getVertexPos(const T vertex);//给出顶点vertex在图中的位置，下标
	bool insertVertex(const T& vertex);//插入一个顶点
	int getWeight(int v1, int v2);//代价
	bool RemoveVertex(const T& vertex);//删除点
	bool insertEdge(int v1, int v2,int cost);//插入一条边
	bool RemoveEdge(int v1, int v2);//删除边
	int getFirstNeighbor(int v);//取v的第一个邻接顶点
	int getNextNeighbor(int v, int w);//取v的邻接顶点w的下一邻接顶点 
	int getNeighbor(Edge*& pEdge);//取v关于边pEdge的邻接顶点
	void shortestPath(int v, int* dist, int* path);//非负权值的最短路径
	void printShortestPath(T v);
	template <typename T>
	friend ostream& operator << <T>(ostream& os, Graphlink<T>& G);
};
#endif // !GRAPHLINK_H_
