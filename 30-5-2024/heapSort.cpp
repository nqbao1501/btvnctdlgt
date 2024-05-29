#include <iostream>
using namespace std;

void Heapify(int *arr, int n, int i)
{
    int largest = i;
    int right = 2*i + 2;
    int left = 2*i + 1;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        Heapify(arr, n, largest);
    }
}
void heapSort(int *arr, int n)
{
    for (int i = n/2-1; i >= 0; i--)
    {
        Heapify(arr, n, i);
    }
    for (int i = n-1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        Heapify(arr,i,0);
    }
}
void Print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void preOrder (int *arr, int n, int i)
{
    if (i >= n)
    {
        return;
    }
    else{
        cout << arr[i] << " ";
        preOrder(arr,n,(2*i)+1);
        preOrder(arr,n,(2*i)+2);
    }

}
void postOrder(int *arr, int n, int i)
{
    if (i >= n)
    {
        return;
    }
    else{
        postOrder(arr,n,(2*i)+1);
        postOrder(arr,n,(2*i)+2);        
        cout << arr[i] << " ";
    }

}    
void inOrder(int *arr, int n, int i)
{
    if (i >= n)
    {
        return;
    }
    else{
        inOrder(arr,n,(2*i)+1);
        cout << arr[i] << " ";
        inOrder(arr,n,(2*i)+2);        

    }
    
}    
int main()
{
    int arr[] = {6, 1, 7, 5, 10, 2, 8};
    preOrder(arr,7,0);
    cout << "\n";
    postOrder(arr,7,0);
    cout << "\n";
    inOrder(arr,7,0);
    cout << "\n";
    heapSort(arr,7);
    Print(arr,7);

}
