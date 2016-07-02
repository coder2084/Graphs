#pragma once
#include <forward_list>
#include <list>
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
using std::forward_list;
using std::queue;
using std::list;
using std::vector;
using std::cout;
using std::unordered_map;
using std::endl;

class Graph
{
public:
	Graph(int numVertives) { mAdjList.resize(numVertives); }
	~Graph() {}

	void addEdgeU(int src, int dest)
	{
		mAdjList[src].push_back(dest);
		mAdjList[dest].push_back(src);
	}

	void addEdgeD(int src, int dest)
	{
		mAdjList[src].push_back(dest);
	}

	void clear()
	{
		mAdjList.clear();
	}


	void print()
	{
		for (size_t i = 0; i < mAdjList.size(); ++i)
		{
			cout << i;

			auto elem = mAdjList.at(i).begin();
			while (elem != mAdjList.at(i).end())
			{
				cout << " - > " << *elem;
				elem++;
			}
			cout << endl;
		}
	}

	void BFS(int node = -1)
	{
		queue<int> q;
		vector<bool> visited(mAdjList.size());
		for (size_t i = 0; i < visited.size(); ++i)
			visited[i] = false;

		if (node == -1)
			node = 0;

		q.push(node);
		visited[node] = true;
		while (q.empty() == false)
		{
			int node = q.front();
			q.pop();
			cout << node << " ";
			auto connections = mAdjList[node];
			for (auto elem : connections)
			{
				if (visited[elem] == false)
				{
					visited[elem] = true;
					q.push(elem);
				}
			}
		}

		cout << endl;
	}

	void DFSUtil(int i, vector<bool>& visited)
	{
		visited[i] = true;
		cout << i << " ";
		for (auto elem : mAdjList[i])
			if (!visited[elem])
				DFSUtil(elem, visited);
	}

	void DFSRecursive(int node = -1)
	{
		if (node == -1) node = 0;

		vector<bool> visited(mAdjList.size());
		for (auto elem : visited) elem = false;

		DFSUtil(node, visited);

		cout << endl;
	}

private:
	vector<list<int>> mAdjList;

	
};