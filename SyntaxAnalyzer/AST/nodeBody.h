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
};

#endif 