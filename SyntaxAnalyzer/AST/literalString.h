#ifndef LITERAL_STRING_H
#define LITERAL_STRING_H

#include <string>
#include <vector>
#include "node.h"
#include <SyntaxAnalyzer/AST/memory.h>
#include <SyntaxAnalyzer/Semantics/String.h>

class StringLiteral: public NodeLiteral {
public:
    std::string stringVal;

    StringLiteral() {
        this->nodeType = "literal";
        this->type = "String";
        this->stringVal = "";
    }

    virtual std::string getStringVal() {
        return stringVal;
    }

    virtual void setStringVal(std::string x) {
        this->stringVal = x;
    }

    Literal* codegen(Memory* memory) {
        String* node = new String();
        node->setStringVal(stringVal);
        return node;
    }
};

#endif