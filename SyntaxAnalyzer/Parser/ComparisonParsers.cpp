#include <SyntaxAnalyzer/Parser/Parser.h>

Node* ElementParser(Parser *parser, int *tokenNumber);

Node* ComparisonParser(Parser *parser, int *tokenNumber) {
    NodeInvocation* nodeComparison = new NodeInvocation();
    nodeComparison->setName(parser->GetToken(*tokenNumber).value.stringVal);
    (*tokenNumber) ++;
    nodeComparison->addParameter(ElementParser(parser, tokenNumber));
    nodeComparison->addParameter(ElementParser(parser, tokenNumber));

    if (parser->GetToken(*tokenNumber).code != tokenCloseParenthesis) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position, "Expected )");
    }

    (*tokenNumber) ++;
    return nodeComparison;
}