#include <SyntaxAnalyzer/Parser/Parser.h>

Node* ElementParser(Parser *parser, int *tokenNumber);

Node* ArithmeticParser(Parser *parser, int *tokenNumber) {
    NodeInvocation *arithmetic_node = new NodeInvocation();
    Token curToken = parser->GetToken(*tokenNumber);
    (*tokenNumber) ++;

    if (curToken.code == tokenPlus) {
        arithmetic_node->setName("plus");
    }
    if (curToken.code == tokenMinus) {
        arithmetic_node->setName("minus");
    }
    if (curToken.code == tokenDiv) {
        arithmetic_node->setName("div");
    }
    if (curToken.code == tokenMul) {
        arithmetic_node->setName("mul");
    }

    arithmetic_node->addParameter(ElementParser(parser, tokenNumber));
    arithmetic_node->addParameter(ElementParser(parser, tokenNumber));

    if (parser->GetToken(*tokenNumber).code != tokenCloseParenthesis) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position, "Expected )");
    }

    (*tokenNumber) ++;
    return arithmetic_node;
}