// Лабораторная работа №5
// main.cpp
// Тимофеев Дмитрий, группа 6383
// 12.11.17
//
// Бинарные деревья и алгоритмы сжатия
#include<stdio.h>
#include <iostream>
#include<fstream>
#include"codetree.h"

#include"bitstream.h"
#include<sstream>

using namespace std;
using namespace code_tree;

// a0b00r0100k01100d011011001000!
void test(){
    ifstream input("msg");
    ofstream output("code");
    BitOutputStream bos(output);
    cout<<"start"<<endl;
    encode(input, bos);
    cout<<"coded"<<endl;
    output.close();
    input.close();
    ifstream coded("code");
    ofstream decoded("encoded");
    BitInputStream bis(coded);
    decode(bis, decoded);
    cout<<"decoded"<<endl;
}

void test2(){
    //stringstream in;
    //in<<"Яя!\n";
    stringstream ss;
    BitOutputStream bos(ss);
    BitInputStream bis(ss);
    bos.writeChar('я');

    cout<<(int)'я'<<endl;


    bos.close();
    //encode(in,bos);
    //decode(bis, cout);

    cout<<(int)bis.readBit();
    cout<<(int)bis.readBit();
    cout<<(int)bis.readBit();
    cout<<(int)bis.readBit();
    cout<<(int)bis.readBit();
    cout<<(int)bis.readBit();
    cout<<(int)bis.readBit();
    cout<<(int)bis.readBit();

}

int main(){
    test();
    //test2();
    return 0;
}

