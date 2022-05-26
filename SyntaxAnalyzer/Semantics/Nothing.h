#ifndef NOTHING_H
#define NOTHING_H

#include <string>
#include <vector>
#include <SyntaxAnalyzer/Semantics/Literal.h>

class Nothing: public Literal {
public:
    Nothing() {
        this->type = "Nothing";
    }
    void print() {
        
    }
};

#endif