/*
Yêu cầu bài toán: Nhập vào n đối tượng có màu đỏ (red), trắng (white) và xanh (blue), 
sắp xếp theo trật tự như sau: các đối tượng cùng mầu nằm kế tiếp nhau và theo thứ tự đỏ, trắng, xanh.  
*/

#include <iostream>
#include <string>
using namespace std;

//fuction de quick sort
void Swap(int *a, int *b);
int partition(int *array, int start, int end);
void quickSort(int* array, int start, int end);

//function de ma hoa string thanh so va giai ma so lai thanh string
int* encrypt(string *input, int n);
void decrypt(int *input, string *output, int n);


int main()
{
    string Input[] = {"blue", "red", "blue", "red", "red", "white", "red", "blue", "white"};
    int n = size(Input);
    int *b = encrypt(Input, n);
    quickSort(b, 0, n);
    decrypt(b, Input, n);
    for (int i = 0; i < n; i++)
    {
        cout << Input[i] << " ";
    }

}





void Swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int *array, int start, int end)
{
    int pivotVal = array[end];
    int i = start - 1;
    for (int j = start; j <= end-1; j++)
    {
        if (array[j] < pivotVal)
        {
            i++;
            Swap(&array[i], &array[j]);
        }
    }
    i++;
    Swap(&array[i],&array[end]);
    return i;
}
void quickSort(int* array, int start, int end)
{
    if (end <= start) return;
    int pivot = partition(array, start, end);
    quickSort(array, start, pivot - 1);
    quickSort(array, pivot + 1, end);
}
int *encrypt(string *input, int n){
    int *b = new int[n];

    for (int i = 0; i < n ; i++)
    {
        if (input[i] == "red") b[i] = 0;
        else if (input[i] == "white") b[i] = 1;
        else b[i] = 2; 
    }
    return b;
}
void decrypt(int *input, string *output, int n)
{
    for (int i = 0; i < n ; i++)
    {
        if (input[i] == 0) output[i] = "red";
        else if (input[i] == 1) output[i] = "white";
        else output[i] = "blue"; 
    }
    delete input;
}
