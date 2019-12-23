#include"Graphlink.h"
template <typename T>
int Graphlink<T>::getWeight(int v1, int v2) {
	if (v1 != -1 && v2 != -1) {
		Edge* p = Table[v1].adj;
		while (p != nullptr && p->dest) {
			p = p->link;
		}
		if (p != nullptr) {
			return p->cost;
		}
	}
	return -1;
}
template <typename T>
int Graphlink<T>::getVertexPos(const T vertex) {//��������vertex��ͼ�е�λ�ã��±�
	for (int i = 0; i < maxV; i++)
		if (Table[i].data == vertex)return i;
	return -1;
}
template <typename T>
int Graphlink<T>::getFirstNeighbor(int v) {
	if (v != -1) {//�������
		if (Table[v].adj != nullptr)//�б�
			return (Table[v].adj)->dest;//�����ڽӶ���
	}
	return -1;//�ڽӶ��㲻����
}
template <typename T>
int Graphlink<T>::getNextNeighbor(int v, int w) {
	if (v != -1) {//�������
		Edge* p = Table[v].adj;
		while (p != nullptr && p->dest != w)//Ѱ���ڽӶ���w
			p = p->link;
		if (p != nullptr && p->link != nullptr)
			return p->link->dest;//������һ���ڽӶ���
	}
	return -1;//��һ���ڽӶ���
}