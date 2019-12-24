#include"Graphlink.h"
#include"Edge-Vertex.h"
template<typename T>
void Graphlink<T>::shortestPath(int v, int* dist, int* path) {
	int n = getnumVertices();
	bool* know = new bool[n];//��i·��ȷ��ʱ��know[i]=true
	int w, min;
	for (int i = 0; i < n; i++) {//��ʼ��
		dist[i] = getWeight(v, i);
		know[i] = false;//��ʼ��
		if (i != v&&dist[i]<max )path[i] = v;
		else path[i] = -1;
	}
	know[v] = true;dist[v] = 0;
	for (int i = 0; i < n; i++) {
		min = max;
		cout << min;
		int u = v;
		for (int j = 0; j < n; j++)
			if (know[j] == false && dist[j] < min) 
			{
				u = j; min = dist[j]; 
			}
		know[u] = true;
		for (int k = 0; k < n; k++) {
			w = getWeight(u, k);
			if (know[k] == false && w < max && dist[u] + w < dist[k]) {
				cout <<k << " " <<u << " " << w << endl;
				dist[k] = dist[k] + w;
				path[k] = u;
			}
		}
	}
};
template <typename T>
void Graphlink<T>::printShortestPath(T vertex) {
	int num = getnumVertices();
	int* dist = new int[num] {};
	int* path = new int[num] {};
	int* d = new int[num] {};
	int v = getVertexPos(vertex);
	shortestPath(v, dist, path);
	cout << "����" << vertex << "��·��ѡ���" << endl;
	for (int i = 0; i < num; ++i) {
		if (i != v) {
			int k = 0;
			for (int j = i; j != v; ) {
				d[k] = j;
				j = path[j]; ++k;
			}
			cout << "����" << getValue(i) << "�����·��Ϊ��" << getValue(v);
			for (int j = k-1; j>=0 ; --j) {cout << ' ' << getValue(d[j]) ;}
			cout << endl;
			cout << "���·�����ȣ�" << dist[i] << endl;
		}
	}
	delete[]d;
	delete[]dist;
	delete[]path;
}