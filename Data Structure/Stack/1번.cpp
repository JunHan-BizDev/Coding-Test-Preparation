#include <iostream>
#include "StackTType.h"
using namespace  std;

int main(){
    StackType<int> stack;
    int view = 0;
    for(int i = 1; i < 7; i++)
    {
        stack.Push(i);
    }
    
    while(!stack.IsEmpty()){
        cout << stack.Top() << endl;
        stack.Pop();
    }
    
    return 0;
}
