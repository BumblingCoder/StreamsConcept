#pragma once

namespace _floatFormatterInternal{
  template<int precision> constexpr const char* floatFormatString();
  template<> constexpr const char * floatFormatString<0>(){ return "%.0f"; }
  template<> constexpr const char * floatFormatString<1>(){ return "%.1f"; }
  template<> constexpr const char * floatFormatString<2>(){ return "%.2f"; }
  template<> constexpr const char * floatFormatString<3>(){ return "%.3f"; }
  template<> constexpr const char * floatFormatString<4>(){ return "%.4f"; }
  template<> constexpr const char * floatFormatString<5>(){ return "%.5f"; }
  template<> constexpr const char * floatFormatString<6>(){ return "%.6f"; }
  template<> constexpr const char * floatFormatString<7>(){ return "%.7f"; }
  template<> constexpr const char * floatFormatString<8>(){ return "%.8f"; }
  template<> constexpr const char * floatFormatString<9>(){ return "%.9f"; }
  template<> constexpr const char * floatFormatString<10>(){ return "%.10f"; }
  template<> constexpr const char * floatFormatString<11>(){ return "%.11"; }
  template<> constexpr const char * floatFormatString<12>(){ return "%.12f"; }
  template<> constexpr const char * floatFormatString<13>(){ return "%.13f"; }
  template<> constexpr const char * floatFormatString<14>(){ return "%.14f"; }
  template<> constexpr const char * floatFormatString<15>(){ return "%.15f"; }
  template<> constexpr const char * floatFormatString<16>(){ return "%.16f"; }
  template<> constexpr const char * floatFormatString<17>(){ return "%.17f"; }
  template<> constexpr const char * floatFormatString<18>(){ return "%.18f"; }
  template<> constexpr const char * floatFormatString<19>(){ return "%.19f"; }
  template<> constexpr const char * floatFormatString<20>(){ return "%.20f"; }
  template<> constexpr const char * floatFormatString<21>(){ return "%.21f"; }
  template<> constexpr const char * floatFormatString<22>(){ return "%.22f"; }
  template<> constexpr const char * floatFormatString<23>(){ return "%.23f"; }
  template<> constexpr const char * floatFormatString<24>(){ return "%.24f"; }
  template<> constexpr const char * floatFormatString<25>(){ return "%.25f"; }
  template<> constexpr const char * floatFormatString<26>(){ return "%.26f"; }
  template<> constexpr const char * floatFormatString<27>(){ return "%.27f"; }
  template<> constexpr const char * floatFormatString<28>(){ return "%.28f"; }
  template<> constexpr const char * floatFormatString<29>(){ return "%.29f"; }
  template<> constexpr const char * floatFormatString<30>(){ return "%.30f"; }
  template<> constexpr const char * floatFormatString<31>(){ return "%.31f"; }
  template<> constexpr const char * floatFormatString<32>(){ return "%.32f"; }
}

template< int precision = 6>
class FloatFormatter
{
public:
    FloatFormatter(double f) { snprintf( buffer, 30, _floatFormatterInternal::floatFormatString<precision>(), f ); }
    const char* streamable_string() const { return buffer; }
private:
    char buffer[30];
};
