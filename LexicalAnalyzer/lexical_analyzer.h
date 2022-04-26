#ifndef LEXICAL_ANALYZER_H
#define LEXICAL_ANALYZER_H

#include <string>
#include <fstream>
#include <cstring>
#include <vector>

#include <Token/tokens.h>

Token getNextToken(std::ifstream *file, int *curLine, int *curPos);
std::vector<Token> Analyze(std::ifstream &sourcecode);

#endif