#include"Graph.h"
bool Graphlink::RemoveEdge(int vertex1, int vertex2)
{
	int v1 = getVertexPos(vertex1);
	int v2 = getVertexPos(vertex2);
	if (v1 != -1 && v2 != -1)
	{
		Edge* p = Table[v1].adj, * q = nullptr, * s = p;
		while (p != nullptr && p->dest != v2)
		{
			q = p;
			p = p->link;
		}
		if (p != nullptr)
		{
			if (p == s)Table[v1].adj = p->link;
			else q->link = p->link;
			delete p;
		}
		else return false;
		p = Table[v2].adj;
		q = nullptr;
		s = p;
		while (p->dest != v1)
		{
			q = p;
			p = p->link;
		}
		if (p == s)Table[v2].adj = p->link;
		else q->link = p->link;
		delete p;
		return true;
	}
	return false;
}
bool Graphlink::RemoveVertex(const int& vertex)
{
	int v = getVertexPos(vertex);
	if (numVertices == 0 || v < 0 || v >= numVertices)return false;
	Edge* p, * s, * t;
	int k;
	while (Table[v].adj != nullptr)
	{
		p = Table[v].adj;
		k = p->dest;
		s = Table[k].adj;
		t = nullptr;
		while (s != nullptr && s->dest != v)
		{
			t = s;
			s = s->link;
		}
		if (s != nullptr)
		{
			if (t == nullptr)Table[k].adj = s->link;
			else t->link = s->link;
			delete s;
		}
		Table[v].adj = p->link;
		delete p;
		numEdges--;
	}
	numVertices--;
	Table[v].data = Table[numVertices].data;
	p = Table[v].adj = Table[numVertices].adj;

	while (p != nullptr)
	{
		s = Table[p->dest].adj;
		while (s != nullptr)
		{
			if (s->dest == numVertices)
			{
				s->dest = v;
				break;
			}
			else
				s = s->link;
		}
		p = p->link;
	}
	return true;
}