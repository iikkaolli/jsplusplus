
#include "value.hpp"

namespace js
{
  bool value::is_object() const
  {
    return true;
  }
  bool value::is_number() const
  {
    return false;
  }
  bool value::is_string() const
  {
    return false;
  }
}
