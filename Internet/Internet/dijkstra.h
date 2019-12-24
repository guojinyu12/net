#include"Graphlink.h"
#include"Edge-Vertex.h"
template<typename T>
void Graphlink<T>::shortestPath(int v, int* dist, int* path) {
	int num = getnumVertices();
	bool* know = new bool[num];//当i路径确定时，know[i]=true
	int w, min;
	for (int i = 0; i < num; i++) {//初始化
		dist[i] = getWeight(v, i);
		know[i] = false;//初始化
		if (i != v&&dist[i]<max )path[i] = v;
		else path[i] = -1;
	}
	know[v] = true;dist[v] = 0;
	int u = v;
	for (int i = 0; i < num; i++) {
		min = max;
		for (int j = 0; j < num; j++) {
			if (know[j] == false && dist[j] < min)
			{
				u = j; min = dist[j];
			}
		}
		know[u] = true;
		for (int k = 0; k < num; k++) {
			w = getWeight(u, k);
			if (know[k] == false && w < max && dist[u] + w < dist[k]) {
				dist[k] = dist[u] + w;
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
	if (v == -1) {
		cout << "路由器" << vertex << "不存在。"<<endl;
		return;
	}
	shortestPath(v, dist, path);
	cout << "路由器" << vertex << "的路由选择表：" << endl;
	for (int i = 0; i < num; ++i) {
		if (i != v) {
			int k = 0;
			for (int j = i; j != v&&j!=-1; ) {
				d[k] = j;
				j = path[j]; ++k;
			}
			if (dist[i] != max) {
				cout << "到路由器" << getValue(i) << "的最短路径为：" << getValue(v);
				for (int j = k - 1; j >= 0; --j) { cout << ' ' << getValue(d[j]); }
				cout << endl;
				cout << "最短路径长度：";
				cout << dist[i] << endl;
			}
			else{
				cout << "不可到达路由器" << getValue(i) <<endl;
			}
			cout << "到路由器" << getValue(i) << "下一跳为"<<getValue(d[0])<<endl;
		}
	}
	delete[]d;
	delete[]dist;
	delete[]path;
}