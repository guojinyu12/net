#include"Graphlink.h"

ostream& operator << (ostream& os, Graphlink& G) {//输入
	Edge *p= nullptr;
	for (int i = 0; i < G.numVertices; i++) {
			os << G.Table[i] << endl;
			p = G.Table[i].adj;//初始化
			while (p != nullptr) {
				os << G.Table[i] <<"  "<< G.Table[p->dest]
					<<"  "<<p->cost<<endl;
				p = p->link;//迭代
			}
		cout << endl;
	}
	return os;
}
