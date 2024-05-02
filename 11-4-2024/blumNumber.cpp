/*
Thiết kế giải thuật và cài đặt để tạo ra một mảng số Blum (hay còn gọi là số nửa nguyên tố là tích của hai số nguyên tố) nhỏ 
hơn một số N cho trước và thực hiện hai yêu cầu sau
- Tìm ra tất cả các cặp số Blum có tổng cũng là một số Blum nhỏ hơn N
- Kiểm tra xem một số Blum M có tồn tại trong dãy số Blum được tạo ra hay không. 
Chạy chương trình đến giá trị N = 10^6 và kiểm tra thời gian thực thi của chương trình. 

*/


#include <iostream>
#include <math.h>

using namespace std;

int PrimeCheck(int n);   // Kiểm tra số nguyên tố 
int BlumCheck(int n);  // Kiểm tra số nửa nguyên tố Blum
int *BlumArray(int numOfInput, int&numOfOutput);
bool binarySearch(int a, int *arr, int low, int high);

bool inBlumArray(int a, int *arr, int low, int high);



int main()
{
    //Thiết kế giải thuật và cài đặt để tạo ra một mảng số Blum (hay còn gọi là số nửa nguyên tố là tích của hai số nguyên tố) nhỏ hơn một số N cho trước
    int numBlumElement;
    int*BlumArr = BlumArray(1000, numBlumElement);

    //Tìm ra tất cả các cặp số Blum có tổng cũng là một số Blum nhỏ hơn N


    for (int i = 0; i < numBlumElement - 1; i++)
    {
        for (int j = i+1; j < numBlumElement; j++)
        {
            int temp =  BlumArr[i] + BlumArr[j];
            if (inBlumArray(temp,BlumArr,j+1,numBlumElement) == 1) cout << BlumArr[i] << ' ' << BlumArr[j] << '\n';

        }
    }



    //Kiểm tra xem một số Blum M có tồn tại trong dãy số Blum được tạo ra hay không.
    int a = 189;
    if (inBlumArray(a, BlumArr, 0, numBlumElement) == 1) cout << "So " << a << " co trong day so Blum";
    else   cout << "So " << a << " khong trong day so Blum";
  

}



int PrimeCheck(int n)   // Kiểm tra số nguyên tố 
{
    int count = 0;
    for (int i = 2; i <= n; i++)
        if (n % i == 0) count++;
    if (count == 1) return 1;
    else return 0;
} 

int BlumCheck(int n)  // Kiểm tra số nửa nguyên tố Blum
{
    int count = 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (PrimeCheck(i) && PrimeCheck(n / i) && (i * (n / i) == n))
        {
            count++;
        }

    }
    return count;
}
int *BlumArray(int numOfInput, int&numOfOutput)
{
    int num = 0;
    for (int i = 4; i <= numOfInput; i++)
    {
        if (BlumCheck(i) == 1)
        {
            num++;
        }
    }
    int* array = new int[num];
    int j = 0;
    for (int i = 4; i <= numOfInput; i++)
    {
        if (BlumCheck(i) == 1)
        {
            array[j] = i;
            j++;
        }
    }
    numOfOutput = j;
    return array;
}
bool binarySearch(int a, int *arr, int low, int high)
{
    if (low <= high)
    {
        int mid = (high + low)/2;
        if (arr[mid] == a) return true;
        else if (a > arr[mid]) return binarySearch(a, arr, mid+1, high);
        else return binarySearch(a, arr, low, mid-1);
    }
    else return false;
}
bool inBlumArray(int a, int *arr, int low, int high)
{
    if (binarySearch(a,arr,low,high) == 1) return true;
    else return false; 
}
