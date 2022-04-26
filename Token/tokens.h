#include <string>

#ifndef TOKENS_H
#define TOKENS_H

enum Code {
    tokenInt, // 0
    tokenReal, // 1
    tokenBoolean, // 2
    tokenString, // 3
    tokenOpenParenthesis, // 6
    tokenCloseParenthesis, // 7
    tokenOpenBracket, // 8
    tokenCloseBracket, // 9
    tokenQuote, // 10
    tokenSetq, // 11
    tokenFunc, // 12
    tokenCond, // 13
    tokenFor, // 14
    tokenForList, // 15
    tokenEqual, // 16
    tokenNonEqual, // 17
    tokenLess, // 18
    tokenLessEq, // 19
    tokenGreater, // 20
    tokenGreaterEq, // 21
    tokenIsInt, // 22
    tokenIsReal, // 23
    tokenIsBool, // 24
    tokenIsString, // 25
    tokenIsList, // 26
    tokenAnd, // 27
    tokenOr, // 28
    tokenXor, // 29
    tokenNot, // 30
    tokenTrue, // 31
    tokenFalse, // 32
    tokenPlus, // 33
    tokenMinus, // 34
    tokenMul, // 35
    tokenDiv, // 36
    tokenHead, // 37
    tokenTail, // 38
    tokenCons, // 39
    tokenRest, // 40
    tokenEmpty, // 41
    tokenList, // 42
    tokenRoot, // 43
    tokenEndFile,
};

struct Location {
    int line;
    int position;
};

struct Value {
    int intVal;
    double realVal;
    bool boolVal;
    std::string stringVal;
};

struct Token {
    unsigned int code;
    Value value;
    Location location;
};

const std::string TokenEnumNames [] = {
    [tokenInt] = "tokenInt",
    [tokenReal] = "tokenReal",
    [tokenBoolean] = "tokenBoolean",
    [tokenString] = "tokenString",
    [tokenOpenParenthesis] = "tokenOpenParenthesis",
    [tokenCloseParenthesis] = "tokenCloseParenthesis",
    [tokenOpenBracket] = "tokenOpenBracket",
    [tokenCloseBracket] = "tokenCloseBracket",
    [tokenQuote] = "tokenQuote",
    [tokenSetq] = "tokenSetq",
    [tokenFunc] = "tokenFunc",
    [tokenCond] = "tokenCond",
    [tokenFor] = "tokenCond",
    [tokenForList] = "tokenForList",
    [tokenEqual] = "tokenEqual",
    [tokenNonEqual] = "tokenNonEqual",
    [tokenLess] = "tokenLess",
    [tokenLessEq] = "tokenLessEq",
    [tokenGreater] = "tokenGreater",
    [tokenGreaterEq] = "tokenGreaterEq",
    [tokenIsInt] = "tokenIsInt",
    [tokenIsReal] = "tokenIsReal",
    [tokenIsBool] = "tokenIsBool",
    [tokenIsString] = "tokenIsString",
    [tokenIsList] = "tokenIsList",
    [tokenAnd] = "tokenAnd",
    [tokenOr] = "tokenOr",
    [tokenXor] = "tokenXor",
    [tokenNot] = "tokenNot",
    [tokenTrue] = "tokenTrue",
    [tokenFalse] = "tokenFalse",
    [tokenPlus] = "tokenPlus",
    [tokenMinus] = "tokenMinus",
    [tokenMul] = "tokenMul",
    [tokenDiv] = "tokenDiv",
    [tokenHead] = "tokenHead",
    [tokenTail] = "tokenTail",
    [tokenCons] = "tokenCons",
    [tokenRest] = "tokenRest",
    [tokenEmpty] = "tokenEmpty",
    [tokenList] = "tokenList",
    [tokenRoot] = "tokenRoot",
    [tokenEndFile] = "tokenEndFile",
};

#endif