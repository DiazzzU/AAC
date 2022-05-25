#include <SyntaxAnalyzer/Parser/Parser.h>

Node* ElementParser(Parser *parser, int *tokenNumber);

Node* LiteralArrayParser(Parser *parser, int *tokenNumber) {
    Token literalType = parser->GetToken(*tokenNumber);
    ArrayLiteral *literal_node = new ArrayLiteral();
    while(parser->GetToken(*tokenNumber).code != tokenCloseSquareBracket) {
        literal_node->addArrayVal(ElementParser(parser, tokenNumber));
    }
    (*tokenNumber) ++;
    return literal_node;
}