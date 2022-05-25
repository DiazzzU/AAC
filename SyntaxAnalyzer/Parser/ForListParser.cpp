#include <SyntaxAnalyzer/Parser/Parser.h>

Node* ElementParser(Parser *parser, int *tokenNumber);
Node* BodyParser(Parser *parser, int *tokenNumber);

Node* ForListParser(Parser *parser, int *tokenNumber) {
    NodeInvocation* nodeFor = new NodeInvocation();
    nodeFor->setName(parser->GetToken(*tokenNumber).value.stringVal);

    (*tokenNumber) ++;
    if (parser->GetToken(*tokenNumber).code != tokenOpenParenthesis) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position, "Expected (");
    }

    (*tokenNumber) ++;
    if (parser->GetToken(*tokenNumber).code != tokenString) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position, "Expected variable");
    }
    nodeFor->addParameter(ElementParser(parser, tokenNumber));
    nodeFor->addParameter(ElementParser(parser, tokenNumber));

    if (parser->GetToken(*tokenNumber).code != tokenCloseParenthesis) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position, "Expected )");
    }

    (*tokenNumber) ++;
    nodeFor->addParameter(ElementParser(parser, tokenNumber));

    if (parser->GetToken(*tokenNumber).code != tokenCloseParenthesis) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position, "Expected )");
    }
    
    (*tokenNumber) ++;    
    return nodeFor;
}