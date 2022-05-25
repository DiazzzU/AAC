#include <SyntaxAnalyzer/Parser/Parser.h>

Node* ElementParser(Parser *parser, int *tokenNumber);

Node* ReadLineParser(Parser *parser, int *tokenNumber) {
    NodeInvocation* nodeReadLine = new NodeInvocation();
    nodeReadLine->setName(parser->GetToken(*tokenNumber).value.stringVal);
    (*tokenNumber) ++;
    if (parser->GetToken(*tokenNumber).code != tokenType) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position, "Exptected Type");
    }
    nodeReadLine->setType(parser->GetToken(*tokenNumber).value.stringVal);

    if (parser->GetToken(*tokenNumber).code != tokenCloseParenthesis) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position, "Expected )");
    }

    (*tokenNumber) ++;
    return nodeReadLine;
}