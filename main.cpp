#include "Graph.h"

int main(int argc, char* argv[])
{
	Graph g(4);
	g.addEdgeD(0, 1);
	g.addEdgeD(0, 2);
	g.addEdgeD(1, 2);
	g.addEdgeD(2, 0);
	g.addEdgeD(2, 3);
	g.addEdgeD(3, 3);

	g.print();
	g.BFS(2);
	g.DFSRecursive(2);
	return 0;
}
