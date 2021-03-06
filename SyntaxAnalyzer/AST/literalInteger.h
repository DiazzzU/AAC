#ifndef LITERAL_INTEGER_H
#define LITERAL_INTEGER_H

#include <string>
#include <vector>
#include "node.h"
#include <SyntaxAnalyzer/AST/memory.h>
#include <SyntaxAnalyzer/Semantics/Integer.h>

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

    Literal* codegen(Memory* memory) {
        Integer* node = new Integer();
        node->setIntVal(intVal);
        return node;
    }
    void print() {
        std::cout << intVal;
    }
};

#endif