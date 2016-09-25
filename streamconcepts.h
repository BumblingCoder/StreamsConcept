#pragma once

template<typename T>
concept bool Streamable = requires( T a ) { {a.streamable_string() } -> const char*; };

template<typename T>
concept bool Stream = requires(T a) { { a << "streams support streaming characters" }; };

template<typename T>
concept bool Writer = requires(T a) { { T::write("writers can write output") }; };
