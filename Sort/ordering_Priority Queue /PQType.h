// Definition of class PQType, which represents the Priority Queue ADT
class FullPQ{};
class EmptyPQ{};
#include "SortedType.h"
template<class ItemType>
class PQType
{
public:
  PQType();          // parameterized class constructor
  ~PQType();            // class destructor
  
  void MakeEmpty();
  // Function: Initializes the queue to an empty state.
  // Post: Queue is empty.
  
  bool IsEmpty() const;
  // Function: Determines whether the queue is empty.
  // Post: Function value = (queue is empty)
  
  bool IsFull() const;
  // Function: Determines whether the queue is full.
  // Post: Function value = (queue is full)
  
  void Enqueue(int priority, ItemType newItem);
  // Function: Adds newItem to the rear of the queue.
  // Post: if (the priority queue is full) exception FullPQ is thrown;
  //       else newItem is in the queue.
  
  void Dequeue(ItemType& item);
  // Function: Removes element with highest priority from the queue
  // and returns it in item.
  // Post: If (the priority queue is empty) exception EmptyPQ is thrown;
  //       else highest priority element has been removed from queue.
  //       item is a copy of removed element.
    void Ordering(int** orderList, int M);
private:
  int length;
 SortedType<ItemType> linkedList;
  //int maxItems;
};

template<class ItemType>
PQType<ItemType>::PQType()
{
  length = linkedList.LengthIs();
}

template<class ItemType>
void PQType<ItemType>::MakeEmpty()
{
  length = 0;
}

template<class ItemType>
PQType<ItemType>::~PQType()
{
	linkedList.MakeEmpty();
}

template<class ItemType>
void PQType<ItemType>::Ordering(int** orderList, int M)
{
    int pre = -1, post = -1; //관계 문제들
    int preIdx = -1,postIdx = -1;
    int target, pretarget = 0, posttarget = 0; // priority 값 받아오는 ㅇㅇ
    for(int i = 0; i< M; i++)
    {
        int item;
        //1. 조건 받아오기
        pre = orderList[i][0];
        post = orderList[i][1];
        
        //2. 해당 조건 탐색
        linkedList.ResetList();
        for(int j = 0; j < linkedList.LengthIs(); j++)
        {
            linkedList.GetNextItem(item, target);
            if(item == pre)
                preIdx = j;
            else if(item == post)
               postIdx = j;
        }
        
        //3. 둘 priority switch
        linkedList.SwapPriority(preIdx, postIdx);
        
        //4. 작은 값의 priority 를 탐색하며 변경
        if(pre > post)
            linkedList.CompareAndSwap(post, pre);
        else
            linkedList.CompareAndSwap(pre, post);
    }
    
    for(int i = 0; i< M; i++)
    {
        int item;
        //1. 다시 조건 받아오기
        pre = orderList[i][0];
        post = orderList[i][1];
        
        linkedList.ResetList();
        for(int j = 0; j < linkedList.LengthIs(); j++)
        {
            linkedList.GetNextItem(item, target);
            if(item == pre)
                preIdx = j;
            else if(item == post)
               postIdx = j;
        }
        
        //preIdx와 postIdx의 priority 비교
        linkedList.ResetList();
        for(int i = 0; i < preIdx; i++)
        {
            linkedList.GetNextItem(item, pretarget);
        }
        
        linkedList.ResetList();
        for(int i = 0; i < postIdx; i++)
        {
            linkedList.GetNextItem(item, posttarget);
        }

        if(pretarget < posttarget)
            linkedList.SwapPriority(preIdx, postIdx);
    }
    
}


template<class ItemType>
void PQType<ItemType>::Dequeue(ItemType& item)
// Post: element with highest priority has been removed 
//       from the queue; a copy is returned in item.
{
  if (length == 0)
    throw EmptyPQ();
  else
  {
    int target;
	linkedList.ResetList();
      
    //priority대로 뽑기
      for(int i = 0; i < linkedList.LengthIs(); i++)
      {
          linkedList.GetNextItem(item, target);
          if(target == linkedList.LengthIs())
          {
              linkedList.DeleteItem(item);
              break;
          }
          

      }
    length--;
  
  }
}

template<class ItemType>
void PQType<ItemType>::Enqueue(int priority, ItemType newItem)
// Post: newItem is in the queue.
{
  if (linkedList.IsFull())
    throw FullPQ();
  else
  {
    length++;
	linkedList.InsertItem(priority, newItem);
  }
}
template<class ItemType>
bool PQType<ItemType>::IsFull() const
// Post: Returns true if the queue is full; false, otherwise.
{
  return linkedList.IsFull();
}

template<class ItemType>
bool PQType<ItemType>::IsEmpty() const
// Post: Returns true if the queue is empty; false, otherwise.
{
  return length == 0;
}

