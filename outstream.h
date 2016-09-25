#pragma once

#include "streamconcepts.h"

template<class Writer, class DefaultFormatter>
class OutStream
{
public:
    template<typename T>
    OutStream& operator<<(const T& item ) { *this << DefaultFormatter::formatter(item); return *this; }
    OutStream& operator<<(const Streamable& streamable){ *this << streamable.streamable_string(); return *this; }
    OutStream& operator<<(const char* streamable ){ Writer::write(streamable); return *this; }
};
