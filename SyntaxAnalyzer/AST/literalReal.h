#ifndef LITERAL_REAL_H
#define LITERAL_REAL_H

#include <string>
#include <vector>
#include "node.h"
#include <SyntaxAnalyzer/AST/memory.h>
#include <SyntaxAnalyzer/Semantics/Real.h>

class RealLiteral: public NodeLiteral {
public:
    double realVal;

    RealLiteral() {
        this->nodeType = "literal";
        this->type = "Real";
        this->realVal = 0;
    }

    virtual double getRealVal() {
        return realVal;
    }

    virtual void setRealVal(double x) {
        this->realVal = x;
    }

    Literal* codegen(Memory* memory) {
        Real* node = new Real();
        node->setRealVal(realVal);
        return node;
    }
};

#endif