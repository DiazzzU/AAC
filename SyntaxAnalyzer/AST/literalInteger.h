#ifndef LITERAL_INTEGER_H
#define LITERAL_INTEGER_H

#include <string>
#include <vector>
#include "node.h"
#include <SyntaxAnalyzer/AST/memory.h>

class IntegerLiteral: public NodeLiteral {
public:
    int intVal;

    IntegerLiteral() {
        this->nodeType = "literal";
        this->type = "Integer";
        this->intVal = 0;
    }

    virtual int getIntVal() {
        return intVal;
    }

    virtual void setIntVal(int x) {
        this->intVal = x;
    }

    Node* codegen(Memory* memory) {
        return this;
    }
    void print() {
        std::cout << intVal;
    }
};

#endif