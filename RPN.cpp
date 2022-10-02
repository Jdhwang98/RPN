//
// Created by Johnathan Hwang on 10/1/22.
//

#ifndef LINKEDLIST_RPN_CPP
#define LINKEDLIST_RPN_CPP
#include "RPN.h"


template<class T>
RPN<T>::RPN() {

}

template<class T>
bool RPN<T>::isNumber(char index) {
//    double num = std::stod(index); //convert string to double
    unsigned num = (int)index;
    if(isdigit(num))
    {
        //return true if number
        std::cout << "number\n";
        return true;
    }
    else
    {
        std::cout << "operator\n";
        return false;
    }

}

template<class T>
double RPN<T>::doOperation(int lhs, int rhs, char operation) {

    switch (operation) {
        case '+':
            return lhs + rhs;
        case '-':
            return lhs - rhs;
        case '*':
            return lhs*rhs;
        case '/':
            return lhs/rhs;
        default:
            return 0;
    }
}

template<class T>
double RPN<T>::calculate(std::string &posFix) {
    Stack<T> _stack;
    Queue<T> _queue;

    for(auto i: posFix){        //loop based on queue size and access values
        //char index = i;  //keep track of value at position
        if(isNumber(posFix[i])){    //check if string is number
            _queue.push(posFix[i]);//push string to queue
        }
        else if(!isNumber(posFix[i]))
        {
            _stack.push(posFix[i]);
        }
        else{
            char operation = _stack.top();//checking operation at index of queue
            _stack.pop();
            int rhs = std::stoi(_queue.front()); //converting string to num from stack
            _queue.pop();
            int lhs = std::stoi(_queue.front()); //converting string to num from stack
            _queue.pop();
            int solution = doOperation(lhs,rhs,operation); //add values with operation
            _queue.push(std::to_string(solution));  //push new value to stack
        }
    }
    return std::stod(_stack.top());
}

template<class T>
RPN<T>::RPN(std::string postfix)
{
    calculate(postfix);
}

#endif