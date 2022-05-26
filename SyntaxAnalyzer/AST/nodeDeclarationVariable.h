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

    void setExpression(Node* x) {
        this->expression = x;
    }

    Literal* codegen(Memory* memory) {
        Literal* element = expression->codegen(memory);
        if (type != "Any" && element->getType() != type) {
            std::cout << "TypeError";
            exit(0);
        }
        if (memory->variables.count(name)) {
            std::cout << "Variable with name " << name << "already exist\n";
            exit(0);
        }
        memory->variables[name] = element;
        return new Literal();
    }
};

#endif //COMPILER_NODEDECLARATION_H