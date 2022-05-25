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
    std::string type;

    NodeInvocation() {
        this->nodeType = "Invocation";
    }

    std::string getName() {
        return name;
    }
    std::vector <Node*> getParameters() {
        return parameters;
    }
    Node* getDeclaration() {
        return declaration;
    }
    std::string getType() {
        return type;
    }

    void setDeclaration(Node* declaration) {
        this->declaration = declaration;
    }
    void setName(std::string name) {
        this->name = name;
    }
    void addParameter(Node* node) {
        parameters.push_back(node);
    }
    void setType(std::string type) {
        this->type = type;
    }


    Node* codegen(Memory* memory) {
        if (name == "plus") {
            Node* parameters[0].codegen();
        }
    }
};

#endif //COMPILER_NODEINVOCATION_H