#ifndef GRAPHLINK_H_
#define GRAPHLINK_H_
#include"Edge-Vertex.h"
const int max = 0x7ffff;
class Graphlink;
class Graphlink {   //ͼ���ඨ��
	int maxVertices;//��󶥵������ܵذ���
	int numVertices;//��ɫ�ذ���
	int numEdges;//����
	Vertex* Table;//����� (���������ͷ���)
public:
	Graphlink(int sz);//���캯��
	~Graphlink();//��������
	int getE() { return numEdges; }//����
	int getmaxVertices() { return maxVertices; }//������
	int getnumVertices() { return numVertices; }//����
	int getValue(int i) { return Table[i].data; }//ȡλ��Ϊi�Ķ����ֵ
	int getVertexPos(const int vertex);//��������vertex��ͼ�е�λ�ã��±�
	bool insertVertex(const int& vertex);//����һ������
	int getWeight(int v1, int v2);//����
	bool RemoveVertex(const int& vertex);//ɾ����
	bool insertEdge(int v1, int v2, int cost);//����һ����
	bool RemoveEdge(int v1, int v2);//ɾ����
	int getFirstNeighbor(int v);//ȡv�ĵ�һ���ڽӶ���
	int getNextNeighbor(int v, int w);//ȡv���ڽӶ���w����һ�ڽӶ��� 
	int getNeighbor(Edge*& pEdge);//ȡv���ڱ�pEdge���ڽӶ���
	void shortestPath(int v, int* dist, int* path);//�Ǹ�Ȩֵ�����·��
	void printShortestPath(int v);
	friend ostream& operator << (ostream& os, Graphlink& G);
};
#endif // !GRAPHLINK_H_
