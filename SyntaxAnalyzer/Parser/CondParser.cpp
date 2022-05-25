#include <SyntaxAnalyzer/Parser/Parser.h>

Node* ElementParser(Parser *parser, int *tokenNumber);

Node* CondParser(Parser *parser, int *tokenNumber){
    NodeInvocation* nodeCond = new NodeInvocation();
    nodeCond->setName(parser->GetToken(*tokenNumber).value.stringVal);
    (*tokenNumber) ++;
    bool condition = true;
    while(parser->GetToken(*tokenNumber).code != tokenCloseParenthesis) {

        if (!condition) {
            parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position, "Expected )");
        }

        if (parser->GetToken(*tokenNumber).code != tokenOpenSquareBracket) {
            parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position, "Expected [");
        }
        (*tokenNumber) ++;

        if (parser->GetToken(*tokenNumber).value.stringVal == "else") {
            condition = false;
        }

        nodeCond->addExpression(ElementParser(parser, tokenNumber));
        nodeCond->addExpression(ElementParser(parser, tokenNumber));
        if (parser->GetToken(*tokenNumber).code != tokenCloseSquareBracket) {
            parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position, "Expected ]");
        }
    }
    (*tokenNumber) ++;
    return nodeCond;
}