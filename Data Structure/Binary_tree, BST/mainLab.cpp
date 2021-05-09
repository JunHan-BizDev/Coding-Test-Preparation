#include <iostream>
#include "TreeType.h"
using namespace std;

int main(){
    TreeType tree;
//    tree.InsertItem(4);
//    tree.InsertItem(2);
//    tree.InsertItem(8);
//    tree.InsertItem(1);
//    tree.InsertItem(3);
    
    SortedType list;
    ItemType2 a,b,c,d,e,f,g;
    a.Initialize(1);
    b.Initialize(2);
    c.Initialize(3);
    d.Initialize(4);
    e.Initialize(5);
    f.Initialize(6);
    g.Initialize(7);
    
    
    list.InsertItem(a);
    list.InsertItem(b);
    list.InsertItem(c);
    list.InsertItem(d);
    list.InsertItem(e);
    list.InsertItem(f);
    list.InsertItem(g);

    
    
    
    tree.CallMakeTree(tree, list);
//    tree.MakeTree_Trial(list);

//    tree.MakeTree(list);
    
    
//    cout << tree.MatchingItem(list);
    
    return 0;
}
