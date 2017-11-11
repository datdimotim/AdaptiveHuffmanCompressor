#include <iostream>
#include"codetree.h"

using namespace std;
using namespace code_tree;

void codeDecodeTest(){
    char* code=encode("Думаю пока нет смысла приводить здесь полный листинг реализации класса string, так как данная статья рассчитана на начинающих программистов, и в ней я планирую скорее научить вас использовать string, нежели объяснять его внутреннее представление. Я привёл здесь определение шаблона и описание некоторых конструкторов, только чтобы показать вам, что это действительно класс. Который можете реализовать и вы (возможно не такой эффективный и гибкий).Ну что же, настало время реализовать свой простенький класс string. Но перед этим, не забывайте, что класс string обладает всеми возможностями стандартных типов. Если вы знакомы с классами, то наверное уже догадались, что для реализации таких возможностей, в классе должны быть перегружены многие операторы (в том числе ввода >> и вывода <<). Кроме того класс string содержит ещё множество полезных методов.");
    char* msg=decode(code);
    cout<<msg<<endl;
    delete[] msg;
    delete[] code;


    //cout<<decode(encode("abrakadabra!"))<<endl;
    //cout<<decode(encode("aaabrakadabra!"))<<endl;
    //cout<<decode(encode("bv sssre uufffff!"))<<endl;
    //cout<<decode(encode("bv sssre uufffff!"))<<endl;
    //cout<<decode(encode("v sssrffffffffffff"))<<endl;
    //cout<<decode(encode("//Node* esc=new Node('e',1,nullptr,nullptr,nullptr);"))<<endl;
}

int main(){
    codeDecodeTest();
    return 0;
}

