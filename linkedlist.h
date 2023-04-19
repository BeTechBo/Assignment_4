#ifndef linkedlist
#define linkedlist
#include <iostream>
using namespace std;
struct Node{
    int value , num_occ;
    Node* n_after;
};

class Elinkedlist{
Node * head = NULL;
public:

Node * IsValueRepeated(int v){
    Node *q = head; 
    while(q != NULL){
        if(v == q->value) {
            return q;
        }
        q = q->n_after;
    }
    Node *x = NULL;
    return x;
}

Elinkedlist * from_vectoll(vector <int> v){

for(int i = 0; i < v.size(); i++){
    if(IsValueRepeated(v[i]) == NULL){
        Node *x = new Node();
        x->value = v[i];
        x->num_occ ++;
        AddNode(x); 
    }
    else{
        IsValueRepeated(v[i])->num_occ++;
    }
}
return this;
}


int Get_Sum_All() {
    Node * q = head;
    int tot = 0;
    while(q != NULL){
        tot+=(q->value*q->num_occ);
        q = q->n_after;
    }
    return tot;
}
void printlist(){
    Node * q = head; 
    while(q != NULL){
        cout << "Value : " <<q->value << '\t' << "number of occuerances: " << q->num_occ << endl;
        q = q->n_after;
    }
    cout << endl;
}

void AddNode(Node * n){
Node *q , *t;
q = head;
if(head == NULL){head = n;}
else{
while(q != NULL){
if(q->n_after == NULL){
t = q;
}
q = q->n_after;
}
q = n;
n->n_after = NULL;
t->n_after = n;
}
}
Node* get_head(){
    return head;
}

void removeNode(){
Node *q;
q = head;
if(head ==  NULL){cout << "List is empty\n";}
else if(head ->n_after == NULL){
    head = NULL;
}
else{
while(q->n_after->n_after != NULL){
        q = q->n_after;
    }
    delete (q->n_after);
    q->n_after = NULL;

}
}
};
#endif