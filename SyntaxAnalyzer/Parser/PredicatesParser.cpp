#include <SyntaxAnalyzer/Parser/Parser.h>

Node* ElementParser(Parser *parser, int *tokenNumber);

Node* PredicatesParser(Parser *parser, int *tokenNumber) {
    NodeInvocation* nodePredicates = new NodeInvocation();
    nodePredicates->setName(parser->GetToken(*tokenNumber).value.stringVal);
    (*tokenNumber) ++;
    nodePredicates->addParameter(ElementParser(parser, tokenNumber));

    if (parser->GetToken(*tokenNumber).code != tokenCloseParenthesis) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position, "Expected )");
    }

    (*tokenNumber) ++;
    return nodePredicates;
}