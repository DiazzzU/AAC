#include <SyntaxAnalyzer/Parser/Parser.h>

Node* ParameterParser(Parser *parser, int *tokenNumber){
    NodeParameter* nodeParameter = new NodeParameter();
    if (parser->GetToken(*tokenNumber).code != tokenString) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position, "Expected variable");
    }
    nodeParameter->setName(parser->GetToken(*tokenNumber).value.stringVal);
    (*tokenNumber) ++;
    if (parser->GetToken(*tokenNumber).code != tokenType) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position, "Expected type");
    }
    nodeParameter->setType(parser->GetToken(*tokenNumber).value.stringVal);
    (*tokenNumber) ++;
    return nodeParameter;
}