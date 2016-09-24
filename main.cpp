#include <cstdio>

using namespace std;

template<typename T>
concept bool Streamable = requires( T a ) { {a.streamable_string() } -> const char*; };

template<typename T>
concept bool Stream = requires(T a) { { a << "streams support streaming characters" }; };

class FloatFormatter
{
public:
    FloatFormatter(float f) { snprintf( buffer, 30, "%f", f ); }
    const char* streamable_string() const { return buffer; }
private:
    char buffer[30];
};

template<typename... formatable>
class DefaultFormatter{};

template< typename Formatable, typename Streamable, typename... Ts >
class DefaultFormatter<Formatable, Streamable, Ts...> : DefaultFormatter< Ts... >
{
public:
    static Streamable formatter( const Formatable& f ) { return Streamable{f}; }
};

template<class RealStream, class DefaultFormatter>
class BaseOutStream
{
public:
    template<typename T>
    RealStream& operator<<(const T& item ) { *stream << DefaultFormatter::formatter(item); return *stream; }
    RealStream& operator<<(const Streamable& streamable){ *stream << streamable.streamable_string(); return *stream; }
private:
    RealStream* stream = static_cast<RealStream*>(this);
};

template<typename DefaultFormatter>
class StdOutStream : public BaseOutStream< StdOutStream<DefaultFormatter>, DefaultFormatter >
{
public:
    using BaseOutStream<StdOutStream<DefaultFormatter>, DefaultFormatter >::operator<<;
    StdOutStream& operator<<(const char* streamable){ fputs( streamable, stdout ); return *this; }
};

int main()
{
    StdOutStream<DefaultFormatter<float, FloatFormatter, double, FloatFormatter>> stream;
    stream << "Hello World! " << 4.5f << " is a float\n";
    return 0;
}
