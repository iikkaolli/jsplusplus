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
  
    bool string_value_s::equals(const value_base_s& rhs) const
    {
      return rhs.equals(m_value);
    }
  
    bool string_value_s::equals(int value) const
    {
      try {
	size_t len = 0;
	return ((std::stoi(m_value, &len) == value) &&
		(m_value.length() == len));
      } catch(...) {
      }
      
      return false;
    }
  
    bool string_value_s::equals(double value) const
    {
      try {
	size_t len = 0;
	return ((std::stod(m_value, &len) == value) &&
		(m_value.length() == len));
      } catch(...) {
      }
      
      return false;
    }
  
    bool string_value_s::equals(const std::string& value) const
    {
      return m_value == value;
    }
    
  value_base_p make_string_value(const std::string& value)
  {
    return value_base_p{new string_value_s{value}};
  }
}
