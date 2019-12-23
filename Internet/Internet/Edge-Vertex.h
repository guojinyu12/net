struct Edge {//�߽��Ķ���
	int dest;	//�ߵ���һ����λ��
	int cost;
	Edge* link;//��һ������ָ��
	Edge() : dest(0), cost(0), link(nullptr) {}//Ĭ�Ϲ��캯��
	Edge(int num,int cost, Edge* p) : dest(num),cost(cost), link(p) {}//���캯��
	int getWeight() { return cost; }
	bool operator != (Edge& R)const { return dest != R.dest; }//�����ڱȽ����������
};
template <typename T>
struct Vertex {//����Ķ���
	T data;//��������
	Edge* adj;//�������ͷָ��
	Vertex() :adj(nullptr) {}//Ĭ�Ϲ��캯��
	Vertex(T x) :data(x), adj(nullptr) {}//���캯��
};