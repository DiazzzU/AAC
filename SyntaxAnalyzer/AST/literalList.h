#ifndef LITERAL_LIST_H
#define LITERAL_LIST_H

#include <string>
#include <vector>
#include "node.h"

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

    Node* codegen(Memory* memory) {
        return this;
    }
    void print() {
        std::cout << "'(";
        for (auto x : listVal) {
            x->print();
            std::cout << ' ';
        }
        std::cout << ")";
    }

};

#endif