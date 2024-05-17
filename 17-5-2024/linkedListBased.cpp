#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};
struct Stack //coi cái head của linked list là top của stack
{
    Node* top;
};
void Push(int x, Stack &a) 
{
    Node *temp =  new Node();
    temp->data = x;
    temp->next = a.top;
    a.top = temp;   
}
void Pop(Stack &a)
{
    Node* temp = a.top;
    if (a.top == NULL) return;
    a.top = a.top->next;
    free(temp);
}
int Top(Stack &a)
{
    return a.top->data;
}
bool IsEmpty(Stack &a)
{
    if (a.top == NULL) return true;
    else return false;
}
void Print(Stack a)
{
    Node* temp = a.top;
    while (temp->next!= NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main()
{
    Stack a;
    int A[10] = {73,89,96,99,60,55,52,66,67,79};
    for (int i = 0; i < 10; i++)
    {
        if (A[i] < A[0] && A[i] % 2 == 0) {
            if (!IsEmpty(a)) Pop(a);
        } else Push(A[i], a);
    }
    Print(a);

}
