#include <iostream>
#include "StackType.h"
using namespace std;

void ReplaceItem(StackType& st, int oldItem, int newItem){
    StackType temp;
    
    while(!st.IsEmpty()){
        if(st.Top() != oldItem){
            temp.Push(st.Top());
            st.Pop();
        }
        else{
            temp.Push(newItem);
            st.Pop();
        }
    }
    
    while(!temp.IsEmpty()){
        st.Push(temp.Top());
        temp.Pop();
    }
}
