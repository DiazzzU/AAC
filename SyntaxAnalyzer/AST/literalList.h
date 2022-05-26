#ifndef LITERAL_LIST_H
#define LITERAL_LIST_H

#include <string>
#include <vector>
#include "node.h"
#include <SyntaxAnalyzer/Semantics/List.h>

class ListLiteral: public NodeLiteral {
public:
    std::vector <Node*> listVal;

    ListLiteral() {
        this->nodeType = "literal";
        this->type = "List";
    }

    virtual std::vector <Node*> getListVal() {
        return listVal;
    }

    virtual void addListVal(Node* val) {
        this->listVal.push_back(val);
    }

    Literal* codegen(Memory* memory) {
        List* node = new List();

        for (auto x : listVal) {
            Literal* element = x->codegen(memory);
            node->addListVal(element);
        }
        return node;
    }

};

#endif