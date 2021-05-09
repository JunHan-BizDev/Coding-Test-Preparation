#include <iostream>
#include <cmath>
#include <time.h>
#include "UnsortedType.h"
using namespace std;

/*2번*/

// 피보나치 수열은 0번째부터 시작함을 가정.

int Fibonacci_Recursive(int n)
{
    if(n == 0)
        return n;
    else if(n == 1)
        return n;
    else
        return Fibonacci_Recursive(n-1) + Fibonacci_Recursive(n-2);
}

// 피보나치 수열은 0번째부터 시작함을 가정.

int Fibonacci_non_Recursive(int n)
{
    int result = 0;
    int prev = 0, pprev = 0;
    int temp;
    for(int i = 0; i < n; i++)
    {
        if( i == 0 )
        {
            result = 0;
            prev = 0;
            pprev = 0;
        }
        else if(i == 1)
        {
            result = 1;
            prev = 1;
            pprev = 0;
        }
        else
        {
            temp = result;
            pprev = prev;
            prev = temp;
            result = (prev + pprev);

        }
    }
    
    return result;
}


/*3번*/
//A.
float SqrRoot_Recursion(float number, float approx, float tol)
{
    float result = 0;
    if(abs(approx*approx - number) < tol)
        return approx;
    else
        result = SqrRoot_Recursion(2, (approx*approx + number) / (2*approx), tol);
    
    return result;
}

//B.

float SqrRoot_non_Recursion(float number, float approx, float tol)
{
    while(abs(approx*approx - number) > tol)
    {
        approx = (approx*approx + number) / (2*approx);
    }
    
    return approx;
}

/*4번*/
//A.
int NumPaths(int row, int col, int n)
{
    int result;
    if((row == n)|| (col == n))
        return 1;
    else
        result = NumPaths(row+1, col, n) + NumPaths(row, col+1, n);
    
    return result;
}

//B.

int NumPaths_B(int row,int col,int n)
{
    int mat[n][n];
    
    for(int i= 0; i < n; i++)
        for(int j= 0; j < n; j++)
            mat[i][j] = -1;
    
  
    if(mat[row-1][col-1] == -1)
    {
        mat[row-1][col-1] = NumPaths(row, col, n);
    }
    
    return mat[row-1][col-1];
    
    

}


int main()
{
    
    //2.C : 절대 그렇지 않다. n = 30일때 시간을 재보면 재귀버전은 5709ms이고, 비재귀버전은 1.844ms이므로 무려 2000배 넘게 차이가 난다. 따라서 성능을 향상시키지 못한다.
    clock_t start, end;
    double time_result;
    
    start = clock();
    cout << Fibonacci_Recursive(30);
    end = clock();
    
    time_result = (double)(end - start);
    
    start = clock();
    cout << Fibonacci_non_Recursive(30);
    start = clock();
    
    time_result = (double)(end - start);

    

//    float a,b;
//    a= SqrRoot_Recursion(2, 1, 0.1);
//    b=SqrRoot_non_Recursion(2, 1, 0.1);
//
//    NodeType<int>* ptr = new NodeType<int>;
//    UnsortedType<int> list;
//    list.InsertItem(1);
//    list.InsertItem(5);
//    list.InsertItem(3);
//    list.InsertItem(11);
//    list.InsertItem(14);
//
//    ptr = list.listData;
//
//    ptr = list.MinLoc(ptr);
//
//    list.Sort(list.listData);
    
    
//    int result = 0;
//    result = NumPaths(1, 1, 3);
//
//    result = NumPaths_B(1, 1, 3);

    return 0;
}
