#include <iostream>
#include "PQTypeStack.h"
using namespace std;

int main(){
    PQType<int> stack;
    int top;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(5);
    stack.Push(6);
    stack.Push(4);

    
    top = stack.Top();
    
    stack.Push(100);
    stack.Pop(top);
    
    

    return 0;
}
