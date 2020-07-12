#include "../printArray.cpp"
#include <map>

/*
	Complexity: O(V + E)
	Explanation: This is a topological sort, so this only works on
		acyclic, directed graphs.

		Let's tackle this step by step. V will be used for vertices.
		E for edges.
		
		Step 1 has O(V) since it only goes through vertices.
		Step 2 has O(V) for the same reason.
		Step 3 has O(E) because it only traverses edges. It only
		uses the vertices to get the next edge. This would be O(V * E)
		IF and ONLY IF, a vertices can go to nodes previously visited.
		Since we are toposorting, then it should be impossible.
		Step 4 is negligible since this is after our toposort
*/


struct Node {
	vector<Node*> neighbors;
	int data;
};

struct Graph {
	vector<Node*> vertices;
};

// Step 1: Count the in_nodes for every node
// Step 2: Make a queue and push one or all the nodes with 0 in_nodes
// Step 3: Make a vector/queue for the final result and loop through the queue
//		subtracting the in_nodes if it passes and adding more when
//		their in_nodes turns to 0
//	(Also make a counter if you need to detect loops for the problem)
// Step 4: Do whatever you want with the data structure that now has the
//		resulting topo sort
void Khans(Graph g) {
	map<Node*, int> in_nodes;

	// Step 1
	for (Node* node : g->vertices) {
		in_nodes[node]++;
	}

	// Step 2
	queue<Node*> next;
	// if this doesn't work, use auto
	for (pair<Node*, int>& node: in_nodes) {
		if (node.second == 0) {
			next.push(node.first);
		}
	}

	// Step 3
	vector<int> topo;
	int counter = 0;
	while (!next.empty()) {
		Node* curr = next.top();
		next.pop();
		counter ++;
		topo.push_back(curr);

		for (Node* node: curr->neighbors) {
			in_nodes[node]--;
			if (in_nodes[node] == 0) {
				next.push(node);
			}
		}
	}

	// Step 4
	// no loop if counter == topo size, so now we use our functions/ return it
	if (counter == topo.size()) {
		printArray(topo);
	}
}

int main() {
	Graph g;
	

}
