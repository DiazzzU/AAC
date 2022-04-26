#ifndef COMPILER_NODEINVOCATION_H
#define COMPILER_NODEINVOCATION_H

#include <string>
#include <vector>
#include "node.h"

class NodeInvocation: public Node {
public:
    std::string name;
    std::vector<Node*> parameters;
    Node* declaration;

    NodeInvocation() {
        this->nodeType = "Invocation";
    }

    virtual std::string getName() {
        return name;
    }
    virtual std::vector <Node*> getParameters() {
        return parameters;
    }
    virtual Node* getDeclaration() {
        return declaration;
    }

    virtual void setDeclaration(Node* declaration) {
        this->declaration = declaration;
    }
    virtual void setName(std::string name) {
        this->name = name;
    }
    virtual void addParameter(Node* node) {
        parameters.push_back(node);
    }
};

#endif //COMPILER_NODEINVOCATION_H