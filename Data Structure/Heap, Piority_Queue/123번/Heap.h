#pragma once
template <class ItemType>
void swap(ItemType& one, ItemType& two);

template<class ItemType>
// Assumes ItemType is either a built-in simple type or a class
// with overloaded relational operators.
struct HeapType
{
  void ReheapDown(int root, int bottom);
  void ReheapUp(int root, int bottom);
    void NonRecursv_ReheapDown(int root, int bottom);
    void NonRecursv_ReheapUp(int root, int bottom);

  ItemType* elements;   // Array to be allocated dynamically
  int numElements;
};

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
      ReheapDown(maxChild, bottom);
    }
  }
}

template<class ItemType>
void HeapType<ItemType>::NonRecursv_ReheapUp(int root, int bottom)
{
    int parent = bottom;
    
    //자식과 부모노드 비교
    //언제까지 ? bottom > root
    
    while(parent > root)
    {
        parent = (bottom-1) / 2;
        if(elements[bottom] > elements[parent])
        {
            Swap(elements[bottom], elements[parent]);
            bottom = parent;
        }
        else
            break;
    }
}


template<class ItemType>
void HeapType<ItemType>::NonRecursv_ReheapDown(int root, int bottom)
{
    //root = 0, bottom = 끝
    
    int Lchild, Rchild,Maxchild = 0;
    
    while(Maxchild < bottom)
    {
        Lchild = (root * 2) + 1;
        Rchild = (root * 2) + 2;
        //Lchild만 있는 경우
        if(Lchild == bottom)
        {
            Maxchild = Lchild;
        }
        //LR둘다 있는경우
        else
        {
            if(elements[Lchild] > elements[Rchild])
                Maxchild = Lchild;
            else
                Maxchild = Rchild;
        }
        
        if(elements[root] < elements[Maxchild])
        {
            Swap(elements[root], elements[Maxchild]);
            root = Maxchild;
        }
    }
    
}
