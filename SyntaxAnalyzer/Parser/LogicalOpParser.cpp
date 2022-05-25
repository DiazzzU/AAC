#include <SyntaxAnalyzer/Parser/Parser.h>

Node* ElementParser(Parser *parser, int *tokenNumber);

Node* LogicalOpParser(Parser *parser, int *tokenNumber){
    NodeInvocation* nodeLogicalOp = new NodeInvocation();
    nodeLogicalOp->setName(parser->GetToken(*tokenNumber).value.stringVal);
    if (parser->GetToken(*tokenNumber).code == tokenNot) {
        (*tokenNumber) ++;
        nodeLogicalOp->addParameter(ElementParser(parser, tokenNumber));
    } else {
        (*tokenNumber) ++;
        nodeLogicalOp->addParameter(ElementParser(parser, tokenNumber));
        nodeLogicalOp->addParameter(ElementParser(parser, tokenNumber));
    }

    if (parser->GetToken(*tokenNumber).code != tokenCloseParenthesis) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position, "Expected )");
    }

    (*tokenNumber) ++;
    return nodeLogicalOp;
}