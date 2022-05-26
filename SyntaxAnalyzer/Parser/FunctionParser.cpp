#include <SyntaxAnalyzer/Parser/Parser.h>

Node* ElementParser(Parser *parser, int *tokenNumber);

Node* FunctionParser(Parser *parser, int *tokenNumber) {

    NodeInvocation* node = new NodeInvocation();
    node->setName(parser->GetToken(*tokenNumber).value.stringVal);
    node->setInvocType("Function");
    (*tokenNumber) ++;

    while(parser->GetToken(*tokenNumber).code != tokenCloseParenthesis) {
        node->addParameter(ElementParser(parser, tokenNumber));
    }
    (*tokenNumber) ++;
    return node;
}