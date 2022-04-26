#include <string>

#ifndef COMPILER_TOKENS_H
#define COMPILER_TOKENS_H

enum Code {
    tokOpenParenthesis, // 0
    tokCloseParenthesis, // 1
    tokOpenBracket, // 2
    tokCloseBracket, // 3
    tokSlash, // 4
    tokQuote, // 5
    tokSetq, // 6
    tokFunc, // 7
    tokLambda, // 8
    tokProg, // 9
    tokCond, // 10
    tokWhile, // 11
    tokReturn, // 12
    tokBreak, // 13
    tokEqual, // 14
    tokNonEqual, // 15
    tokLess, // 16
    tokLessEq, // 17
    tokGreater, // 18
    tokGreaterEq, // 19
    tokIsInt, // 20
    tokIsReal, // 21
    tokIsBool, // 22
    tokIsNull, // 23
    tokIsAtom, // 24
    tokIsList, // 25
    tokAnd, // 26
    tokOr, // 27
    tokXor, // 28
    tokNot, // 29
    tokTrue, // 30
    tokFalse, // 31
    tokPlus, // 32
    tokMinus, // 33
    tokTimes, // 34
    tokDivide, // 35
    tokHead, // 36
    tokTail, // 37
    tokCons, // 38
    tokEval, // 39
    tokInt, // 40
    tokReal, // 41
    tokBoolean, // 42
    tokAtom, // 43
    tokList, // 44
    tokRoot, // 45
    tokEndFile, // 46
    tokFunction // 47
};

struct Location {
    int line;
    int position;
};

struct Value {
    int intVal;
    double realVal;
    bool boolVal;
    std::string atomVal;
};

struct Token {
    unsigned int code;
    Value value;
    Location location;
};

#endif //COMPILER_TOKENS_H