#include "Graph.h"
Graphlink::Graphlink(int sz) :numVertices(0), numEdges(0),maxVertices(20){
	maxVertices =maxVertices > sz? maxVertices:sz;
	Table = new Vertex[maxVertices];//�����洢�ռ�
	if (Table == nullptr) { cerr << "����ʧ��!!!" << endl; exit(1); }
}
Graphlink::~Graphlink() {
	if (Table != nullptr) {//���ڶ���
		Edge* p = nullptr;
		for (int i = numVertices - 1; i >= 0; i--) {
			p = Table[i].adj;
			while (p != nullptr) {//ɾ����
				Table[i].adj = p->link;
				delete p;
				p = Table[i].adj;
			}
		}
		delete[] Table;
	}
}