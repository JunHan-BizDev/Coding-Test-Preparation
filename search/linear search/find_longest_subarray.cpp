#include <iostream>
using namespace std;



void longestSubarray(const int arr[], const int length)
{
    
    int startIdx = 0, endIdx = 0, result = 1; // index 변수
    
    //결과 저장 array
    int outcome[50];
    int arrlen = 0;
    
    int startobj = arr[startIdx], endobj = -1;     //값 비교 변수

    //array 검사
    while(startIdx < length)
    {
        endIdx++;
        //조건 1 : 만약 val1,val2 차이 1 이상이면 초기화
        if(abs(arr[startIdx] - arr[endIdx]) > 1)
        {
            //해당 원소 길이 array에 저장
            outcome[arrlen] = result;
            arrlen++;
            result = 1;
            
            //그 다음 원소 검사
            startIdx++;
            endIdx = startIdx;
            endobj = -1;
            startobj = arr[startIdx];
            
            continue;
        }
        //조건 2 : value가 3개 이상이면 초기화
        if(startobj != arr[endIdx] && endobj != arr[endIdx] && endobj != -1)
        {
            //해당 원소 길이 array에 저장
            outcome[arrlen] = result;
            arrlen++;
            result = 1;

            //그 다음 원소 검사
            startIdx++;
            endIdx = startIdx;
            endobj = -1;
            startobj = arr[startIdx];
            
            continue;
        }
        
        result++;
        if(arr[endIdx] != startobj)
            endobj = arr[endIdx];
    }
    
    //저장된 길이 중 최대길이 반환
    for(int i = 0; i < arrlen; i++)
    {
        if(outcome[i] > result)
            result  = outcome[i];
    }
    
    cout << result << endl;
    
}

int main(){
    int arr[7];
    int arrlen = 7, num = -1;
    //배열 입력
    for( int i = 0; i < arrlen; i++)
    {
        cin >> num;
        arr[i] = num;
    }
    
    longestSubarray(arr, arrlen);
    
    return 0;
}
