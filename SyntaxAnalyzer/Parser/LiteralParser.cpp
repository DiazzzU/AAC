#include <SyntaxAnalyzer/Parser/Parser.h>

Node* LiteralParser(Parser *parser, int *tokenNumber) {
    Token literalType = parser->GetToken(*tokenNumber);
    if (literalType.code == tokenInt) {
        IntegerLiteral *literal_node = new IntegerLiteral();
        literal_node->setType("Integer");
        literal_node->setIntVal(literalType.value.intVal);
        (*tokenNumber) ++;
        return literal_node;
    }
    if (literalType.code == tokenReal) {
        RealLiteral *literal_node = new RealLiteral();
        literal_node->setType("Real");
        literal_node->setRealVal(literalType.value.realVal);
        (*tokenNumber) ++;
        return literal_node;
    }
    if (literalType.code == tokenBoolean) {
        BooleanLiteral *literal_node = new BooleanLiteral();
        literal_node->setType("Boolean");
        literal_node->setBooleanVal(literalType.value.boolVal);
        (*tokenNumber) ++;
        return literal_node;
    }
    if (literalType.code == tokenDoubleQuote) {
        StringLiteral *literal_node = new StringLiteral();
        literal_node->setType("String");
        std::string value = "";
        int previousPos = parser->GetToken(*tokenNumber).location.position;
        int previousSize = parser->GetToken(*tokenNumber).value.stringVal.size();
        (*tokenNumber) ++;
        while(parser->GetToken(*tokenNumber).code != tokenDoubleQuote) {
            int num = parser->GetToken(*tokenNumber).location.position - previousPos - previousSize;
            for (int i = 1; i <= num; i++) {
                value += " ";
            } 
            value += parser->GetToken(*tokenNumber).value.stringVal;
            previousPos = parser->GetToken(*tokenNumber).location.position;
            previousSize = parser->GetToken(*tokenNumber).value.stringVal.size();
            (*tokenNumber) ++;
        }
        literal_node->setStringVal(value);
        (*tokenNumber) ++;
        return literal_node;
    }

    return NULL;
}