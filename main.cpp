#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

#include <LexicalAnalyzer/lexical_analyzer.h>
#include <SyntaxAnalyzer/Parser/Parser.h>

using namespace std;

int main() {
    ifstream sourcecode ("../sourcecode.txt");
    vector<Token> tokenList = Analyze(sourcecode);
    for (auto x : tokenList) {
        cout << TokenEnumNames[x.code] << ' ' << x.value.stringVal << endl;
    }
    Parser* parser = new Parser();
    Node* root = parser->ProgramParse(tokenList);
    vector <Node*> expressions = root->getExpressions();
    cout << expressions.size() << ' ';
}