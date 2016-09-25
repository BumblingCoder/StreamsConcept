#include <string>

#include "defaultformatter.h"
#include "floatformatter.h"
#include "floatformatter.h"
#include "outstream.h"
#include "stdoutwriter.h"
#include "streamconcepts.h"
#include "stringformatter.h"
#include "intformatter.h"

int main()
{
    using namespace std::string_literals;
    OutStream<StdOutWriter,DefaultFormatter<float, FloatFormatter<1>,
                                            double, FloatFormatter<>,
                                            std::string, StringFormatter,
                                            short int, IntFormatter,
                                            int, IntFormatter,
                                            long int, IntFormatter,
                                            long long int, IntFormatter>> stream;
    stream << 4.5f <<" float\n";
    stream << 4.5 <<" double\n";
    stream << "str"s <<" string\n";
    stream << static_cast<short>(-4) <<" short\n";
    stream << -5 <<" int\n";
    stream << static_cast<long>(-6) <<" long\n";
    stream << static_cast<long long>(-7) <<" long long\n";
    return 0;
}
