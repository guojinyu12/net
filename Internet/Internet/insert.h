#include"Graphlink.h"
template<typename T>
inline bool Graphlink<T>::insertEdge(int v1, int v2,int cost)
{
	Table[v1].adj = new Edge(v2, cost, Table[v1].adj);
	if(Table[v1].adj==nullptr)
		return false;
	return true;
}
template <typename T>
inline bool Graphlink<T>::insertVertex(const T& vertex) {//插入一个顶点
	if (numV < maxV) {
		Table[numV++].data = vertex;
		return true;
	}
	return false;
}
