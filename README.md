# enum_sequence
C++'s integer sequence for enums

## Usage
```C++
#include "enum_sequence.hpp"

enum class rgb_color { red, green, blue };

// make_enum_sequence<Enum typename, min_value, max value>
// will generate enum seq like this:  <rgb_color::red, rgb_color::green, rgb_color::blue, (rgb_color)3, (rgb_color)4>
mgutility::detail::make_enum_sequence<rgb_color, 0, 5>; 

```
