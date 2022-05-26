#include "lexical_analyzer.h"

Token getNextToken(std::ifstream *file, int *curLine, int *curPos) {
    Token token;
    char c;

    std::string tokenLetters = "";

    while (file->peek() == ' ' || file->peek() == '\n') {
        (*curPos) ++;
        if (file->peek() == '\n') {
            (*curPos) = 1;
            (*curLine)++;
        }
        file->get(c);
    }

    token.location.position = *curPos;
    token.location.line = *curLine;
    if (file->peek() == EOF) {
        token.code = tokenEndFile;
        return token;
    }

    (*curPos) ++;
    tokenLetters += file->get();

    if (tokenLetters != "(" && tokenLetters != ")" && tokenLetters != "[" && 
            tokenLetters != "]" && tokenLetters != "\'" && tokenLetters != "\n" && 
                tokenLetters != "}" && tokenLetters != "{" && tokenLetters != "\"" && 
                    tokenLetters != ":") {

        while (tokenLetters != "->" && file->peek() != ' ' && file->peek() != '(' && 
                    file->peek() != ')' && file->peek() != '[' && file->peek() != ']' && 
                        file->peek() != EOF && file->peek() != '\n' && file->peek() != '}' && 
                            file->peek() != '{' && file->peek() != '\"' && file->peek() != ':') {

            tokenLetters += file->get();
            (*curPos) ++;

        }

    }

    if (tokenLetters == "(") {
        token.code = tokenOpenParenthesis;
    } else if (tokenLetters == ")") {
        token.code = tokenCloseParenthesis;
    } else if (tokenLetters == "[") {
        token.code = tokenOpenSquareBracket;
    } else if (tokenLetters == "]") {
        token.code = tokenCloseSquareBracket;
    } else if (tokenLetters == "{") {
        token.code = tokenOpenCurlyBracket;
    } else if (tokenLetters == "}") {
        token.code = tokenCloseCurlyBracket;
    } else if (tokenLetters == "\'") {
        token.code = tokenQuote;
    } else if (tokenLetters == "\"") {
        token.code = tokenDoubleQuote;
    } else if (tokenLetters == ":") {
        token.code = tokenSemicolon;
    } else if (tokenLetters == "->") {
        token.code = tokenRightArrow;
    } else if (tokenLetters == "set") {
        token.code = tokenSet;
    } else if (tokenLetters == "let") {
        token.code = tokenLet;
    } else if (tokenLetters == "define") {
        token.code = tokenDefine;
    } else if (tokenLetters == "return") {
        token.code = tokenReturn;
    } else if (tokenLetters == "cond") {
        token.code = tokenCond;
    } else if (tokenLetters == "for") {
        token.code = tokenFor;
    } else if (tokenLetters == "for/list") {
        token.code = tokenForList;
    } else if (tokenLetters == "equal") {
        token.code = tokenEqual;
    } else if (tokenLetters == "nonequal") {
        token.code = tokenNonEqual;
    } else if (tokenLetters == "less") {
        token.code = tokenLess;
    } else if (tokenLetters == "lesseq") {
        token.code = tokenLessEq;
    } else if (tokenLetters == "greater") {
        token.code = tokenGreater;
    } else if (tokenLetters == "greatereq") {
        token.code = tokenGreaterEq;
    } else if (tokenLetters == "isint") {
        token.code = tokenIsInt;
    } else if (tokenLetters == "isreal") {
        token.code = tokenIsReal;
    } else if (tokenLetters == "isbool") {
        token.code = tokenIsBool;
    } else if (tokenLetters == "islist") {
        token.code = tokenIsList;
    } else if (tokenLetters == "isstring") {
        token.code = tokenIsString;
    } else if (tokenLetters == "and") {
        token.code = tokenAnd;
    } else if (tokenLetters == "or") {
        token.code = tokenOr;
    } else if (tokenLetters == "xor") {
        token.code = tokenXor;
    } else if (tokenLetters == "not") {
        token.code = tokenNot;
    } else if (tokenLetters == "true") {
        token.code = tokenBoolean;
        token.value.boolVal = true;
    } else if (tokenLetters == "false") {
        token.code = tokenBoolean;
        token.value.boolVal = false;
    } else if (tokenLetters == "else") {
        token.code = tokenBoolean;
        token.value.boolVal = true;
    } else if (tokenLetters == "plus") {
        token.code = tokenPlus;
    } else if (tokenLetters == "minus") {
        token.code = tokenMinus;
    } else if (tokenLetters == "mul") {
        token.code = tokenMul;
    } else if (tokenLetters == "div") {
        token.code = tokenDiv;
    } else if (tokenLetters == "head") {
        token.code = tokenHead;
    } else if (tokenLetters == "tail") {
        token.code = tokenTail;
    } else if (tokenLetters == "cons") {
        token.code = tokenCons;
    } else if (tokenLetters == "rest") {
        token.code = tokenRest;
    } else if (tokenLetters == "empty") {
        token.code = tokenEmpty;
    } else if (tokenLetters == "list") {
        token.code = tokenList;
    } else if (tokenLetters == "String") {
        token.code = tokenType;
        token.value.stringVal = tokenLetters;
    } else if (tokenLetters == "Integer") {
        token.code = tokenType;
        token.value.stringVal = tokenLetters;
    } else if (tokenLetters == "Real") {
        token.code = tokenType;
        token.value.stringVal = tokenLetters;
    } else if (tokenLetters == "List") {
        token.code = tokenType;
        token.value.stringVal = tokenLetters;
    } else if (tokenLetters == "Boolean") {
        token.code = tokenType;
        token.value.stringVal = tokenLetters;
    } else if (tokenLetters == "Array") {
        token.code = tokenType;
        token.value.stringVal = tokenLetters;
    } else if (tokenLetters == "Keyword") {
        token.code = tokenType;
        token.value.stringVal = tokenLetters;
    } else if (tokenLetters == "array") {
        token.code = tokenArray;
    } else if (tokenLetters == "array-rem") {
        token.code = tokenArrayRem;
    } else if (tokenLetters == "array-get") {
        token.code = tokenArrayGet;
    } else if (tokenLetters == "array-add") {
        token.code = tokenArrayAdd;
    } else if (tokenLetters == "array-set") {
        token.code = tokenArraySet;
    } else if (tokenLetters == "record") {
        token.code = tokenRecord;
    } else if (tokenLetters == "record-keywords") {
        token.code = tokenRecordKeywords;
    } else if (tokenLetters == "record-values") {
        token.code = tokenRecordValues;
    } else if (tokenLetters == "record-field") {
         token.code = tokenRecordField;
    } else if (tokenLetters == "read-line") {
        token.code = tokenReadLine;   
    } else if (isdigit(tokenLetters[0]) || tokenLetters[0] == '-') {
        bool minus = false;
        bool real = false;
        bool integer = true;
        if(tokenLetters[0] == '-') {
            minus = true;
        }
        for (int i = minus; i < tokenLetters.size(); i++) {
            if (tokenLetters[i] == '.') {
                real = true;
                continue;
            }
            integer &= isdigit(tokenLetters[i]);
        }
        if (real && integer) {
            token.code = tokenReal;
            token.value.realVal = stod(tokenLetters);
        } else if (integer) {
            token.code = tokenInt;
            token.value.intVal = stoi(tokenLetters);

        } else {
            token.code = tokenString;
            token.value.stringVal = tokenLetters;
        }
    } else {
        token.code = tokenString;
        token.value.stringVal = tokenLetters;
    }
    token.value.stringVal = tokenLetters;
    return token;
}

std::vector<Token> Analyze(std::ifstream &sourcecode) {
    int curLine = 1, curPos = 0;
    int cur = 0;
    char peek = sourcecode.peek();
    std::vector<Token> tokensList;

    if (sourcecode.is_open()) {
        while (peek != EOF) {
            tokensList.push_back(getNextToken(&sourcecode, &curLine, &curPos));
            cur++;
            peek = sourcecode.peek();
        }
    }
    sourcecode.close();

    if (tokensList.back().code == tokenEndFile) {
        tokensList.pop_back();
    }

    return tokensList;
}