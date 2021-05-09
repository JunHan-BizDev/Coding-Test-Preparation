#include <iostream>
#include "QueType.h"
using namespace std;


//1번은 가장 밑에!
// 멤버함수들은 다 cpp파일에 있음.
//2번

void ReplaceItem(QueType &queue, int oldItem, int newItem){
    EmptyQueue empty;
    QueType temp;
    
    ItemType compare;
    if(queue.IsEmpty()){
        throw empty;
    }
    
    while(!queue.IsEmpty()){
        queue.Dequeue(compare);
        if(compare == oldItem){
            temp.Enqueue(newItem);
        }
        else{
            temp.Enqueue(compare);
        }
    }
    
    while(!temp.IsEmpty()){
        temp.Dequeue(compare);
        queue.Enqueue(compare);
    }
}


//3번

bool Identical(QueType queue1, QueType queue2){
    int comp1, comp2;
    bool result;
    while(!queue1.IsEmpty() || !queue2.IsEmpty()){
        queue1.Dequeue(comp1);
        queue2.Dequeue(comp2);
        if(comp1 != comp2){
            result = false;
            break;
        }
    }
    if(queue1.IsEmpty() && queue2.IsEmpty()){
        result = true;
    }
    else{
        result = false;
    }
    
    return result;
}


//4번

int Length(QueType &queue){
    int length = 0;
    QueType temp;
    ItemType item;
    while(!queue.IsEmpty()){
        queue.Dequeue(item);
        temp.Enqueue(item);
        length++;
    }
    
    //복원
    while(!temp.IsEmpty()){
        temp.Dequeue(item);
        queue.Enqueue(item);
    }

    
    return length;
}


//1번
int main(){

    QueType queue(10);
    int val = -1;

    for(int i = 0; i < 10; i++){
        val = rand() % 100;
        cout << "넣을 아이템 : " << val << endl;
        queue.Enqueue(val);
    }
    cout << endl;
    for(int i = 0; i < 10; i++){
        queue.Dequeue(val);
        cout << "뺀 아이템 : "  << val << endl;
    }


    return 0;

}


