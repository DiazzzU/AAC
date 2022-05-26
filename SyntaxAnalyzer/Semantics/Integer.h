#ifndef INTEGER_H
#define INTEGER_H

#include <string>
#include <vector>
#include <SyntaxAnalyzer/Semantics/Literal.h>

class Integer: public Literal {
public:
    int intVal;

    Integer() {
        this->type = "Integer";
        this->intVal = 0;
    }

    virtual int getIntVal() {
        return intVal;
    }

    virtual void setIntVal(int x) {
        this->intVal = x;
    }

    void print() {
        std::cout << intVal;
    }
};

#endif