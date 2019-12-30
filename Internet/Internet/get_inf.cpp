#include"Graph.h"
int Graphlink::getWeight(int v1, int v2) {
	if (v1 != -1 && v2 != -1) {
		Edge* p = Table[v1].adj;
		while (p != nullptr) {
			if (p->dest == v2) {
				return p->cost;
			}
			p = p->link;
		}
	}
	return max;
}
int Graphlink::getVertexPos(const int vertex) {//给出顶点vertex在图中的位置，下标
	for (int i = 0; i < maxVertices; i++)
		if (Table[i].data == vertex)return i;
	return -1;
}
int Graphlink::getFirstNeighbor(int v) {
	if (v != -1) {//顶点存在
		if (Table[v].adj != nullptr)//有边
			return (Table[v].adj)->dest;//返回邻接顶点
	}
	return -1;//邻接顶点不存在
}

int Graphlink::getNextNeighbor(int v, int w) {
	if (v != -1) {//顶点存在
		Edge* p = Table[v].adj;
		while (p != nullptr && p->dest != w)//寻找邻接顶点w
			p = p->link;
		if (p != nullptr && p->link != nullptr)
			return p->link->dest;//返回下一个邻接顶点
	}
	return -1;//下一个邻接顶点
}

int Graphlink::getNeighbor(Edge*& pEdge) {//取v关于边pEdge的邻接顶点
	if (pEdge != nullptr) {
		int m = pEdge->dest;
		pEdge = pEdge->link;
		return m;
	}
	else return -1;
}