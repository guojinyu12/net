#include"Edge-Vertex.h"
ostream& operator << (ostream& os, Edge& e) {//���
	return os << e.dest << "  " << e.cost;
}
ostream& operator << (ostream& os, Vertex& v) {//���
	return os << v.data;
}