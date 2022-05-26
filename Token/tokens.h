#include <string>

#ifndef TOKENS_H
#define TOKENS_H

enum Code {
    tokenInt, 
    tokenReal, 
    tokenBoolean, 
    tokenString, 
    tokenOpenParenthesis, 
    tokenCloseParenthesis, 
    tokenOpenSquareBracket, 
    tokenCloseSquareBracket, 
    tokenOpenCurlyBracket,
    tokenCloseCurlyBracket,
    tokenSet,
    tokenLet, 
    tokenDefine, 
    tokenCond, 
    tokenFor, 
    tokenForList, 
    tokenEqual, 
    tokenNonEqual, 
    tokenLess, 
    tokenLessEq, 
    tokenGreater, 
    tokenGreaterEq, 
    tokenIsInt, 
    tokenIsReal, 
    tokenIsBool, 
    tokenIsString, 
    tokenIsList, 
    tokenAnd, 
    tokenOr, 
    tokenXor, 
    tokenNot, 
    tokenTrue, 
    tokenFalse, 
    tokenPlus, 
    tokenMinus, 
    tokenMul, 
    tokenDiv, 
    tokenHead, 
    tokenTail, 
    tokenCons, 
    tokenRest,
    tokenEmpty, 
    tokenList, 
    tokenAppend, 
    tokenRoot, 
    tokenEndFile,
    tokenQuote,
    tokenType,
    tokenArray,
    tokenArrayRem,
    tokenArrayGet,
    tokenArrayAdd,
    tokenArraySet,
    tokenRecord,
    tokenRecordKeywords,
    tokenRecordValues,
    tokenRecordField,
    tokenReadLine,
    tokenDoubleQuote,
    tokenSemicolon,
    tokenRightArrow,
    tokenReturn
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
    [tokenOpenSquareBracket] = "tokenOpenSquareBracket",
    [tokenCloseSquareBracket] = "tokenCloseSquareBracket",
    [tokenOpenCurlyBracket] = "tokenOpenCurlyBracket",
    [tokenCloseCurlyBracket] = "tokenCloseCurlyBracket",
    [tokenSet] = "tokenSet",
    [tokenLet] = "tokenLet",
    [tokenDefine] = "tokenDefine",
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
    [tokenAppend] = "tokenAppend",
    [tokenRoot] = "tokenRoot",
    [tokenEndFile] = "tokenEndFile",
    [tokenQuote] = "tokenQuote",
    [tokenType] = "tokenType",
    [tokenArray] = "tokenArray",
    [tokenArrayRem] = "tokenArrayRem",
    [tokenArrayGet] = "tokenArrayGet",
    [tokenArrayAdd] = "tokenArrayAdd",
    [tokenArraySet] = "tokenArraySet",
    [tokenRecord] = "tokenRecord",
    [tokenRecordKeywords] = "tokenRecordKeywords",
    [tokenRecordValues] = "tokenRecordValues",
    [tokenRecordField] = "tokenRecordField",
    [tokenReadLine] = "tokenReadLine",
    [tokenDoubleQuote] = "tokenDoubleQuote",
    [tokenSemicolon] = "tokenSemicolon",
    [tokenRightArrow] = "tokenRightArrow",
    [tokenReturn] = "tokenReturn"
};

#endif