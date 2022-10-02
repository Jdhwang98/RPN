//
// Created by Johnathan Hwang on 10/1/22.
//

#ifndef LINKEDLIST_RPN_H
#define LINKEDLIST_RPN_H
#include "Stack.h"
#include "Queue.h"

template<class T>
class RPN {
private:
    int lhs, rhs;

public:
    //stoi = string to int
    //isDigit check if int
    RPN();
    RPN(std::string postfix);
    bool isNumber(char index);
    static double doOperation(int lhs, int rhs, char operation);
    double calculate(std::string& posFix);
};

#include "RPN.cpp"
#endif //LINKEDLIST_RPN_H
