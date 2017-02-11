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

  bool int_value_s::equals(const value_base_s& rhs) const
  {
    return rhs.equals(m_value);
  }
  
  bool int_value_s::equals(int value) const
  {
    return m_value == value;
  }
  
  bool int_value_s::equals(double value) const
  {
    return m_value == value;
  }
  
  bool int_value_s::equals(const std::string& value) const
  {
    try {
      size_t len = 0;
      return ((std::stoi(value, &len) == m_value) &&
	      (value.length() == len));
    } catch(...) {}

    return false;
  }

  std::ostream& int_value_s::write(std::ostream& stream) const
  {
    stream << m_value;
    return stream;
  }

  value_base_p make_int_value(const int value)
  {
    return value_base_p{new int_value_s{value}};
  }
}
