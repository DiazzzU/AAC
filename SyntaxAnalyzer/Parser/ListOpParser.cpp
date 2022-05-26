#include <SyntaxAnalyzer/Parser/Parser.h>

Node* ElementParser(Parser *parser, int *tokenNumber);
Node* LiteralListParser(Parser *parser, int *tokenNumber);

Node* ListOpParser(Parser *parser, int *tokenNumber) {
    Token currentToken = parser->GetToken(*tokenNumber);
    if (currentToken.code == tokenList) {
        (*tokenNumber) ++;
        return LiteralListParser(parser, tokenNumber);
    }
    NodeInvocation* nodeListOp = new NodeInvocation();
    nodeListOp->setName(currentToken.value.stringVal);
    (*tokenNumber) ++;
    nodeListOp->addParameter(ElementParser(parser, tokenNumber));

    if (currentToken.code == tokenAppend) {
        nodeListOp->addParameter(ElementParser(parser, tokenNumber));
    }

    if (parser->GetToken(*tokenNumber).code != tokenCloseParenthesis) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position, "Expected )");
    }
    (*tokenNumber) ++;

    return nodeListOp;
}