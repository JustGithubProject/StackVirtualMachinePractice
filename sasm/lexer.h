#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <vector>

// Type definitions
typedef uint8_t byte;
typedef std::vector<std::string> strings;

enum State : byte 
{
    START,
    READCHAR,
    READBLOCK,
    SKIP,
    DUMP,
    COMMENT,
    END
}

class Lexer
{
private:
    bool myIsSpace(char c);
    bool isSpecial(char c);
    bool isGroup(char c);
    char endChar, begChar;
public:
    strings lex(std::string s);
    
};

#endif