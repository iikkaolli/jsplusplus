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
  
  value_base_p make_null_value()
  {
    return value_base_p{new null_value_s{}};
  }
}
