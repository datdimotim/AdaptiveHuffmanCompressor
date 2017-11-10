#include <iostream>
#include"codetree.h"

using namespace std;
using namespace code_tree;

void iterate_test(){
    Node** nodes=new Node*[11];
    for(int i=0;i<11;i++)nodes[i]=new Node(i,i,nullptr,nullptr,nullptr);

    nodes[10]->left=nodes[8]; nodes[8]->parent=nodes[10];
    nodes[10]->right=nodes[9]; nodes[9]->parent=nodes[10];
    nodes[8]->left=nodes[4]; nodes[4]->parent=nodes[8];
    nodes[8]->right=nodes[5]; nodes[5]->parent=nodes[8];
    nodes[4]->left=nodes[0]; nodes[0]->parent=nodes[4];
    nodes[4]->right=nodes[1]; nodes[1]->parent=nodes[4];
    nodes[9]->left=nodes[6]; nodes[6]->parent=nodes[9];
    nodes[9]->right=nodes[7]; nodes[7]->parent=nodes[9];
    nodes[7]->left=nodes[2]; nodes[2]->parent=nodes[7];
    nodes[7]->right=nodes[3]; nodes[3]->parent=nodes[7];

    Node* next=nodes[0];
    while(next!=nullptr){
        cout<<"node num="<<(int)next->symbol<<" w= "<<next->weight<<endl;
        next=iterate(next);
        //cin.get();
    }
}

int h(Node* root){
    if(root==nullptr)return 0;
    else return 1+max(h(root->left),h(root->right));
}

namespace code_tree{
    Node* findFirstOnLevel(Node* elem, int n);
}

Node* first(Node* n){
    while(n->parent!=nullptr)n=n->parent;
    return findFirstOnLevel(n,h(n));
}

void print(Node* elem){
    Node* next=first(elem);
    while(next!=nullptr){
        cout<<"node num="<<(int)next->symbol<<" w= "<<next->weight<<endl;
        next=iterate(next);
    }
    cout<<"======"<<endl;
}

void recKLP(Node* elem){
    if(elem==nullptr){
        cout<<"$";
        return;
    }
    cout<<"("<<(int)elem->symbol;
    recKLP(elem->left);
    recKLP(elem->right);
    cout<<")";
}

void printKLP(Node* elem){
    while(elem->parent!=nullptr)elem=elem->parent;
    recKLP(elem);
    cout<<endl;
}

void test(){
    Node** nodes=new Node*[11];
    for(int i=0;i<11;i++)nodes[i]=new Node(i,i,nullptr,nullptr,nullptr);

    nodes[10]->left=nodes[8]; nodes[8]->parent=nodes[10];
    nodes[10]->right=nodes[9]; nodes[9]->parent=nodes[10];
    nodes[8]->left=nodes[4]; nodes[4]->parent=nodes[8];
    nodes[8]->right=nodes[5]; nodes[5]->parent=nodes[8];
    nodes[4]->left=nodes[0]; nodes[0]->parent=nodes[4];
    nodes[4]->right=nodes[1]; nodes[1]->parent=nodes[4];
    nodes[9]->left=nodes[6]; nodes[6]->parent=nodes[9];
    nodes[9]->right=nodes[7]; nodes[7]->parent=nodes[9];
    nodes[7]->left=nodes[2]; nodes[2]->parent=nodes[7];
    nodes[7]->right=nodes[3]; nodes[3]->parent=nodes[7];

    nodes[10]->weight=19;
    nodes[8]->weight=9;
    nodes[9]->weight=10;
    nodes[4]->weight=4;
    nodes[5]->weight=5;
    nodes[0]->weight=2;
    nodes[1]->weight=2;
    nodes[6]->weight=5;
    nodes[7]->weight=5;
    nodes[2]->weight=2;
    nodes[3]->weight=3;

    int step=0;
    while(true){
        step++;
        int r=rand()%11;
        if(nodes[r]->left!=nullptr)continue;
        //if(step==55){
            //print(nodes[0]);
            //printKLP(nodes[0]);
            //cout<<"r="<<r<<endl;
        //}
        incrementWeight(nodes[r]);
        Node* next=first(nodes[0]);
        int prevWeight=next->weight;
        while(next!=nullptr){
            if(prevWeight>next->weight){
                cout<<"error on step="<<step<<endl;
                print(next);
                return;
            }
            prevWeight=next->weight;
            next=iterate(next);
        }
    }
}

void testUpdating(){
    Node** nodes=new Node*[11];
    for(int i=0;i<11;i++)nodes[i]=new Node(i,i,nullptr,nullptr,nullptr);

    nodes[10]->left=nodes[8]; nodes[8]->parent=nodes[10];
    nodes[10]->right=nodes[9]; nodes[9]->parent=nodes[10];
    nodes[8]->left=nodes[4]; nodes[4]->parent=nodes[8];
    nodes[8]->right=nodes[5]; nodes[5]->parent=nodes[8];
    nodes[4]->left=nodes[0]; nodes[0]->parent=nodes[4];
    nodes[4]->right=nodes[1]; nodes[1]->parent=nodes[4];
    nodes[9]->left=nodes[6]; nodes[6]->parent=nodes[9];
    nodes[9]->right=nodes[7]; nodes[7]->parent=nodes[9];
    nodes[7]->left=nodes[2]; nodes[2]->parent=nodes[7];
    nodes[7]->right=nodes[3]; nodes[3]->parent=nodes[7];

    nodes[10]->weight=19;
    nodes[8]->weight=9;
    nodes[9]->weight=10;
    nodes[4]->weight=4;
    nodes[5]->weight=5;
    nodes[0]->weight=2;
    nodes[1]->weight=2;
    nodes[6]->weight=5;
    nodes[7]->weight=5;
    nodes[2]->weight=2;
    nodes[3]->weight=3;

    while(true){
        Node* next=first(nodes[0]);
        while(next!=nullptr){
            cout<<"node num="<<(int)next->symbol<<" w= "<<next->weight<<endl;
            next=iterate(next);
        }
        cout<<"======"<<endl;

        int n;
        cin>>n;
        incrementWeight(nodes[n]);

    }
}

int main(){
    testUpdating();

    return 0;
}

