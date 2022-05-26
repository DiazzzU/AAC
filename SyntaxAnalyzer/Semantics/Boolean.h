#ifndef BOOLEAN_H
#define BOOLEAN_H

#include <string>
#include <vector>
#include <SyntaxAnalyzer/Semantics/Literal.h>

class Boolean: public Literal {
public:
    bool booleanVal;

    Boolean() {
        this->type = "Boolean";
        this->booleanVal = false;
    }

    virtual bool getBooleanVal() {
        return booleanVal;
    }

    virtual void setBooleanVal(bool x) {
        this->booleanVal = x;
    }

    void print() {
        std::cout << (booleanVal ? "true" : "false");
    }

};

#endif