#ifndef NODEDECLARATIONVARIABLE_H
#define NODEDECLARATIONVARIABLE_H

#include <string>
#include <vector>
#include "node.h"

class NodeDeclarationVariable: public NodeDeclaration {
public:
    Node* expression;

    NodeDeclarationVariable() {
        this->nodeType = "DeclarationVariable";
        this->type = "Any";
    }

    Node* getExpression() {
        return expression;
    }

    void setExpression(Node* expression) {
        this->expression = expression;
    }
};

#endif //COMPILER_NODEDECLARATION_H