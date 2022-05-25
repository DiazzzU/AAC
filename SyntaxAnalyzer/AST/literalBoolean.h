#ifndef LITERAL_BOOLEAN_H
#define LITERAL_BOOLEAN_H

#include <string>
#include <vector>
#include "node.h"
#include <SyntaxAnalyzer/AST/memory.h>

class BooleanLiteral: public NodeLiteral {
public:
    bool booleanVal;

    BooleanLiteral() {
        this->nodeType = "literal";
        this->type = "Boolean";
        this->booleanVal = false;
    }

    virtual bool getBooleanVal() {
        return booleanVal;
    }

    virtual void setBooleanVal(bool x) {
        this->booleanVal = x;
    }

    Node* codegen(Memory* memory) {
        return this;
    }
    void print() {
        std::cout << booleanVal;
    }

};

#endif