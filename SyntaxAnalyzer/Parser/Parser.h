#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

#include <LexicalAnalyzer/lexical_analyzer.h>
#include <SyntaxAnalyzer/AST/node.h>
#include <SyntaxAnalyzer/AST/nodeBody.h>
#include <SyntaxAnalyzer/AST/nodeDeclaration.h>
#include <SyntaxAnalyzer/AST/nodeDeclarationVariable.h>
#include <SyntaxAnalyzer/AST/nodeDeclarationFunction.h>
#include <SyntaxAnalyzer/AST/nodeInvocation.h>
#include <SyntaxAnalyzer/AST/nodeLiteral.h>
#include <SyntaxAnalyzer/AST/nodeParameter.h>
#include <SyntaxAnalyzer/AST/nodeBody.h>
#include <SyntaxAnalyzer/AST/literalBoolean.h>
#include <SyntaxAnalyzer/AST/literalInteger.h>
#include <SyntaxAnalyzer/AST/literalReal.h>
#include <SyntaxAnalyzer/AST/literalString.h>
#include <SyntaxAnalyzer/AST/literalList.h>
#include <SyntaxAnalyzer/AST/literalArray.h>
#include <SyntaxAnalyzer/AST/literalRecord.h>

class Parser {
    std::vector<Token> tokenList;
public:
    Node* ProgramParse(std::vector<Token> List);
    Token GetToken(int tokenNumber);
    void ErrorMessage(int line, int position, std::string message);
};

#endif