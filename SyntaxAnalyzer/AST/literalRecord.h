#ifndef LITERAL_RECORD_H
#define LITERAL_RECORD_H

#include <string>
#include <vector>
#include <map>
#include "node.h"
#include <SyntaxAnalyzer/AST/memory.h>

class RecordLiteral: public NodeLiteral {
public:
    std::map < std::string, Node*> recordVal;

    RecordLiteral() {
        this->nodeType = "literal";
        this->type = "Record";
    }

    virtual std::map < std::string, Node*> getRecordVal() {
        return recordVal;
    }

    virtual void addRecordVal(std::string key, Node* val) {
        this->recordVal[key] = val;
    }

    Node* codegen(Memory* memory) {
        return this;
    }

    void print() {
        std::cout << "(record ";
        for (auto x : recordVal) {
            std::cout << x.first << ":";
            x.second->print();
        }
        std::cout << ")";
    }

};

#endif