#ifndef NODEDECLARATIONFUNCTION_H
#define NODEDECLARATIONFUNCTION_H

#include <string>
#include <vector>
#include "node.h"

class NodeDeclarationFunction: public NodeDeclaration {
public:
    std::string name;
    std::vector <Node*> parameters;
    Node* body;

    NodeDeclarationFunction() {
        this->nodeType = "DeclarationFunction";
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
};

#endif