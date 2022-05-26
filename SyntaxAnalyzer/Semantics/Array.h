#ifndef ARRAY_H
#define ARRAY_H

#include <string>
#include <vector>
#include <SyntaxAnalyzer/Semantics/Literal.h>

class Array: public Literal {
public:
    std::vector <Literal*> arrayVal;

    Array() {
        this->type = "Array";
    }

    virtual std::vector <Literal*> getArrayVal() {
        return arrayVal;
    }

    virtual void addArrayVal(Literal* val) {
        this->arrayVal.push_back(val);
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