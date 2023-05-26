class Node {
public:
	int data;
	Node* next;
	Node* prev;
};
class LinkedList {
public:
	LinkedList();
	void Append(int data);
	void Prepend(int data);
	int Length();
	void Print();
	void PrintReverse();
private:
	Node* head;
	Node* tail;
};