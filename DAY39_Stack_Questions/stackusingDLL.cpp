//📑 Satyam's Solution
#include <bits/stdc++.h>
using namespace std;
// with the help of DLL , we get the O(1) time to find and delete middle element of the stack
template <class T>
class Node
{
public:
    T data;
    Node *next;
    Node *prev;

    Node(T data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
// generic stack using DLL
template <class T>
class STACK
{
public:
    Node<T> *head;
    Node<T> *middle;
    Node<T> *top;
    int size;

    STACK()
    {
        head = NULL;
        middle = head;
        size = 0;
        top = head;
    }

    void push(T data)
    {
        Node<T> *ptr = new Node<T>(data);
        if (head == NULL)
        {
            head = ptr;
            top = head;
            middle = head;
        }
        else
        {
            top->prev = ptr;
            ptr->next = top;
            top = ptr;
        }
        size++;
        if (size > 1 and size % 2 == 1)
        {
            middle = middle->prev;
        }
    }

    void pop()
    {
        Node<T> *temp = top;
        if (size == 0)
        {
            cout << "Stack is empty.\n";
            return;
        }
        else
        {
            top = top->next;
            if (top == NULL)
            {
                head = middle = NULL;
                size = 0;
                return;
            }
        }
        size--;
        if (size > 0 and size % 2 == 0)
        {
            middle = middle->next;
        }
        delete (temp);
    }

    void getTop()
    {
        if (size == 0)
        {
            cout << "Stack is empty.\n";
        }
        else
            cout << "Top = " << top->data << "\n";
    }

    void getMiddle()
    {
        if (size == 0)
        {
            cout << "Stack is empty.\n";
        }
        else
        {
            cout << "Middle = " << middle->data << "\n";
        }
    }

    void deleteMiddle()
    {
        Node<T> *d = middle;

        if (size == 0)
        {
            cout << "Stack is empty.\n";
            return;
        }
        size--;
        if (size == 0)
        {
            delete (d);
            top = middle = head = NULL;
            return;
        }

        middle->prev->next = middle->next;
        if (middle != head)
            middle->next->prev = middle->prev;
        else
            head = middle->prev;
        if (size % 2 == 1)
            middle = middle->prev;
        else
            middle = middle->next;
        delete (d);
    }

    void display()
    {
        if (size == 0)
        {
            cout << "Stack is empty\n";
            return;
        }
        Node<T> *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " , ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main()
{
    STACK<int> d;
    d.push(100);
    d.push(200);
    d.push(300);
    d.push(400);
    d.push(500);
    d.display();
    //d.pop();
    d.getMiddle();
    d.deleteMiddle();
    //d.deleteMiddle();

    d.display();
    d.getMiddle();

    return 0;
}