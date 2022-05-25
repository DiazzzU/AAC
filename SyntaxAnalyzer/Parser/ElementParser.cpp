#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

#include <Token/tokens.h>
#include <SyntaxAnalyzer/Parser/Parser.h>

Node* LiteralParser(Parser *parser, int *tokenNumber);
Node* AtomParser(Parser *parser, int *tokenNumber);
Node* ListParser(Parser *parser, int *tokenNumber);
Node* QuoteParser(Parser *parser, int *tokenNumber);
Node* LiteralListParser(Parser *parser, int *tokenNumber);
Node* LiteralArrayParser(Parser *parser, int *tokenNumber);

Node* ElementParser(Parser *parser, int *tokenNumber) {
    Token elementType = parser->GetToken(*tokenNumber);
    if (elementType.code == tokenOpenParenthesis) {
        return ListParser(parser, tokenNumber);
    } else if (elementType.code == tokenString) {
        return AtomParser(parser, tokenNumber);
    } else if (elementType.code == tokenBoolean || elementType.code == tokenInt || elementType.code == tokenReal || elementType.code == tokenDoubleQuote) {
        return LiteralParser(parser, tokenNumber);
    } else if (elementType.code == tokenQuote) {
        (*tokenNumber) ++;
        if (parser->GetToken(*tokenNumber).code == tokenOpenParenthesis) {
            (*tokenNumber) ++;
            return LiteralListParser(parser, tokenNumber);
        }
        if (parser->GetToken(*tokenNumber).code == tokenOpenSquareBracket) {
            (*tokenNumber) ++;
            return LiteralArrayParser(parser, tokenNumber);
        }
        parser->ErrorMessage(elementType.location.line, elementType.location.position, "Expected ( or [");
    } else {
        parser->ErrorMessage(elementType.location.line, elementType.location.position, "Undefined function or variable");
    }
}