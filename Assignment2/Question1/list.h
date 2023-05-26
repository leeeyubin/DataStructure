class Node {
public:
	int data;
	Node* next;
};
class LinkedList {
public:
	LinkedList();
	void Append(int data);
	int Length();
	void Print();
private:
	Node* head;
};