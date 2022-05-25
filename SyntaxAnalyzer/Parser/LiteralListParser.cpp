#include <SyntaxAnalyzer/Parser/Parser.h>

Node* ElementParser(Parser *parser, int *tokenNumber);

Node* LiteralListParser(Parser *parser, int *tokenNumber) {
    Token literalType = parser->GetToken(*tokenNumber);
    ListLiteral *literal_node = new ListLiteral();
    while(parser->GetToken(*tokenNumber).code != tokenCloseParenthesis) {
        literal_node->addListVal(ElementParser(parser, tokenNumber));
    }
    (*tokenNumber) ++;
    return literal_node;
}