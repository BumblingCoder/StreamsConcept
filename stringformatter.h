#pragma once

#include <string>

class StringFormatter{
public:
    StringFormatter( const std::string& str ) : string(str) {}
    const char* streamable_string() const { return string.c_str(); }
private:
    const std::string& string;
};
