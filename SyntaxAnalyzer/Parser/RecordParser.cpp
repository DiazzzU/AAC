#include <SyntaxAnalyzer/Parser/Parser.h>

Node* ElementParser(Parser *parser, int *tokenNumber);

Node* RecordParser(Parser *parser, int *tokenNumber) {
    Token currentToken = parser->GetToken(*tokenNumber);
    (*tokenNumber) ++;
    if (currentToken.code == tokenRecord) {
        RecordLiteral* nodeRecord = new RecordLiteral();
        while (parser->GetToken(*tokenNumber).code != tokenCloseParenthesis) {
            if (parser->GetToken(*tokenNumber).code != tokenOpenParenthesis) {
                parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position, "Expected (");
            }
            (*tokenNumber) ++;

            if (parser->GetToken(*tokenNumber).code != tokenString) {
                parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position, "Expected Keyword");
            }
            std::string keyword = parser->GetToken(*tokenNumber).value.stringVal;
            (*tokenNumber) ++;
            nodeRecord->addRecordVal(keyword, ElementParser(parser, tokenNumber));
            
            if (parser->GetToken(*tokenNumber).code != tokenCloseParenthesis) {
                parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position, "Expected )");
            }
            (*tokenNumber) ++;
        }
        (*tokenNumber) ++;
        return nodeRecord;
    }
    NodeInvocation* nodeRecordOp = new NodeInvocation();
    nodeRecordOp->setName(currentToken.value.stringVal);
    nodeRecordOp->addParameter(ElementParser(parser, tokenNumber));

    if (currentToken.code == tokenRecordField) {
        nodeRecordOp->addParameter(ElementParser(parser, tokenNumber));
    }

    if (parser->GetToken(*tokenNumber).code != tokenCloseParenthesis) {
        parser->ErrorMessage(parser->GetToken(*tokenNumber).location.line, parser->GetToken(*tokenNumber).location.position, "Expected )");
    }
    (*tokenNumber) ++;
    return nodeRecordOp;
}