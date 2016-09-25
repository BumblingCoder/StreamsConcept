#pragma once

#include <cstdio>

class StdOutWriter
{
public:
    static void write( const char* streamable ){ fputs( streamable, stdout ); }
};
