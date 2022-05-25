#include <SyntaxAnalyzer/Parser/Parser.h>

Node* ElementParser(Parser *parser, int *tokenNumber);

Node* SetParser(Parser *parser, int *tokenNumber) {
    NodeInvocation* nodeSet = new NodeInvocation();
    (*tokenNumber) ++;

    if (parser->GetToken(*tokenNumber).code != tokenString) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position, "Expected Variable");
    }

    nodeSet->addParameter(ElementParser(parser, tokenNumber));
    nodeSet->addParameter(ElementParser(parser, tokenNumber));
    nodeSet->setName("set");

    if (parser->GetToken(*tokenNumber).code != tokenCloseParenthesis) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position, "Expected )");
    }

    (*tokenNumber) ++;
    return nodeSet;
}