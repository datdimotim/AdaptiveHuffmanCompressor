#include <iostream>
#include"codetree.h"

using namespace std;
using namespace code_tree;


void iterator_test(){
    Node** nodes=new Node*[7];
    for(int i=0;i<7;i++)nodes[i]=new Node(i+1,i+1,nullptr,nullptr,nullptr);

    nodes[6]->left=nodes[4]; nodes[4]->parent=nodes[6];
    nodes[6]->right=nodes[5]; nodes[5]->parent=nodes[6];

    nodes[4]->left=nodes[0]; nodes[0]->parent=nodes[4];
    nodes[4]->right=nodes[1]; nodes[1]->parent=nodes[4];

    nodes[5]->left=nodes[2]; nodes[2]->parent=nodes[5];
    nodes[5]->right=nodes[3]; nodes[3]->parent=nodes[5];

    Node* next=nodes[0];
    while(next!=nullptr){
        cout<<"node num="<<(int)next->symbol<<" w= "<<next->weight<<endl;
        next=iterateNext(next);
        //cin.get();
    }
}

void iterator_on_level_test(){
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
        next=iterateNextOnThisLevelNew(next);
        //cin.get();
    }

    cout<<"=========="<<endl;

    next=nodes[4];
    while(next!=nullptr){
        cout<<"node num="<<(int)next->symbol<<" w= "<<next->weight<<endl;
        next=iterateNextOnThisLevelNew(next);
        //cin.get();
    }

    cout<<"=========="<<endl;

    next=nodes[8];
    while(next!=nullptr){
        cout<<"node num="<<(int)next->symbol<<" w= "<<next->weight<<endl;
        next=iterateNextOnThisLevelNew(next);
        //cin.get();
    }

    cout<<"=========="<<endl;

    next=nodes[10];
    while(next!=nullptr){
        cout<<"node num="<<(int)next->symbol<<" w= "<<next->weight<<endl;
        next=iterateNextOnThisLevelNew(next);
        //cin.get();
    }
}


int main(){
    iterator_on_level_test();
    return 0;
}

