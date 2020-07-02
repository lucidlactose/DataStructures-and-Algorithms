#include "printArray.cpp"

// Unliked a Stack, you can implement a Queue using a singly linked list
struct node {
	int data;
	node* next;
	node (int data) {
		this->data = data;
		next = nullptr;
	}
};

class Queue {
	node* head;
	node* tail;
	int sz;
public:
	Queue(): head(nullptr), sz(0) {}
	~Queue() {
		while(!empty()) {
			pop();
		}
	}

	// O(1)
	int size() {
		return sz;
	}

	// O(1)
	bool empty() {
		return head == nullptr;
	}

	// O(1)
	int front() {
		if (!empty()) {
			return head->data;
		}
		return -1;
	}

	// O(1)
	void pop() {
		if (!empty()) {
			node* temp = head;
			head = head->next;
			if (temp == tail) {
				tail = nullptr;
			}
			delete temp;
			sz--;
		}
	}

	// O(1)
	void push(int data) {
		if (!head) {
			head = new node(data);
			tail = head;
		}
		else {
			tail->next = new node(data);
			tail = tail->next;
		}
		sz++;
	}
};


int main() {
	Queue q;

	// empty case
	q.pop();
	cout << "EMPTY CASE: " << q.front() << " " << q.size() << " " << q.empty() << endl;

	// single case
	q.push(100);
	cout << "SINGLE CASE: " << q.front() << " " << q.size() << " " << q.empty() << endl;

	// many case
	for (int i=13; i < 30; ++i) {
		q.push(i);
	}
	cout << "MANY CASE: " << q.front() << " " << q.size() << " " << q.empty() << endl;

	// delete everything
	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}
	cout << "DELETE CASE: " << q.front() << " " << q.size() << " " << q.empty() << endl;

	// mixed case
	q.push(6);
	q.push(7);
	q.push(21);
	cout << "MIXED CASE: " << q.front() << endl;
	q.pop();
	cout << q.front() << endl;
	q.pop();
	q.pop();
	cout << q.front() << endl;
	

	return 0;
}
