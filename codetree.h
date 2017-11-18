// Лабораторная работа №5
// codetree.h
// Тимофеев Дмитрий, группа 6383
// 12.11.17
//
// Бинарные деревья и алгоритмы сжатия

#ifndef CODETREE
#define CODETREE

#include<iostream>
#include"bitstream.h"

namespace code_tree {
    void encode(std::istream &in, BitOutputStream &code);
    void decode(BitInputStream &in, std::ostream &code);
}

#endif // CODETREE

