#ifndef MGUTILITY_ENUM_SEQ_HPP
#define MGUTILITY_ENUM_SEQ_HPP
#include <cstdint>

namespace mgutility{
namespace detail{

#ifndef MIN_ENUM_VALUE
#define MIN_ENUM_VALUE 0
#endif

template <typename Enum, Enum ...>
struct enum_sequence{};

template <typename Enum, int N, int ... Next>
struct enum_sequence_helper : enum_sequence_helper<Enum, N-1, N-1, Next...>{};

template <typename Enum, int ... Next>
struct enum_sequence_helper<Enum, MIN_ENUM_VALUE, Next ... >{ using type = enum_sequence<Enum, static_cast<Enum>(Next) ... >; };

template <typename Enum, int N>
using make_enum_sequence = typename enum_sequence_helper<Enum, N>::type;
}
}
#endif // MGUTILITY_ENUM_SEQ_HPP
