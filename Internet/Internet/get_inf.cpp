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
int Graphlink::getVertexPos(const int vertex) {//��������vertex��ͼ�е�λ�ã��±�
	for (int i = 0; i < maxVertices; i++)
		if (Table[i].data == vertex)return i;
	return -1;
}
int Graphlink::getFirstNeighbor(int v) {
	if (v != -1) {//�������
		if (Table[v].adj != nullptr)//�б�
			return (Table[v].adj)->dest;//�����ڽӶ���
	}
	return -1;//�ڽӶ��㲻����
}

int Graphlink::getNextNeighbor(int v, int w) {
	if (v != -1) {//�������
		Edge* p = Table[v].adj;
		while (p != nullptr && p->dest != w)//Ѱ���ڽӶ���w
			p = p->link;
		if (p != nullptr && p->link != nullptr)
			return p->link->dest;//������һ���ڽӶ���
	}
	return -1;//��һ���ڽӶ���
}

int Graphlink::getNeighbor(Edge*& pEdge) {//ȡv���ڱ�pEdge���ڽӶ���
	if (pEdge != nullptr) {
		int m = pEdge->dest;
		pEdge = pEdge->link;
		return m;
	}
	else return -1;
}