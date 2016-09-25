#include <string>

#include "defaultformatter.h"
#include "floatformatter.h"
#include "floatformatter.h"
#include "outstream.h"
#include "stdoutwriter.h"
#include "streamconcepts.h"
#include "stringformatter.h"

int main()
{
    using namespace std::string_literals;
    OutStream<StdOutWriter,DefaultFormatter<float, FloatFormatter<1>, double, FloatFormatter<>, std::string, StringFormatter>> stream;
    stream << "Hello World! " << 4.5f << " is a float and "s << 4.5 << " is a double!";
    return 0;
}
