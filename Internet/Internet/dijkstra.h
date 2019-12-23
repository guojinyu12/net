#include"Graphlink.h"
#include"Edge-Vertex.h"
const int max = 0x7fffffff;
template<typename T>
int getnumV(Graphlink<T>& G, T v, int dist[], int path[]) {
	int n = G.getmaxV();
	bool* S = new bool[n];
	int i, j, k;
	int w, min;
	for (i = 0; i < n; i++) {
		dist[i] = G.getWeight(v, i);
		S[i] = false;
		if (i != v && dist[i] < max)path[i] = v;
		else path[i] = -1;
	}
	S[v] = true;
	dist[v] = 0;
	for (i = 0; i < n - 1; i++) {
		min = max;
		int u = v;
		for (j = 0; j < n; j++)
			if (S[j] == false && dist[j] < min) { u = j; min = dist[j]; }
		S[u] = true;
		for (k = 0; k < n; k++) {
			w = G.getWeight(u, k);
			if (S[k] == false && w < max && dist[u] + w < dist[k]) {
				dist[k] = dist[k] + w;
				path[k] = u;
			}
		}
	}
};