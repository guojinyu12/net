#include"Graphlink.h"

ostream& operator << (ostream& os, Graphlink& G) {//����
	Edge *p= nullptr;
	for (int i = 0; i < G.numVertices; i++) {
			os << G.Table[i] << endl;
			p = G.Table[i].adj;//��ʼ��
			while (p != nullptr) {
				os << G.Table[i] <<"  "<< G.Table[p->dest]
					<<"  "<<p->cost<<endl;
				p = p->link;//����
			}
		cout << endl;
	}
	return os;
}
