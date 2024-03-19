///////////////////////////////////////////////////////
// Asked to create a sample linked list.
// Test results are in the jpeg image file included in this repository.
//
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class Node 
{
public:
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void append(int data) 
    {
        Node* newNode = new Node(data);
        if (head == nullptr) 
        {
            head = tail = newNode;
        } 
        else 
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    bool remove(int data) 
    {
        Node* current = head;
        while (current) 
        {
            if (current->data == data) 
            {
                if (current == head) 
                {
                    head = current->next;
                    if (head)
                        head->prev = nullptr;
                } 
                else if (current == tail) 
                {
                    tail = current->prev;
                    tail->next = nullptr;
                } 
                else 
                {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    ~DoublyLinkedList() 
    {
        Node* current = head;
        while (current) 
        {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // Helper function for testing
    std::vector<int> toVector() const 
    {
        std::vector<int> result;
        Node* current = head;
        while (current) 
        {
            result.push_back(current->data);
            current = current->next;
        }
        return result;
    }
};


// Helper function for testing
bool testDoublyLinkedList() 
{
    DoublyLinkedList dll;
    dll.append(1);
    dll.append(2);
    dll.append(3);
    if (dll.toVector() != std::vector<int>({1, 2, 3}))
        return false;

    dll.remove(2);
    if (dll.toVector() != std::vector<int>({1, 3}))
        return false;

    if (dll.remove(5))
        return false;

    dll.remove(1);
    if (dll.toVector() != std::vector<int>({3}))
        return false;

    dll.remove(3);
    if (!dll.toVector().empty())
        return false;

    return true;
}

int main() 
{
    if (testDoublyLinkedList()) 
    {
        std::cout << "All tests passed!\n";
    } 
    else 
    {
        std::cerr << "Tests failed!\n";
    }

    // Or traditional printf formatting, supports a lot of formats:
    printf("Done...\n");
    return 0;
}

