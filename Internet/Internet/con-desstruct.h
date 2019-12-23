#include"Graphlink.h"
template <typename T>
Graphlink<T>::Graphlink(int sz) :numVertices(0), numEdges(0),maxVertices(20){
	maxVertices =maxVertices > sz? maxVertices:sz;
	Table = new Vertex<T>[maxVertices];//´´½¨´æ´¢¿Õ¼ä
	if (Table == nullptr) { cerr << "·ÖÅäÊ§°Ü!!!" << endl; exit(1); }
}
template <typename T>
Graphlink<T>::~Graphlink() {
	if (Table != nullptr) {//´æÔÚ¶¥µã
		Edge* p = nullptr;
		for (int i = numVertices - 1; i >= 0; i--) {
			p = Table[i].adj;
			while (p != nullptr) {//É¾³ý±ß
				Table[i].adj = p->link;
				delete p;
				p = Table[i].adj;
			}
		}
		delete[] Table;
	}
}
