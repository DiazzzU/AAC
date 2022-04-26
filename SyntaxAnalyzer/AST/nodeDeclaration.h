#ifndef NODEDECLARATION_H
#define NODEDECLARATION_H

#include <string>
#include <vector>
#include "node.h"

class NodeDeclaration: public Node {
public:
    std::string type;
    std::string name;
    std::vector <Node*> parameters;
    Node* expression;

    NodeDeclaration() {
        this->nodeType = "Declaration";
    }

    virtual std::string getType() {
        return type;
    }
    virtual std::string getName() {
        return name;
    }
    virtual std::vector <Node*> getParameters() {
        return parameters;
    }
    virtual Node* getExpression() {
        return expression;
    }

    virtual void setType(std::string x) {
        this->type = x;
    }
    virtual void setExpression(Node* expression) {
        this->expression = expression;
    }
    virtual void setName(std::string name) {
        this->name = name;
    }
    virtual void addParameter(Node* node) {
        parameters.push_back(node);
    }

};

#endif //COMPILER_NODEDECLARATION_H