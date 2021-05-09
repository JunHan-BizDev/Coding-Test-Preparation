#include <iostream>
#include "TreeType.h"
using namespace std;

int main(){
    
    TreeType tree;
    
    tree.InsertItem('k');
    tree.InsertItem('d');
    tree.InsertItem('o');
    tree.InsertItem('a');
    tree.InsertItem('f');
    tree.InsertItem('x');
    tree.InsertItem('v');
    tree.InsertItem('e');


    tree.DeleteItem('d');
    
    return 0;
}
