#include <SyntaxAnalyzer/Parser/Parser.h>

Node* ElementParser(Parser *parser, int *tokenNumber);
Node* ParameterParser(Parser *parser, int *tokenNumber);
Node* BodyParser(Parser *parser, int *tokenNumber);

Node* DefineParser(Parser *parser, int *tokenNumber) {
    NodeDeclarationFunction* nodeDefine = new NodeDeclarationFunction();
    (*tokenNumber) ++;
    
    if (parser->GetToken(*tokenNumber).code != tokenString) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position, "Expected function name");
    }
    nodeDefine->setName(parser->GetToken(*tokenNumber).value.stringVal);

    (*tokenNumber) ++;
    if (parser->GetToken(*tokenNumber).code != tokenOpenParenthesis) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position, "Expected (");
    }

    (*tokenNumber) ++;
    while(parser->GetToken(*tokenNumber).code != tokenCloseParenthesis) {
        nodeDefine->addParameter(ParameterParser(parser, tokenNumber));
    }

    (*tokenNumber) ++;
    if (parser->GetToken(*tokenNumber).code != tokenCloseParenthesis) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position, "Expected )");
    }

    (*tokenNumber) ++;
    if (parser->GetToken(*tokenNumber).code != tokenRightArrow) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position, "Expected ->");
    }

    (*tokenNumber) ++;
    if (parser->GetToken(*tokenNumber).code != tokenType) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position, "Expected Type");
    }
    nodeDefine->setType(parser->GetToken(*tokenNumber).value.stringVal);

    (*tokenNumber) ++;
    if (parser->GetToken(*tokenNumber).code != tokenOpenCurlyBracket) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position, "Expected {");
    }
    nodeDefine->setBody(BodyParser(parser, tokenNumber));
    return nodeDefine;
}