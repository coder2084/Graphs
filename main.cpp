#include "Graph.h"

int main(int argc, char* argv[])
{
	Graph g(6);
	g.addEdgeD(5, 2);
	g.addEdgeD(5, 0);
	g.addEdgeD(4, 0);
	g.addEdgeD(4, 1);
	g.addEdgeD(2, 3);
	g.addEdgeD(3, 1);

	g.print();
	g.bfs(2);
	g.dfsRecursive(2);
	g.topologicalSort();
	return 0;
}
