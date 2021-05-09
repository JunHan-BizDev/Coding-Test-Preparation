template <class ItemType>
void swap(ItemType& one, ItemType& two);

template<class ItemType>
// Assumes ItemType is either a built-in simple type or a class
// with overloaded relational operators.
struct HeapType
{
  void ReheapDown(int root, int bottom);
  void ReheapUp(int root, int bottom);
  int FindIndex(ItemType item);
    int getBiggestTimeStampIndex();

  ItemType* elements;   // Array to be allocated dynamically
    int* timestamp;
  int numElements;
};

template <class ItemType>
int HeapType<ItemType>::FindIndex(ItemType item)
{
    int i = 0, result;
    while(elements[i] != NULL)
    {
        if(elements[i] == item)
            result = i;
        i++;
    }
    return result;
}
template <class ItemType>
int HeapType<ItemType>::getBiggestTimeStampIndex()
{
    int i = 1, result, index = 0;
    result = timestamp[0];
    while(timestamp[i] != NULL)
    {
        if(result < timestamp[i])
        {
            result = timestamp[i];
            index = i;
        }
        i++;
    }
    
    return index;
}

template <class ItemType>
void Swap(ItemType& one, ItemType& two)
{
  ItemType temp;
  temp = one;
  one = two;
  two = temp;
}  
template<class ItemType>
void HeapType<ItemType>::ReheapUp(int root, int bottom)
// Post: Heap property is restored.
{
  int parent;
  
  if (bottom > root)
  {
    parent = (bottom-1) / 2;
    if (elements[parent] < elements[bottom])
    {
      Swap(elements[parent], elements[bottom]);
        Swap(timestamp[parent], timestamp[bottom]);
      ReheapUp(root, parent);
    }
  }
}
template<class ItemType>
void HeapType<ItemType>::ReheapDown(int root, int bottom)
// Post: Heap property is restored.
{
  int maxChild;
  int rightChild;
  int leftChild;

  leftChild = root*2+1;
  rightChild = root*2+2;
  if (leftChild <= bottom)
  {
    if (leftChild == bottom)
      maxChild = leftChild;
    else
    {
      if (elements[leftChild] <= elements[rightChild])
        maxChild = rightChild;
      else
        maxChild = leftChild;
    }
    if (elements[root] < elements[maxChild])
    {
      Swap(elements[root], elements[maxChild]);
        Swap(timestamp[root], timestamp[maxChild]);

      ReheapDown(maxChild, bottom);
    }
  }
}

