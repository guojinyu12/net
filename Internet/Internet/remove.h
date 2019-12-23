#include"Graphlink.h"
template<typename T>
bool Graphlink<T>::RemoveEdge(int v1, int v2)
{
	if (v1 != -1 && v2 != -1)
	{
		Edge<T>* p = Table[v1].adj, * q = nullptr, * s = p;
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
			p = q;
			p = p->link;
		}
		if (p == s)Table[v2].adj = p->link;
		else q->link = p->link;
		delete p;
		return true;
	}
	return false;
}

template<typename T>
bool Graphlink<T>::RemoveVertex(const T& vertex)
{
	if (numV == 1 || vertex<0 || vertex>=numV)return false;
	Edge<T>* p, * s, * t;
	int i, k;
	while (Table[vertex].adj != nullptr)
	{
		p = Table[vertex].adj;
		k = p->dest;
		s = Table[k].adj;
		t = nullptr;
		while (s != nullptr && s->dest != vertex)
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
		Table[vertex].adj = p->link;
		delete p;
		numE--;
	}
	numV--;
	Table[vertex].data = Table[numV].data;
	p = Table[vertex].adj = Table[numV].adj;
	while (p != nullptr)
	{
		s = Table[p->dest].adj;
		while (s != nullptr)
		{
			if (s->dest == numV)
			{
				s->dest = v;
				break;
			}
			else
				s = s->link;
		}
	}
	return true;
}