#include <iostream>
#include <string>
#include <sstream>
#include "list.h"

using namespace std;

LinkedList::LinkedList() {
    head = 0;
    tail = 0;
}
void LinkedList::Append(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = 0;
    newNode->prev = 0;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}
void LinkedList::Prepend(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = 0;
    newNode->prev = 0;

    if (head == 0) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
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
void LinkedList::PrintReverse() {
    Node* temp = tail;
    while (temp != 0) {
        cout << temp->data << " ";
        temp = temp->prev;
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

    list.PrintReverse();
    cout << list.Length() << endl;

    return 0;
}