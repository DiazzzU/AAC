#ifndef LITERAL_ARRAY_H
#define LITERAL_ARRAY_H

#include <string>
#include <vector>
#include "node.h"
#include <SyntaxAnalyzer/AST/memory.h>

class ArrayLiteral: public NodeLiteral {
public:
    std::vector <Node*> arrayVal;

    ArrayLiteral() {
        this->nodeType = "literal";
        this->type = "Array";
    }

    virtual std::vector <Node*> getArrayVal() {
        return arrayVal;
    }

    virtual void addArrayVal(Node* val) {
        this->arrayVal.push_back(val);
    }

    Node* codegen(Memory* memory) {
        return this;
    }
    void print() {
        std::cout << "'[";
        for (auto x : arrayVal) {
            x->print();
            std::cout << ' ';
        }
        std::cout << "]";
    }
};

#endif