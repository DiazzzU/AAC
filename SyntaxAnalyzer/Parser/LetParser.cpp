#include <SyntaxAnalyzer/Parser/Parser.h>

Node* ElementParser(Parser *parser, int *tokenNumber);

Node* LetParser(Parser *parser, int *tokenNumber) {
    NodeDeclarationVariable* nodeLet = new NodeDeclarationVariable();
    (*tokenNumber) ++;

    if (parser->GetToken(*tokenNumber).code != tokenString) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position, "Expected variable name");
    }
    nodeLet->setName(parser->GetToken(*tokenNumber).value.stringVal);
    (*tokenNumber) ++;

    if (parser->GetToken(*tokenNumber).code == tokenSemicolon) {
        (*tokenNumber) ++;
        if (parser->GetToken(*tokenNumber).code != tokenType) {
            parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position, "Expected type, but found anything else");
        }
        nodeLet->setType(parser->GetToken(*tokenNumber).value.stringVal);
        (*tokenNumber) ++;
    }
    nodeLet->setExpression(ElementParser(parser, tokenNumber));

    if (parser->GetToken(*tokenNumber).code != tokenCloseParenthesis) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position, "Expected )");
    }

    (*tokenNumber) ++;
    return nodeLet;
}