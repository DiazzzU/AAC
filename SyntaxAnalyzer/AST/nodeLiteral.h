#ifndef NODELITERAL_H
#define NODELITERAL_H

#include <string>
#include <vector>
#include "node.h"

class NodeLiteral: public Node {
public:
    std::string type;

    NodeLiteral() {
        this->nodeType = "literal";
    }
};

#endif