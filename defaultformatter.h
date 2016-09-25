#pragma once

#include "voidformatter.h"

template<typename... formatable>
class DefaultFormatter{ public: static VoidFormatter formatter() { return VoidFormatter{}; } };

template< typename Formatable, typename Streamable, typename... Ts >
class DefaultFormatter<Formatable, Streamable, Ts...> : public DefaultFormatter< Ts... >
{
public:
    using DefaultFormatter< Ts... >::formatter;
    static Streamable formatter( const Formatable& f ) { return Streamable{f}; }
};
