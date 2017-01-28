#include "int_value.hpp"

namespace js
{
  int_value_s::int_value_s()
    : int_value_s(0)
  {}

  int_value_s::int_value_s(const int value)
    : m_value(value)
  {}
  
  int_value_s::~int_value_s()
  {}

  value_base_p int_value_s::clone() const
  {
    return value_base_p{new int_value_s{m_value}};
  }
  
  value_base_p make_int_value(const int value)
  {
    return value_base_p{new int_value_s{value}};
  }
}
