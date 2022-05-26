#ifndef REAL_H
#define REAL_H

#include <string>
#include <vector>
#include <SyntaxAnalyzer/Semantics/Literal.h>

class Real: public Literal {
public:
    double realVal;

    Real() {
        this->type = "Real";
        this->realVal = 0;
    }

    virtual double getRealVal() {
        return realVal;
    }

    virtual void setRealVal(double x) {
        this->realVal = x;
    }

    void print() {
        std::cout << realVal;
    }

};

#endif