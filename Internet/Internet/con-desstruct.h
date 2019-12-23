#include"Graphlink.h"
template <typename T>
Graphlink<T>::Graphlink(int sz) :numV(0), numE(0) {
	int max=maxV > sz? maxV:sz;
	Table = new Vertex<T>[max];//�����洢�ռ�
	if (Table == nullptr) { cerr << "����ʧ��!!!" << endl; exit(1); }
}
template <typename T>
Graphlink<T>::~Graphlink() {
	if (Table != nullptr) {//���ڶ���
		Edge* p = nullptr;
		for (int i = numV - 1; i >= 0; i--) {
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
