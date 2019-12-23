struct Edge {//�߽��Ķ���
	int m_dest;	//�ߵ���һ����λ��
	int m_cost;
	Edge* link;//��һ������ָ��
	Edge() : m_dest(0), m_cost(0), link(nullptr) {}//Ĭ�Ϲ��캯��
	Edge(int num,int cost, Edge* p) : m_dest(num),m_cost(cost), link(p) {}//���캯��
	int getWeight() { return m_cost; }
	bool operator != (Edge& R)const { return m_dest != R.m_dest; }//�����ڱȽ����������
};
template <typename T>
struct Vertex {//����Ķ���
	T data;//��������
	Edge* adj;//�������ͷָ��
	Vertex() :adj(nullptr) {}//Ĭ�Ϲ��캯��
	Vertex(T x) :data(x), adj(nullptr) {}//���캯��
};