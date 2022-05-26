#ifndef RECORD_H
#define RECORD_H

#include <string>
#include <vector>
#include <map>
#include <SyntaxAnalyzer/Semantics/Literal.h>

class Record: public Literal {
public:
    std::map < std::string, Literal*> recordVal;

    Record() {
        this->type = "Record";
    }

    virtual std::map < std::string, Literal*> getRecordVal() {
        return recordVal;
    }

    virtual void addRecordVal(std::string key, Literal* val) {
        this->recordVal[key] = val;
    }

    void print() {
        std::cout << "(record ";
        for (auto x : recordVal) {
            std::cout << x.first << ":";
            x.second->print();
            std::cout << ' ';
        }
        std::cout << ")";
    }

};

#endif