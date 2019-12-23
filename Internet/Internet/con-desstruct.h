#include"Graphlink.h"
template <typename T>
Graphlink<T>::Graphlink(int sz) :numVertices(0), numEdges(0),maxVertices(20){
	maxVertices =maxVertices > sz? maxVertices:sz;
	Table = new Vertex<T>[maxVertices];//�����洢�ռ�
	if (Table == nullptr) { cerr << "����ʧ��!!!" << endl; exit(1); }
}
template <typename T>
Graphlink<T>::~Graphlink() {
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
