#include "printArray.cpp"
using namespace std;

// doubly linked list node
// stacks need doubly linked lists to maintain constant complexity
struct node {
	int data;
	node* prev;
	node* next;
	node(int data, node* prev = nullptr, node* next = nullptr) {
		this->data = data;
		this->prev = prev;
		this->next = next;
	}
};

class Stack {
	node* head;
	node* tail;
	int sz;
public:
	// Constructors and especially Desctructors are usually taken into account
	// when calculating dependency. Some languages don't even have destructors
	// so it's usually optional to code one (ask your interviewer but leave until
	// the end)

	// O(1)
	Stack(): head(nullptr), tail(nullptr), sz(0) {}

	// O(n) where n is the total of nodes the stack currently has
	~Stack() {
		node* curr = head;

		while (curr) {
			node* next = curr->next;
			delete curr;
			curr = next;
		}
	}

	// O(1)
	bool empty() {
		return head == nullptr;
	}

	// O(1)
	int size() {
		return sz;
	}

	// O(1)
	int top() {
		if (!empty())
			return tail->data;
		return -1;
	}

	// O(1)
	void push(int data) {
		if (!head) {
			head = new node(data);
			tail = head;
		}
		else {
			tail->next = new node(data, tail);
			tail = tail->next;
		}
		sz++;
	}

	// O(1)
	// Sometimes people want pop to return the popped value.
	// This doesn't do that, but if you want, call and save top()
	// at the start of the function and return that value at the end
	int pop() {
		
		if (tail) {
			if (head == tail) {
				delete head;
				head = nullptr;
				tail = nullptr;
			}
			else {
				node* temp = tail->prev;
				temp->next = nullptr;
				delete tail;
				tail = temp;
			}
			sz--;
		}
	}
};


int main() {
	Stack s;

	// empty cases
	s.pop();
	cout << "EMPTY CASE: " << s.top() << " " << s.size() << " " << s.empty() << endl;

	// single case
	s.push(100);
	cout << "SINGLE CASE: " << s.top() << " " << s.size() << " " << s.empty() << endl;

	// add 100 numbers
	for (int i=0; i < 100; ++i) {
		s.push(i);
	}
	cout << "AFTER 100 PUSHES: " << s.top() << " " << s.size() << " " << s.empty() << endl;

	// delete everything
	while (!s.empty()) {
		s.pop();
	}
	cout << "AFTER DELETE: " << s.top() << " " << s.size() << " " << s.empty() << endl;

	return 0;
}
