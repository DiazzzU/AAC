#ifndef LITERAL_RECORD_H
#define LITERAL_RECORD_H

#include <string>
#include <vector>
#include <map>
#include "node.h"
#include <SyntaxAnalyzer/AST/memory.h>
#include <SyntaxAnalyzer/Semantics/Record.h>

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

    Literal* codegen(Memory* memory) {
        Record* node = new Record();
        for (auto x : recordVal) {
            node->addRecordVal(x.first, x.second->codegen(memory));
        }
        return node;
    }
};

#endif