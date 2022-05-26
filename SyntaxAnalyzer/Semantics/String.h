#ifndef STRING_H
#define STRING_H

#include <string>
#include <vector>
#include <SyntaxAnalyzer/Semantics/Literal.h>

class String: public Literal {
public:
    std::string stringVal;

    String() {
        this->type = "String";
        this->stringVal = "";
    }

    virtual std::string getStringVal() {
        return stringVal;
    }

    virtual void setStringVal(std::string x) {
        this->stringVal = x;
    }

    void print() {
        std::cout << "\"" << stringVal << "\"";
    }

};

#endif