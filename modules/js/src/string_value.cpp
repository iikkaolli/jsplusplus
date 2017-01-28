#include "string_value.hpp"

namespace js
{
  string_value_s::string_value_s()
    : string_value_s(std::string{})
  {}

  string_value_s::string_value_s(const std::string& value)
    : m_value(value)
  {}
  
  string_value_s::~string_value_s()
  {}

  value_base_p string_value_s::clone() const
  {
    return value_base_p{new string_value_s{m_value}};
  }
  
  value_base_p make_string_value(const std::string& value)
  {
    return value_base_p{new string_value_s{value}};
  }
}
