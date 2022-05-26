#ifndef NODEBODY_H
#define NODEBODY_H

#include <string>
#include <vector>
#include "node.h"

class NodeBody: public Node {
public:
    std::vector<Node*> expressions;

    NodeBody() {
        this->nodeType = "Body";
    }

    void addExpression(Node* expression) {
        expressions.push_back(expression);
    }

    std::vector<Node*> getExpressions() {
        return expressions;
    }

    Literal* codegen(Memory* memory) {
        for (auto exp : expressions) {
            Literal* element = exp->codegen(memory);
            if (exp->getName() == "return") {
                return element;
            }
            element->print();
            if (element->getType() != "Literal") {
                std::cout << '\n';
            }
        }
    }
};

#endif 