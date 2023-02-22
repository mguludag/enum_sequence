#ifndef MGUTILITY_ENUM_SEQ_HPP
#define MGUTILITY_ENUM_SEQ_HPP
#include <cstdint>

namespace mgutility{
namespace detail{

template <typename Enum, Enum ...>
struct enum_sequence{};

template <typename Enum, int Min, int Max, int ... Next>
struct enum_sequence_helper : enum_sequence_helper<Enum, Min, Max-1, Max-1, Next...>{};

template <typename Enum, int Min, int ... Next>
struct enum_sequence_helper<Enum, Min, Min, Next ... >{ using type = enum_sequence<Enum, static_cast<Enum>(Next) ... >; };

template <typename Enum, int Min, int Max>
using make_enum_sequence = typename enum_sequence_helper<Enum, Min, Max>::type;
}
}
#endif // MGUTILITY_ENUM_SEQ_HPP
