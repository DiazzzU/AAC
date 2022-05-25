#include <SyntaxAnalyzer/Parser/Parser.h>

Node* ElementParser(Parser *parser, int *tokenNumber);

Node* Parser::ProgramParse(std::vector<Token> List) {
    tokenList = List;
    NodeBody *root = new NodeBody();
    int tokenNumber = 0;
    while (tokenNumber < List.size()) {
        root->addExpression(ElementParser(this, &tokenNumber));
    }
    return root;
}

Token Parser::GetToken(int tokenNumber) {
    if (tokenNumber >= tokenList.size()) {
        ErrorMessage(tokenList.back().location.line, tokenList.back().location.position, "Not enough arguments");
        return tokenList.back();
    }
    return tokenList[tokenNumber];
}

void Parser::ErrorMessage(int line, int position, std::string message) {
    std::cout << "Syntax error at line " << line << ", at position " << position << ". " << message << '\n';
    exit(0);
}