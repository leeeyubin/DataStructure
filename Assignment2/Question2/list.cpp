#include <iostream>
#include <string>
#include <sstream>
#include "list.h"

using namespace std;

LinkedList::LinkedList() {
    head = 0;
}
void LinkedList::Append(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = 0;
    if (head == NULL) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != 0) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void LinkedList::Prepend(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}
int LinkedList::Length() {
    int count = 0;
    Node* temp = head;
    while (temp != 0) {
        temp = temp->next;
        count++;
    }
    return count;
}
void LinkedList::Print() {
    Node* temp = head;
    while (temp != 0) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(void) {
    LinkedList list;

    string numbers;
    int number;
    getline(cin, numbers);

    istringstream is(numbers);
    while (is >> number) {
        if (number % 2)
            list.Append(number);
        else
            list.Prepend(number);
    }

    list.Print();
    cout << list.Length() << endl;

    return 0;
}