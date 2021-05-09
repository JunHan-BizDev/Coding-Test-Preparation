#include <iostream>
#include "StackTType.h"
using namespace std;


void copy(StackType<int> stackA, StackType<int>& stackB){
    StackType<int> temp;
    
    while(!stackA.IsEmpty()){
        temp.Push(stackA.Top());
        stackA.Pop();
    }
    
    while(!temp.IsEmpty()){
        stackB.Push(temp.Top());
        temp.Pop();
    }

}

int main(){
    StackType<int> stackA, stackB;
    int val = 0;
    
    while(1){
        cout << "stack에 넣을 값 : ";
        cin >> val;
        if(val == -1)
            break;
        stackA.Push(val);
    }
    
    copy(stackA,stackB);
    
    cout << "copy finished.\n\n";
    
    
    return 0;
}
