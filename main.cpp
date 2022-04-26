#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

#include <LexicalAnalyzer/lexical_analyzer.h>

using namespace std;

int main() {
    ifstream sourcecode ("sourcecode.txt");

    vector<Token> tokenList = Analyze(sourcecode);
}