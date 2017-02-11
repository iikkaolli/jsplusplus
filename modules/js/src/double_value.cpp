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
  
  bool double_value_s::equals(const value_base_s& rhs) const
  {
    return rhs.equals(m_value);
  }

  bool double_value_s::equals(int value) const
  {
    return m_value == value;
  }
  
  bool double_value_s::equals(double value) const
  {
    return m_value == value;
  }
  
  bool double_value_s::equals(const std::string& value) const
  {
    try {
      size_t len = 0;
      return ((std::stod(value, &len) == m_value) &&
	      (value.length() == len));
    } catch(...) {}

    return false;
  }

  value_base_p make_double_value(const double value)
  {
    return value_base_p{new double_value_s{value}};
  }
}
