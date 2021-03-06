#include <SyntaxAnalyzer/Parser/Parser.h>

Node* SetParser(Parser *parser, int *tokenNumber);
Node* LetParser(Parser *parser, int *tokenNumber);
Node* DefineParser(Parser *parser, int *tokenNumber);
Node* ForParser(Parser *parser, int *tokenNumber);
Node* ForListParser(Parser *parser, int *tokenNumber);
Node* ArithmeticParser(Parser *parser, int *tokenNumber);
Node* ComparisonParser(Parser *parser, int *tokenNumber);
Node* PredicatesParser(Parser *parser, int *tokenNumber);
Node* LogicalOpParser(Parser *parser, int *tokenNumber);
Node* ReadLineParser(Parser *parser, int *tokenNumber);
Node* CondParser(Parser *parser, int *tokenNumber);
Node* ListOpParser(Parser *parser, int *tokenNumber);
Node* ArrayOpParser(Parser *parser, int *tokenNumber);
Node* RecordParser(Parser *parser, int *tokenNumber);
Node* FunctionParser(Parser *parser, int *tokenNumber);
Node* ReturnParser(Parser *parser, int *tokenNumber);


Node* ListParser(Parser *parser, int *tokenNumber){
    (*tokenNumber) ++;
    Token currentToken = parser->GetToken(*tokenNumber);
    if (currentToken.code == tokenSet) {
        return SetParser(parser, tokenNumber);
    } 
    else if (currentToken.code == tokenLet) {
        return LetParser(parser, tokenNumber);
    } 
    else if (currentToken.code == tokenDefine) {
        return DefineParser(parser, tokenNumber);
    } 
    else if (currentToken.code == tokenFor) {
        return ForParser(parser, tokenNumber);
    } 
    else if (currentToken.code == tokenForList) {
        return ForListParser(parser, tokenNumber);
    } 
    else if (currentToken.code == tokenCond) {
        return CondParser(parser, tokenNumber);
    }
    else if (currentToken.code == tokenPlus || currentToken.code == tokenMinus || currentToken.code == tokenMul || currentToken.code == tokenDiv) {
        return ArithmeticParser(parser, tokenNumber);
    } 
    else if (currentToken.code == tokenEqual || currentToken.code == tokenNonEqual || currentToken.code == tokenLess ||
                    currentToken.code == tokenLessEq || currentToken.code == tokenGreater || currentToken.code == tokenGreaterEq) {
        return ComparisonParser(parser, tokenNumber);
    } 
    else if (currentToken.code == tokenIsBool || currentToken.code == tokenIsInt || currentToken.code == tokenIsReal || 
                    currentToken.code == tokenIsList || currentToken.code == tokenIsString) {
        return PredicatesParser(parser, tokenNumber);
    } 
    else if (currentToken.code == tokenOr || currentToken.code == tokenAnd || 
                    currentToken.code == tokenXor || currentToken.code == tokenNot) {
        return LogicalOpParser(parser, tokenNumber);
    } 
    else if (currentToken.code == tokenReadLine) {
        return ReadLineParser(parser, tokenNumber);
    } 
    else if (currentToken.code == tokenList || currentToken.code == tokenHead || currentToken.code == tokenTail ||
                    currentToken.code == tokenRest || currentToken.code == tokenEmpty || currentToken.code == tokenAppend) {
        return ListOpParser(parser, tokenNumber);
    }
    else if (currentToken.code == tokenArray || currentToken.code == tokenArrayAdd || 
                currentToken.code == tokenArrayGet || currentToken.code == tokenArrayRem || currentToken.code == tokenArraySet) {
        return ArrayOpParser(parser, tokenNumber);
    }
    else if (currentToken.code == tokenRecord || currentToken.code == tokenRecordField || 
                currentToken.code == tokenRecordKeywords || currentToken.code == tokenRecordValues) {
        return RecordParser(parser, tokenNumber);
    }
    else if (currentToken.code == tokenString) {
        return FunctionParser(parser, tokenNumber);
    } 
    else if (currentToken.code == tokenReturn) {
        return  ReturnParser(parser, tokenNumber);
    }
    else {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position, "Undefined symbols");
    }
}