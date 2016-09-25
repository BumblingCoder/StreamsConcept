#pragma once

#include <type_traits>

class IntFormatter
{
public:
    template< typename T > requires std::is_signed<T>()()
    IntFormatter(T i);
    const char* streamable_string() const {return buffer; }
private:
    char buffer[30];
};

template<> IntFormatter::IntFormatter<short int>( short int i ) { snprintf( buffer, 30, "%hi", i ); }
template<> IntFormatter::IntFormatter<int>( int i ) { snprintf( buffer, 30, "%i", i ); }
template<> IntFormatter::IntFormatter<long int>( long int i ) { snprintf( buffer, 30, "%li", i ); }
template<> IntFormatter::IntFormatter<long long int>( long long int i ) { snprintf( buffer, 30, "%lli", i ); }
