#include <iostream>
using namespace std;

/*
Cài đặt thuật sắp xếp nhanh để sắp xếp nhanh (Quick sort) mảng của các phần tử (Xanh, Đỏ , Trắng) theo quy tắc quốc kỳ Hà Lan 
(Dutch National Flag), sau đó cài đặt thuật toán trộn hai mảng để sắp xếp một dãy mới gồm các phần tử (Xanh, Đỏ, Trắng) vào 
dãy cũ đã sắp xếp theo đúng quy tắc quốc kỳ Hà Lan
*/


//fuction de quick sort
void Swap(int *a, int *b);
int partition(int *array, int start, int end);
void quickSort(int* array, int start, int end);

//function de ma hoa string thanh so va giai ma so lai thanh string
int* encrypt(string *input, int n);
void decrypt(int *input, string *output, int n);

void combine(string *&a, string *b, int numA, int numB);




int main()
{

    string* Input1 = new string[9] {"blue", "red", "blue", "red", "red", "white", "red", "blue", "white"};
    string* Input2 = new string[9] {"white", "red","red", "red", "blue", "red", "blue", "blue", "white"};
    combine(Input1, Input2, 9, 9);
    int* Input1AsInt = encrypt(Input1, 18);
    quickSort(Input1AsInt, 0 , 18);
    decrypt(Input1AsInt, Input1, 18);
    for (int i = 0; i < 18; i++)
    {
        cout << Input1[i] << " ";
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

void combine(string *&a, string *b, int numA, int numB)
{
    string *temp = new string[numA + numB];
    for (int i = 0; i < numA; i++)
    {
        temp[i] = a[i];
    }
    for (int i = 0; i < numB; i++)
    {
         temp[numA + i] = b[i];
    }
    a = temp;
}
