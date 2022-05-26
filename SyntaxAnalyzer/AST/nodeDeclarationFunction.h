#ifndef NODEDECLARATIONFUNCTION_H
#define NODEDECLARATIONFUNCTION_H

#include <string>
#include <vector>
#include "node.h"

class NodeDeclarationFunction: public NodeDeclaration {
public:
    std::vector <Node*> parameters;
    Node* body;

    NodeDeclarationFunction() {
        this->nodeType = "DeclarationFunction";
        this->type = "Any";
    }

    std::vector <Node*> getParameters() {
        return parameters;
    }
    Node* getBody() {
        return body;
    }

    void addParameter(Node* node) {
        parameters.push_back(node);
    }
    void setBody(Node* body) {
        this->body = body;
    }

    Literal* codegen(Memory* memory) {
        if (memory->functions.count(name)) {
            std::cout << "Function with name " << name << "already exist\n";
            exit(0);
        }
        memory->functions[name] = this;
        return new Literal();
    }
};

#endif