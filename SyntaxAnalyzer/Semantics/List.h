#ifndef LIST_H
#define LIST_H

#include <string>
#include <vector>
#include <SyntaxAnalyzer/Semantics/Literal.h>

class List: public Literal {
public:
    std::vector <Literal*> listVal;

    List() {
        this->type = "List";
    }

    virtual std::vector <Literal*> getListVal() {
        return listVal;
    }

    virtual void addListVal(Literal* val) {
        this->listVal.push_back(val);
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