#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph {
public:
	unordered_map<T, list<T>> adjlist;

	void AddEdge(T u, T v, bool direction) {
		adjlist[u].push_back(v);
		if (direction == 0) {
			adjlist[v].push_back(u);
		}
	}

	void TopoSortUsingDfs(int src, unordered_map<int, bool>& visited, stack<int>& stack) {
		visited[src] = true;
		for (auto nbr : adjlist[src]) {
			if (!visited[nbr]) {
				TopoSortUsingDfs(nbr, visited, stack);
			}
		}
		stack.push(src);
	}

	// This is Kahn's Algorithm for topological sort using BFS
	void TopoSortUsingBfs(int n, unordered_map<int, bool>& visited, queue<int>& q) {
		// Step 1: Calculate the indegree of each vertex
		unordered_map<int, int> indegree;

		// Initialize indegree for each node to 0
		for (int i = 0; i < n; i++) {
			indegree[i] = 0;
		}

		for (auto node : adjlist) {
			int src = node.first;
			for (auto nbr : node.second) {
				indegree[nbr]++;
			}
		}

		// Step 2: Push all nodes with indegree 0 into the queue
		for (auto node : indegree) {
			if (node.second == 0) {
				q.push(node.first);
			}
		}

		// Step 3: Process nodes from the queue
		while (!q.empty()) {
			int curr = q.front();
			q.pop();
			cout << curr << " ";  // Process the node

			// Decrease the indegree of neighbors
			for (auto nbr : adjlist[curr]) {
				indegree[nbr]--;
				if (indegree[nbr] == 0) {
					q.push(nbr);
				}
			}
		}
	}
};

int main() {
	Graph<int> g;
	int n = 5;
	g.AddEdge(0, 1, 1);
	g.AddEdge(1, 2, 1);
	g.AddEdge(2, 3, 1);
	g.AddEdge(3, 4, 1);

	// Using DFS-based topological sort (optional code)
	// stack<int> s;
	// unordered_map<int, bool> visited;
	// for (int i = 0; i < n; i++) {
	//     if (!visited[i]) {
	//         g.TopoSortUsingDfs(i, visited, s);
	//     }
	// }
	// cout << "TopoSort using DFS: ";
	// while (!s.empty()) {
	//     cout << s.top() << " ";
	//     s.pop();
	// }

	// Using BFS-based topological sort
	queue<int> q;
	unordered_map<int, bool> visited;
	cout << "TopoSort using BFS (Kahn's Algorithm): ";
	g.TopoSortUsingBfs(n, visited, q);
	cout << endl;

	return 0;
}
