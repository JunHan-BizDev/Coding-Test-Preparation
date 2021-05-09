#include <iostream>
#include "StackTType.h"
using namespace std;


const int MAX_items = 200;
template<class itemtype>
class doublestack{
public:
    void push(itemtype item){
        if(isFull())
            cout << "stack is full" << endl;
        
        else if(item <= 1000){
            stack[Apointer] = item;
            Apointer++;
        }
        else{
            stack[Bpointer] = item;
            Bpointer--;
        }
    }
    bool isFull(){
        if(Apointer > Bpointer )
            return true;
        else
            return false;
    }
    void print(){
        cout << "Stack A :" << endl << endl;

        for(int i = 0; i < Apointer; i++){
            
            cout << stack[i] <<  "\t";
        }
        cout << endl << endl << "Stack B :" << endl << endl;

        for(int i = MAX_items - 1; i > Bpointer; i--){
            cout << stack[i] <<  "\t";
        }

    }
private:
    int stack[MAX_items];
    int Apointer = 0;
    int Bpointer =(MAX_items -1 );
};


int main(){
    doublestack<int> stack;
    for(int i = 0; i <= 5; i++){
        stack.push(i);
    }
    for(int i = 1000; i <= 1005; i++){
        stack.push(i);
    }
    
    stack.print();
    return 0;

}
