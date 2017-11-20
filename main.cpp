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
#include<string.h>

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

const char* MSG_INFO="Неправильное команда. Пример команды:\n\thuffman -e input output\n\thuffman -d input output\n";

int main(int c, char* args[]){
    if(c!=4){
        cout<<MSG_INFO;
        return 0;
    }

    if(strcmp(args[2],args[3])==0){
        cout<<"Имя входного файла совпадает с именем выходного!"<<endl;
        return 0;
    }

    ifstream input(args[2]);
    if(!input){
        cout<<"входной файл не найден!"<<endl;
        return 0;
    }

    if(strcmp(args[1],"-e")==0){
        ofstream output(args[3]);
        BitOutputStream bos(output);
        encode(input, bos);
        return 0;
    }

    if(strcmp(args[1],"-d")==0){
        ofstream output(args[3]);
        BitInputStream bis(input);
        decode(bis, output);
        return 0;
    }

    cout<<MSG_INFO;
    return 0;
}

