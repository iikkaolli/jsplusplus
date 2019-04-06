#include "null_value.hpp"

namespace js
{
  null_value_s::null_value_s()
  {}
  
  null_value_s::~null_value_s()
  {}

  value_base_p null_value_s::clone() const
  {
    return value_base_p{new null_value_s{}};
  }

  bool null_value_s::equals(const value_base_s& rhs) const
  {
    return !rhs.is_object() && !rhs.is_number() && !rhs.is_string();
  }

  std::ostream& null_value_s::write(std::ostream& stream) const
  {
    stream << "null";
    return stream;
  }

  value_base_p make_null_value()
  {
    return value_base_p{new null_value_s{}};
  }
}
