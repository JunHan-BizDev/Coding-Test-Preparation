
#include "TreeType.h"
struct TreeNode
{
  ItemType info;
  TreeNode* left;
  TreeNode* right;
};

bool TreeType::IsFull() const
// Returns true if there is no room for another item
//  on the free store; false otherwise.
{
  TreeNode* location;
  try
  {
    location = new TreeNode;
    delete location;
    return false;
  }
  catch(std::bad_alloc exception)
  {
    return true;
  }
}

bool TreeType::IsEmpty() const
// Returns true if the tree is empty; false otherwise.
{
  return root == NULL;
}

int CountNodes(TreeNode* tree);

int TreeType::LengthIs() const
// Calls recursive function CountNodes to count the
// nodes in the tree.
{
  return CountNodes(root);
}


int CountNodes(TreeNode* tree)
// Post: returns the number of nodes in the tree.
{
  if (tree == NULL)
    return 0;
  else
    return CountNodes(tree->left) + CountNodes(tree->right) + 1;
}

void Retrieve(TreeNode* tree,
     ItemType& item, bool& found);

void TreeType::RetrieveItem(ItemType& item, bool& found)
// Calls recursive function Retrieve to search the tree for item.
{
  Retrieve(root, item, found);
}


void Retrieve(TreeNode* tree,
     ItemType& item, bool& found)
// Recursively searches tree for item.
// Post: If there is an element someItem whose key matches item's,
//       found is true and item is set to a copy of someItem;
//       otherwise found is false and item is unchanged.
{
  if (tree == NULL)
    found = false;                     // item is not found.
  else if (item < tree->info)
    Retrieve(tree->left, item, found); // Search left subtree.
  else if (item > tree->info)
    Retrieve(tree->right, item, found);// Search right subtree.
  else
  {
    item = tree->info;                 // item is found.
    found = true;
   }
}

void Insert(TreeNode*& tree, ItemType item);

void TreeType::InsertItem(ItemType item)
// Calls recursive function Insert to insert item into tree.
{
  Insert(root, item);
}


void Insert(TreeNode*& tree, ItemType item)
// Inserts item into tree.
// Post:  item is in tree; search property is maintained.
{
  if (tree == NULL)
  {// Insertion place found.
    tree = new TreeNode;
    tree->right = NULL;
    tree->left = NULL;
    tree->info = item;
  }
  else if (item < tree->info)
    Insert(tree->left, item);    // Insert in left subtree.
  else
    Insert(tree->right, item);   // Insert in right subtree.
}
void DeleteNode(TreeNode*& tree);

void Delete(TreeNode*& tree, ItemType item);

void TreeType::DeleteItem(ItemType item)
// Calls recursive function Delete to delete item from tree.
{
  Delete(root, item);
}


void Delete(TreeNode*& tree, ItemType item)
// Deletes item from tree.
// Post:  item is not in tree.
{
  if (item < tree->info)
    Delete(tree->left, item);   // Look in left subtree.
  else if (item > tree->info)
    Delete(tree->right, item);  // Look in right subtree.
  else
    DeleteNode(tree);           // Node found; call DeleteNode.
}

void GetPredecessor(TreeNode* tree, ItemType& data);

void DeleteNode(TreeNode*& tree)
// Deletes the node pointed to by tree.
// Post: The user's data in the node pointed to by tree is no
//       longer in the tree.  If tree is a leaf node or has only
//       non-NULL child pointer the node pointed to by tree is
//       deleted; otherwise, the user's data is replaced by its
//       logical predecessor and the predecessor's node is deleted.
{
  ItemType data;
  TreeNode* tempPtr;

  tempPtr = tree;
  if (tree->left == NULL)
  {
    tree = tree->right;
    delete tempPtr;
  }
  else if (tree->right == NULL)
  {
    tree = tree->left;
    delete tempPtr;
  }
  else
  {
    GetPredecessor(tree->left, data);
    tree->info = data;
    Delete(tree->left, data);  // Delete predecessor node.
  }
}

void GetPredecessor(TreeNode* tree, ItemType& data)
// Sets data to the info member of the right-most node in tree.
{
  while (tree->right != NULL)
    tree = tree->right;
  data = tree->info;
}

void PrintTree(TreeNode* tree, std::ofstream& outFile)
// Prints info member of items in tree in sorted order on outFile.
{
  if (tree != NULL)
  {
    PrintTree(tree->left, outFile);   // Print left subtree.
    outFile << tree->info;
    PrintTree(tree->right, outFile);  // Print right subtree.
  }
}

void TreeType::Print(std::ofstream& outFile) const
// Calls recursive function Print to print items in the tree.
{
  PrintTree(root, outFile);
}

TreeType::TreeType()
{
  root = NULL;
}

void Destroy(TreeNode*& tree);

TreeType::~TreeType()
// Calls recursive function Destroy to destroy the tree.
{
  Destroy(root);
}


void Destroy(TreeNode*& tree)
// Post: tree is empty; nodes have been deallocated.
{
  if (tree != NULL)
  {
    Destroy(tree->left);
    Destroy(tree->right);
    delete tree;
  }
}

void TreeType::MakeEmpty()
{
  Destroy(root);
  root = NULL;
}


void CopyTree(TreeNode*& copy,
     const TreeNode* originalTree);

TreeType::TreeType(const TreeType& originalTree)
// Calls recursive function CopyTree to copy originalTree
//  into root.
{
  CopyTree(root, originalTree.root);
}

void TreeType::operator=
     (const TreeType& originalTree)
// Calls recursive function CopyTree to copy originalTree
// into root.
{
  {
  if (&originalTree == this)
    return;             // Ignore assigning self to self
  Destroy(root);      // Deallocate existing tree nodes
  CopyTree(root, originalTree.root);
  }

}
void CopyTree(TreeNode*& copy,
     const TreeNode* originalTree)
// Post: copy is the root of a tree that is a duplicate
//       of originalTree.
{
  if (originalTree == NULL)
    copy = NULL;
  else
  {
    copy = new TreeNode;
    copy->info = originalTree->info;
    CopyTree(copy->left, originalTree->left);
    CopyTree(copy->right, originalTree->right);
  }
}
// Function prototypes for auxiliary functions.

void PreOrder(TreeNode*, QueType&);
// Enqueues tree items in preorder.


void InOrder(TreeNode*, QueType&);
// Enqueues tree items in inorder.


void PostOrder(TreeNode*, QueType&);
// Enqueues tree items in postorder.


void TreeType::ResetTree(OrderType order)
// Calls function to create a queue of the tree elements in
// the desired order.
{
  switch (order)
  {
    case PRE_ORDER : PreOrder(root, preQue);
                     break;
    case IN_ORDER  : InOrder(root, inQue);
                     break;
    case POST_ORDER: PostOrder(root, postQue);
                     break;
  }
}


void PreOrder(TreeNode* tree,
     QueType& preQue)
// Post: preQue contains the tree items in preorder.
{
  if (tree != NULL)
  {
    preQue.Enqueue(tree->info);
    PreOrder(tree->left, preQue);
    PreOrder(tree->right, preQue);
  }
}


void InOrder(TreeNode* tree,
     QueType& inQue)
// Post: inQue contains the tree items in inorder.
{
  if (tree != NULL)
  {
    InOrder(tree->left, inQue);
    inQue.Enqueue(tree->info);
    InOrder(tree->right, inQue);
  }
}


void PostOrder(TreeNode* tree,
     QueType& postQue)
// Post: postQue contains the tree items in postorder.
{
  if (tree != NULL)
  {
    PostOrder(tree->left, postQue);
    PostOrder(tree->right, postQue);
    postQue.Enqueue(tree->info);
  }
}


void TreeType::GetNextItem(ItemType& item,
     OrderType order, bool& finished)
// Returns the next item in the desired order.
// Post: For the desired order, item is the next item in the queue.
//       If item is the last one in the queue, finished is true;
//       otherwise finished is false.
{
  finished = false;
  switch (order)
  {
    case PRE_ORDER  : preQue.Dequeue(item);
                      if (preQue.IsEmpty())
                        finished = true;
                      break;
    case IN_ORDER   : inQue.Dequeue(item);
                      if (inQue.IsEmpty())
                        finished = true;
                      break;
    case  POST_ORDER: postQue.Dequeue(item);
                      if (postQue.IsEmpty())
                        finished = true;
                      break;
  }
}



//1번.
/*
 function : 해당 값의 모든 조상노드들을 출력한다
 pre : tree가 initialized되어있어야 함. value가 tree 내부에 있어야 함
 post: 해당 value의 모든 조상을 출력
 */

void Imp_Ancestors_Iter(TreeNode*& root,ItemType value);

void TreeType::Ancestors_Iter(ItemType value)
{
    return Imp_Ancestors_Iter(root, value);
}

void Imp_Ancestors_Iter(TreeNode*& root,ItemType value)
{
    QueType result;
    TreeNode* parent = new TreeNode;
    TreeNode* obj = new TreeNode;
    bool found = false;
    ItemType item = 0;
    parent = NULL;
    obj = root;
    
    while(obj != NULL && !found)
    {
        if(value < obj->info)
        {
            parent = obj;
            result.Enqueue(parent->info);
            obj = obj->left;
        }
        else if(value > obj->info)
        {
            parent = obj;
            result.Enqueue(parent->info);
            obj = obj->right;
        }
        else
        {
            found = true;
        }
    }
    
    while(!result.IsEmpty())
    {
        result.Dequeue(item);
        cout << item << "\t";
    }
    
    cout << endl;
}

//2번.

void Imp_Ancestors_Recur(TreeNode*& root,ItemType value);

void TreeType::Ancestors_Recur(ItemType value)
{
    return Imp_Ancestors_Recur(root, value);
}

void Imp_Ancestors_Recur(TreeNode*& root,ItemType value)
{
    if(value < root->info)
    {
        cout << root->info << "\t";
        Imp_Ancestors_Recur(root->left, value);
    }
    else if(value > root->info)
    {
        cout << root->info << "\t";
        Imp_Ancestors_Recur(root->right, value);
    }
    else
    {
        return;
    }
    
}


//3번.

ItemType Imp_Smaller(TreeNode*& root, ItemType value);

ItemType TreeType::Smaller(ItemType value)
{
    return Imp_Smaller(root, value);
}

ItemType Imp_Smaller(TreeNode*& root, ItemType value)
{
    if(root == NULL)
    {
        return 0;
    }
    if(root->info < value)
    {
        return Imp_Smaller(root->left, value) + Imp_Smaller(root->right, value)+ 1;
    }
    else
    {
        return Imp_Smaller(root->left, value) + Imp_Smaller(root->right, value);
    }
    
}

//4번.


//////


void AddElement(TreeType& tree,int Array[],int from,int to);

void MakeTree(TreeType &tree, SortedType &list);
void TreeType::CallMakeTree(TreeType &tree, SortedType &list)
{
    return MakeTree(tree, list);
}

void MakeTree(TreeType &tree, SortedType &list)
{

    int length = list.LengthIs();  //리스트 크기를 얻는다
    int* array = new int[length];  //동적 배열 할당
    ItemType2 item_info;


    list.ResetList();

    for(int i=0; i < length; i++)
    {
        list.GetNextItem(item_info);
        array[i] = item_info.getvalue();
    }

    AddElement(tree, array, 0, length-1);
    
    delete [] array;  // 동적 배열 삭제
}

void AddElement(TreeType& tree,int Array[],int front, int rear)
{
    int mid;            //중간 값을 기록하는 변수
    if(front <= rear){        //함수의 종료조건
        mid = (front + rear) / 2;
        tree.InsertItem(Array[mid]);
        AddElement(tree,Array, front,((front + rear) / 2)-1);
        AddElement(tree,Array,((front + rear) / 2)+1,rear);
    }
}


/////////////////
//이건 만들다 실패한거
/*
void Imp_MakeTree(TreeNode*& root, SortedType list,int first, int last);

void TreeType::MakeTree_Trial(SortedType list)
{
    int first = 0, last = list.LengthIs()-1;
    return Imp_MakeTree(root, list, first, last);
}

void Imp_MakeTree(TreeNode*& root, SortedType list,int first, int last)
{
    //1. length / 2 해당하는 인덱스 갖고오기 --> 노드 생성
    //2. 1) root == null일때 : 인덱스 == root root->left , root->right
    //   2) 인덱스 < root 일때 : root->left
    //   3) 인덱스 > root 일때 : root->right
    TreeNode* temp = new TreeNode;
//    temp = NULL;
    
    if(first >= last) // 부호 이렇게 하는게 맞나? 다시확인
        return;     //base case
    
    if(root == NULL)
    {
        temp->info = list.GetMiddle(first, last);
        temp->left = NULL;
        temp->right = NULL;
        root = temp;
        
        Imp_MakeTree(root->left, list, first, (first + last / 2)-1);
        Imp_MakeTree(root->right, list,((first + last) /2)+1,last);
    }
}
*/


//5번.
bool Imp_MatchingItem(TreeNode*& root, ItemType2 item);


bool TreeType::MatchingItem(UnsortedType list)
{
    list.ResetList();
    ItemType2 item;

    for(int i = 0; i < list.LengthIs(); i++)
    {
        list.GetNextItem(item);
        if(Imp_MatchingItem(root, item) == false)
            return false;
    }

    return true;
}

bool Imp_MatchingItem(TreeNode*& root, ItemType2 item)
{
    
    if(root == NULL) // base case
        return false;
    else
    {
        if(root->info == item.getvalue())
            return true;
        else
        {
            if(Imp_MatchingItem(root->left, item) == true)
                return true;
        
            else{
                if(Imp_MatchingItem(root->right, item) == true)
                    return  true;
                
                return false;
            }
        }
    }
    
}
