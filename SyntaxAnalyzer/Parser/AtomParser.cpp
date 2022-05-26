#include <SyntaxAnalyzer/Parser/Parser.h>

Node* AtomParser(Parser *parser, int *tokenNumber){
    Token atomType = parser->GetToken(*tokenNumber);
    NodeInvocation *atom_node = new NodeInvocation();
    (*tokenNumber) ++;
    atom_node->setName(atomType.value.stringVal);
    atom_node->setInvocType("Variable");
    return atom_node;
}