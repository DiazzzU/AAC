#include <SyntaxAnalyzer/Parser/Parser.h>

Node* ElementParser(Parser *parser, int *tokenNumber);

Node* BodyParser(Parser *parser, int *tokenNumber) {
    NodeBody* nodeBody = new NodeBody();
    (*tokenNumber) ++;
    while (parser->GetToken(*tokenNumber).code != tokenCloseCurlyBracket) {
        nodeBody->addExpression(ElementParser(parser, tokenNumber));
    }
    (*tokenNumber) ++;
    return nodeBody;
}