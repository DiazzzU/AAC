#ifndef NODEDECLARATION_H
#define NODEDECLARATION_H

#include <string>
#include <vector>
#include "node.h"

class NodeDeclaration: public Node {
public:
    std::string name;
    std::string type;

    NodeDeclaration() {
        this->nodeType = "Declaration";
    }

    std::string getName() {
        return name;
    }
    std::string getType() {
        return type;
    }

    void setName(std::string name) {
        this->name = name;
    }
    void setType(std::string type) {
        this->type = type;
    }
};

#endif //COMPILER_NODEDECLARATION_H