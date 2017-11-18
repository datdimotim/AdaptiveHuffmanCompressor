// Лабораторная работа №5
// main.cpp
// Тимофеев Дмитрий, группа 6383
// 12.11.17
//
// Бинарные деревья и алгоритмы сжатия

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
    encode(input, bos);
    output.close();
    input.close();
    ifstream coded("code");
    ofstream decoded("encoded");
    BitInputStream bis(coded);
    decode(bis, decoded);
}

void test2(){
    stringstream in;
    in<<"abrakadabra!\n";
    stringstream ss;
    BitOutputStream bos(ss);
    BitInputStream bis(ss);
    encode(in,bos);
    decode(bis, cout);
}

int main(){
    test();
    return 0;
}

