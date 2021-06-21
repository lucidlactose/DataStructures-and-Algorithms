#include "printArray.cpp"
#include <unordered_map>

/*
	Complexity: O(V + E)
	Explanation: This is a modified DFS that travels each edge (E) until
		it visits each vertex (V).

		Since it loops through every vertice and at each vertice
		we visit every edge not visited, it is O(V + E). If it visited
		every vertex repeatedly, then it would be O(V + V * E).
*/

void mDFS(Graph g) {
	// you could store it how you want, a stack, queue, or vector
	vector<int> topo;


	// we just need to know if we visited, so we could use other DS
	// such as arrays, sets, or map, but if the implementation uses a
	// tree instead of a hash, the calculation of big O is different
	unordered_map<Node*, bool> visited;

	for (Node* node: g->vertices) {
		if (!visited.contains(node)) {
			mDFS(node, topo, visited);
		}
	}

	// congrats, you got everything, now do what you want
	printArray(topo);
}

void mDFS( Node* curr, vector<int>& topo, unordered_map<Node*, bool>& visited ) {
	visited[curr] = true;

	for (Node* node: curr->neighbors) {
		if (!visited[node]) {
			mDFS(node, topo, visited);
		}
	}

	topo.push_back(curr);
}
