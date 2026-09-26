#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(){
        data = 12;
        next= NULL;
    }
};
int main(){
    Node *first = new Node;
    cout<<first->data;
    return 0;
}