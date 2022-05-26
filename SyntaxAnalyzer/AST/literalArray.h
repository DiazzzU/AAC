#ifndef LITERAL_ARRAY_H
#define LITERAL_ARRAY_H

#include <string>
#include <vector>
#include "node.h"
#include <SyntaxAnalyzer/AST/memory.h>
#include <SyntaxAnalyzer/Semantics/Array.h>

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

    Literal* codegen(Memory* memory) {
        Array* node = new Array();

        std::string curType = "";

        for (auto x : arrayVal) {
            Literal* element = x->codegen(memory);
            if (curType != "" && curType != element->getType()) {
                std::cout << "TypeError";
                exit(0);
            }
            curType = element->getType();
            node->addArrayVal(element);
        }
        return node;
    }
};

#endif