#include"Graphlink.h"
#include"Edge-Vertex.h"
const int max = 0x7fffffff;
template<typename T>
void Graphlink<T>::shortestPath(int v, int* dist, int* path) {
	int n = getmaxVertices();
	bool* S = new bool[n];
	int w, min;
	for (int i = 0; i < n; i++) {
		dist[i] = getWeight(v, i);
		S[i] = false;
		if (i != v && dist[i] < max)path[i] = v;
		else path[i] = -1;
	}
	S[v] = true;
	dist[v] = 0;
	for (int i = 0; i < n - 1; i++) {
		min = max;
		int u = v;
		for (int j = 0; j < n; j++)
			if (S[j] == false && dist[j] < min) { u = j; min = dist[j]; }
		S[u] = true;
		for (int k = 0; k < n; k++) {
			w = getWeight(u, k);
			if (S[k] == false && w < max && dist[u] + w < dist[k]) {
				dist[k] = dist[k] + w;
				path[k] = u;
			}
		}
	}
};
template <typename T>
void Graphlink<T>::printShortestPath(T vertex) {
	int num = getnumVertices();
	int* dist = new int[num];
	int* path = new int[num];
	int* d = new int[num];
	int v = getVertexPos(vertex);
	shortestPath(v, dist, path);
	cout << "顶点" << vertex << "的路由选择表：" << endl;
	for (int i = 0; i < num; ++i) {
		if (i != v) {
			int k = 0;
			for (int j = i; j != v; ++k) {
				d[k] = j;
				j = path[j];
			}
			cout << "顶点" << getValue(i) << "的最短路径为：" << getValue(v);
			for (int j = k-1; j>=0 ; --j) {cout << ' ' << getValue(d[j]) ;}
			cout << endl;
			cout << "最短路径长度：" << dist[i] << endl;
		}
	}
	delete[]d;
	delete[]dist;
	delete[]path;
}