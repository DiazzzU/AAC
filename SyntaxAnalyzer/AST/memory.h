#ifndef MEMORY_H
#define MEMORY_H

#include <string>
#include <vector>
#include <map>

#include <SyntaxAnalyzer/AST/node.h>
#include <SyntaxAnalyzer/Semantics/Literal.h>

class Node;

class Memory {
public:
    std::map < std::string, Literal*> variables;
    std::map < std::string, Node*> functions;
};

#endif