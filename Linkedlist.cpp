#include<iostream>

using namespace std;

class Node
{
    public: 
    int data;
    Node *next;
};

class LinkedList
{
    private: 
    Node *first;
    public:
    LinkedList()
    {
        first = NULL;
    }
    LinkedList(int A[], int n){};
    void Display();
    void Insert(int index, int x);
    int Delete(int index);
    int length();
};

LinkedList :: LinkedList(int A[], int n)
{
    Node *last, *t;
    int i = 0;
}

