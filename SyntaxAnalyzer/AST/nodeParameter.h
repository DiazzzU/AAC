#ifndef NODEPARAMETER_H
#define NODEPARAMETER_H

#include <string>
#include <vector>
#include "node.h"

class NodeParameter: public Node {
public:
    std::string name;
    std::string type;

    NodeParameter() {
        this->nodeType = "Parameter";
    }

    virtual std::string getName() {
        return name;
    }
    virtual std::string getType() {
        return type;
    }

    virtual void setName(std::string name) {
        this->name = name;
    }
    virtual void setType(std::string x) {
        type = x;
    }
};

#endif 