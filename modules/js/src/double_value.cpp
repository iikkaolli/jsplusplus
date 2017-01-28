#include "double_value.hpp"

namespace js
{
  double_value_s::double_value_s()
    : double_value_s(0)
  {}

  double_value_s::double_value_s(const double value)
    : m_value(value)
  {}
  
  double_value_s::~double_value_s()
  {}

  value_base_p double_value_s::clone() const
  {
    return value_base_p{new double_value_s{m_value}};
  }
  
  value_base_p make_double_value(const double value)
  {
    return value_base_p{new double_value_s{value}};
  }
}
