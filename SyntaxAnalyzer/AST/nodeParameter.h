#ifndef NODEPARAMETER_H
#define NODEPARAMETER_H

#include <string>
#include <vector>
#include "node.h"

class NodeParameter: public Node {
public:
    std::string name;
    Node* declaration;

    NodeParameter() {
        this->nodeType = "Parameter";
    }

    virtual std::string getName() {
        return name;
    }
    virtual Node* getDeclaration() {
        return declaration;
    }

    virtual void setName(std::string name) {
        this->name = name;
    }
    virtual void setDeclaration(Node* x) {
        declaration = x;
    }
};

#endif 