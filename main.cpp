// Лабораторная работа №5
// main.cpp
// Тимофеев Дмитрий, группа 6383
// 12.11.17
//
// Бинарные деревья и алгоритмы сжатия

#include <iostream>
#include"codetree.h"

using namespace std;
using namespace code_tree;

void test(){
    //while(true){
        char code[1000]="(составление актов описания сохранности, профилактическая консервация и реставрация, упаковка и распаковка экспонатов). Проведено 150 заседаний Реставрационной комиссии, на которых рассматривались самые важные ";
        //scanf("%s",code);
        cout<<encode(code)<<endl;
        cout<<decode(encode(code))<<endl<<endl;
    //}
}

int main(){
    test();
    //cout<<"Введите закодированную строку"<<endl;
    //char code[1000];
    //scanf("%s",code);
    //cout<<decode(code)<<endl;
    return 0;
}

