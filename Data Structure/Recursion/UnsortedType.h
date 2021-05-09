using namespace std;
// Header file for Unsorted List ADT.
template <class ItemType>
struct NodeType;

// Assumption:  ItemType is a type for which the operators "<"
// and "==" are defined—either an appropriate built-in type or
// a class that overloads these operators.

template <class ItemType>
class UnsortedType
{
public:
  UnsortedType();     // Class constructor
  ~UnsortedType();    // Class destructor

  bool IsFull() const;
  // Determines whether list is full.
  // Post: Function value = (list is full)

  int  LengthIs() const;
  // Determines the number of elements in list.
  // Post: Function value = number of elements in list.

  void MakeEmpty();
  // Initializes list to empty state.
  // Post:  List is empty.

  void RetrieveItem(ItemType& item, bool& found);
  // Retrieves list element whose key matches item's key
  // (if present).
  // Pre:  Key member of item is initialized.
  // Post: If there is an element someItem whose key matches
  //       item's key, then found = true and item is a copy
  //       of someItem; otherwise found = false and item is
  //       unchanged.
  //       List is unchanged.
  
  void InsertItem(ItemType item);
  // Adds item to list.
  // Pre:  List is not full.
  //       item is not in list.
  // Post: item is in list.

  void DeleteItem(ItemType item);
  // Deletes the element whose key matches item's key.
  // Pre:  Key member of item is initialized.
  //       One and only one element in list has a key matching
  //       item's key.
  // Post: No element in list has a key matching item's key.

  void ResetList();
  // Initializes current position for an iteration through the
  // list.
  // Post: Current position is prior to list.

  void GetNextItem(ItemType& item);
  // Gets the next element in list.
  // Pre:  Current position is defined.
  //       Element at current position is not last in list.
  // Post: Current position is updated to next position.
  //       item is a copy of element at current position.
    
    /*1번*/
    ItemType SumSquare_a(NodeType<ItemType>* list);
    ItemType SumSquare_b(NodeType<ItemType>* list);
    ItemType SumSquare_c(NodeType<ItemType>* list);
    ItemType SumSquare_d(NodeType<ItemType>* list);
    ItemType SumSquare_e(NodeType<ItemType>* list);
    void PrintSumSquares();

    /*5번*/
    NodeType<ItemType>* MinLoc(NodeType<ItemType>* list);
    void Sort(NodeType<ItemType>* list);


private:
  int length;
  NodeType<ItemType>* currentPos;
  NodeType<ItemType>* listData;

};

template<class ItemType>
struct NodeType
{
    ItemType info;
    NodeType* next;
};

template <class ItemType>
UnsortedType<ItemType>::UnsortedType()  // Class constructor
{
  length = 0;
  listData = NULL;
}

template <class ItemType>
UnsortedType<ItemType>::~UnsortedType()
// Class destructor
{
  MakeEmpty();
}
template<class ItemType>
bool UnsortedType<ItemType>::IsFull() const
// Returns true if there is no room for another ItemType
//  on the free store; false otherwise.
{
  NodeType<ItemType>* location;
  try
  {
    location = new NodeType<ItemType>;
    delete location;
    return false;
  }
  catch(std::bad_alloc exception)
  {
    return true;
  }
}
template <class ItemType>
int UnsortedType<ItemType>::LengthIs() const
// Post: Number of items in the list is returned.
{
  return length;
}
template <class ItemType>
void UnsortedType<ItemType>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
    NodeType<ItemType>* tempPtr;

    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}
template <class ItemType>
void UnsortedType<ItemType>::RetrieveItem(ItemType& item,
    bool& found)
// Pre:  Key member(s) of item is initialized.
// Post: If found, item's key matches an element's key in the
//       list and a copy of that element has been stored in item;
//       otherwise, item is unchanged.
{
    bool moreToSearch;
    NodeType<ItemType>* location;

    location = listData;
    found = false;
    moreToSearch = (location != NULL);

    while (moreToSearch && !found)
    {
        if (item == location->info)
        {
            found = true;
            item = location->info;
        }
        else
        {
            location = location->next;
            moreToSearch = (location != NULL);
        }
    }
}
template <class ItemType>
void UnsortedType<ItemType>::InsertItem(ItemType item)
// item is in the list; length has been incremented.
{
    NodeType<ItemType>* location;

    location = new NodeType<ItemType>;
    location->info = item;
    location->next = listData;
    listData = location;
    length++;
}
template <class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
    NodeType<ItemType>* location = listData;
    NodeType<ItemType>* tempLocation;

    // Locate node to be deleted.
    if (item == listData->info)
    {
        tempLocation = location;
        listData = listData->next;        // Delete first node.
    }
    else
    {
        while (!(item==(location->next)->info))
            location = location->next;

        // Delete node at location->next
        tempLocation = location->next;
        location->next = (location->next)->next;
    }
    delete tempLocation;
    length--;
}

template <class ItemType>
void UnsortedType<ItemType>::ResetList()
// Post: Current position has been initialized.
{
  currentPos = NULL;
}
 
template <class ItemType>
void UnsortedType<ItemType>::GetNextItem(ItemType& item)
// Post:  Current position has been updated; item is current item.
{
  if (currentPos == NULL)
    currentPos = listData;
  else
    currentPos = currentPos->next;
  item = currentPos->info;
}

//Base case question
//Smaller caller question
//General-case question



/* 1번 */

template <class ItemType>
ItemType UnsortedType<ItemType>::SumSquare_a(NodeType<ItemType>* list)
{
    if(list != NULL)
        return (list->info*list->info)+SumSquare_a(list->next);
    else
        return 0;
}

/*틀린점 : return 0이 if-else 값에 있어야함. */

template <class ItemType>
ItemType UnsortedType<ItemType>::SumSquare_b(NodeType<ItemType>* list)
{
//    int sum = 0;
//    while(list != NULL)
//    {
//        sum = list->info + sum;
//        list = list->next;
//    }
//    return sum;
    if(list != NULL)
        return list->info * list->info + SumSquare_b(list->next); //smaller-caller
    else //base
        return 0;
}
/*틀린점 : recursive가 이뤄지지 않고, 제곱도 이뤄지지 않음. while문과 return을 고쳐야함.*/

template <class ItemType>
ItemType UnsortedType<ItemType>::SumSquare_c(NodeType<ItemType>* list)
{
    if( list == NULL)
        return 0;
    else
        return list->info*list->info + SumSquare_c(list->next);
}

/*모범답안.*/

template <class ItemType>
ItemType UnsortedType<ItemType>::SumSquare_d(NodeType<ItemType>* list)
{
    if(list->next == NULL)
        return list->info*list->info;
    else
        return list->info*list->info+SumSquare_d(list->next);
}
/*틀린점 없음. 모범답안.*/

template <class ItemType>
ItemType UnsortedType<ItemType>::SumSquare_e(NodeType<ItemType>* list)
{
    if(list == NULL)
        return 0;
    else
        return (list->info*list->info+SumSquare_e(list->next));
}

/* general-case에서 정작 값을 계산하는 곳이 없음 */

template <class ItemType>
void UnsortedType<ItemType>::PrintSumSquares()
{
    //a, b, c, d, e의 문제를 수정 후 출력
    cout << SumSquare_a(listData) << endl;  //  a 번 함수
    cout << SumSquare_b(listData) << endl;  //  b 번 함수
    cout << SumSquare_c(listData) << endl;  //  c 번 함수
    cout << SumSquare_d(listData) << endl;  //  d 번 함수
    cout << SumSquare_e(listData) << endl;  //  e 번 함수
};






/*5번*/

//A.
template <class ItemType>
NodeType<ItemType>* UnsortedType<ItemType>::MinLoc(NodeType<ItemType>* location)
{
    NodeType<ItemType>* MinPtr = new NodeType<ItemType>;
    MinPtr = location;
    
    if(location->next == NULL) //base
        return MinPtr;
    else if(location == NULL)
        return NULL;
    else
    {
        MinPtr = MinLoc(location->next);
        if(location->info < MinPtr->info){
            MinPtr = location;
        }
    }
    
    return MinPtr;
}


//B.

template <class ItemType>
void UnsortedType<ItemType>::Sort(NodeType<ItemType>* location)
{
    ItemType temp;
    NodeType<ItemType>* obj = new NodeType<ItemType>;
    
    if(location != NULL)
    {
        obj = MinLoc(location);
        temp = obj->info;
        obj->info = location->info;
        location->info = temp;
        
        Sort(location->next);
    }
    
}
