#include <SyntaxAnalyzer/Parser/Parser.h>

Node* ElementParser(Parser *parser, int *tokenNumber);

Node* ArrayOpParser(Parser *parser, int *tokenNumber) {
    Token currentToken = parser->GetToken(*tokenNumber);
    if (currentToken.code == tokenArray) {
        ArrayLiteral* nodeArray = new ArrayLiteral();
        (*tokenNumber) ++;
        while (parser->GetToken(*tokenNumber).code != tokenCloseParenthesis) {
            nodeArray->addArrayVal(ElementParser(parser, tokenNumber));
        }
        (*tokenNumber) ++;
        return nodeArray;
    }
    
    NodeInvocation* nodeArray = new NodeInvocation();
    nodeArray->setName(parser->GetToken(*tokenNumber).value.stringVal);

    (*tokenNumber) ++;
    nodeArray->addParameter(ElementParser(parser, tokenNumber));
    nodeArray->addParameter(ElementParser(parser, tokenNumber));

    if (currentToken.code == tokenArrayAdd || currentToken.code == tokenArraySet) {
        nodeArray->addParameter(ElementParser(parser, tokenNumber));
    }
    return nodeArray;
}