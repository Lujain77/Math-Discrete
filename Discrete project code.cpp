#include <bits/stdc++.h>
using namespace std;
class Graph {
	int X;
	list<int>* adj;

public:
	Graph(int X);
	void AddEdge(int x, int y);
	void TwoEdges(int x);
};
Graph::Graph(int X)
{
	this->X = X;
	adj = new list<int>[X];
}
void Graph::AddEdge(int x, int y)
{
	adj[x - 1].push_back(y - 1);
	adj[x - 1].push_back(y - 1);
}
void Graph::TwoEdges(int x)
{
	int NoEdges[x];

	for (int z = 0; z < x; z++) {
		NoEdges[z] = adj[z].size();
	}

	bool graph = true;
	for (int z = 0; z < x; z++) {

		if (NoEdges[z] < 2) {
			graph = false;
			break;
		}
	}
	if (graph)
		cout << "Yes";
	else
		cout << "No";
}
int main()
{
	int X = 8;
	int E = 10;
	int Edges[E][2] = { { 1, 2 }, { 1, 5 }, { 1, 8 },
						{ 2, 3 }, { 5, 4 }, { 8, 7 },
						{ 3, 4 }, { 4, 9 }, { 7, 6 },
						{ 7, 8 } };
	Graph g(X);
	for (int z = 0; z < E; z++) {
		g.AddEdge(Edges[z][0], Edges[z][1]);
	}
	g.TwoEdges(X);

	return 0;
}
