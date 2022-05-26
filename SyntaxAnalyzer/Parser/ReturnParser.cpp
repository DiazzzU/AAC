#include <SyntaxAnalyzer/Parser/Parser.h>

Node* ElementParser(Parser *parser, int *tokenNumber);

Node* ReturnParser(Parser *parser, int *tokenNumber) {
    NodeInvocation* nodeReturn = new NodeInvocation();
    (*tokenNumber) ++;

    nodeReturn->setName("return");

    nodeReturn->addParameter(ElementParser(parser, tokenNumber));

    if (parser->GetToken(*tokenNumber).code != tokenCloseParenthesis) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position, "Expected )");
    }

    (*tokenNumber) ++;
    return nodeReturn;
}