// Ebram Thabet 900214496
#include <vector>
#include "linkedlist.h"
using namespace std;

Node * IsValueRepeated(Node *h , int v){
    Node *q = h; 
    while(q != NULL){
        if(v == q->value) {
            return q;
        }
        q = q->n_after;
    }
    Node *x = NULL;
    return x;
}
Elinkedlist from_vectoll(vector <int> v){
Elinkedlist e;
for(int i = 0; i < v.size(); i++){
    if(IsValueRepeated(e.get_head() , v[i]) == NULL){  // if NULL this means that the value was not repeated in the list before
        
        Node *x = new Node();
        x->value = v[i];
        x->num_occ ++;
        e.AddNode(x); 
    }
    else{
        IsValueRepeated(e.get_head() , v[i])->num_occ++;
    }
}
return e;
}
//function prints the vector
void printvec(vector <int> &v1){
    for(vector <int> :: iterator it = v1.begin(); it != v1.end(); it++){
        cout << *it << '\t';
    }
    cout << endl;
}

void insertafter(int x , int y , vector <int> &v1){
    for(vector <int> :: iterator it = v1.begin(); it != v1.end(); it++){
        if(*it == x){
            vector <int> :: iterator i = v1.insert(++it , y); 
            it = i; // insert returns an iterator pointing at the inserted element
        }
    }
}

int main(){
int n , k;
cout << "Enter the number of integers\n";
cin >> n;
vector <int> nums;
for(int i = 0; i < n; i++){
cout << "Enter num " << i+1 << ": ";  
cin >> k;
nums.push_back(k);
}

int x,y;
cout << "Insert the value that you want insertion after\n";
cin >>x;
cout << "Insert the value that you want to insert\n";
cin >>y;

cout << "+++++++++++++ After inserting +++++++++++++"<<endl; 
insertafter(x,y,nums);
printvec(nums);

// creating some nodes
cout << endl<<"++++++++++++++++++++ Creating a linkedlist, Adding nodes, and removing some ++++++++++++++++++++"<<endl << endl;

Node *node1 = new Node() , *node2 = new Node() , *node3 = new Node();
node1->value = 2; node1->num_occ= 1; node3->num_occ= 1; node2->num_occ= 1; node2->value = 3; node3->value = 4;

Elinkedlist l;
cout << "After adding 3 nodes\n";
l.AddNode(node1); l.AddNode(node2); l.AddNode(node3);
l.printlist();

cout << "After removing 2 nodes\n";
l.removeNode(); l.removeNode();
l.printlist();

cout << endl<<"++++++++++++++++++++ End of line ++++++++++++++++++++"<<endl << endl;
cout << "Way 1. After creating a linkedlist using the integers in the vector using the function written in the main\n";
Elinkedlist l1 = from_vectoll(nums);
l1.printlist();
cout << endl << "Sum of all nodes: " << l1.Get_Sum_All();
cout << endl<<"++++++++++++++++++++ End of line ++++++++++++++++++++"<<endl << endl;

cout << "Way 2. After creating a linkedlist using the integers in the vector using the member function written in the .h file\n";
Elinkedlist e;
e.from_vectoll(nums);
e.printlist();
cout << endl << "Sum of all nodes: " <<e.Get_Sum_All();
cout << endl<<"++++++++++++++++++++ End of line ++++++++++++++++++++"<<endl << endl;

}