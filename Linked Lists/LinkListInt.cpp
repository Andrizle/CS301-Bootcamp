#include "LinkListInt.h"

LinkListInt::LinkListInt()
{
    head = nullptr;
    size = 0;
}

LinkListInt::~LinkListInt()
{
}

void LinkListInt::Add(int value)
{
    Node* newNode = new Node();
    newNode->value = value;
    newNode->next = head;
    head = newNode;
    size++;
}

void LinkListInt::Remove(int value)
{
    Node* current = head;
    Node* previous = nullptr;

    while(current != nullptr) {
        if(current->value == value) {
            if(previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
            size--;
            return;
        }
        previous = current;
        current = current->next;
    }
}

bool LinkListInt::Contains(int value)
{
    while(head != nullptr) {
        if(head->value == value) {
            return true;
        }
        head = head->next;
    }
    return false;
}

int LinkListInt::Size()
{
    return 0;
}

string LinkListInt::ToString()
{
    string listStr = "";
    Node* curr = head;
    while (curr != nullptr) {
        listStr += to_string(curr->value) + " ";
        curr = curr->next;
    }
    listStr += "NULL";
    return listStr;
}
