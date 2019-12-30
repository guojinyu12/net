#include"Edge-Vertex.h"
ostream& operator << (ostream& os, Edge& e) {//Êä³ö
	return os << e.dest << "  " << e.cost;
}
ostream& operator << (ostream& os, Vertex& v) {//Êä³ö
	return os << v.data;
}