#include "value.hpp"
#include "null_value.hpp"
#include "int_value.hpp"
#include "double_value.hpp"

namespace js
{
  // Constructors
  value_c::value_c()
    : m_pImpl(make_null_value())
  {}
  
  value_c::value_c(const value_c& other)
    : m_pImpl(other.m_pImpl->clone())
  {}
  
  value_c& value_c::operator=(const value_c& other)
  {
    m_pImpl = other.m_pImpl->clone();
    return *this;
  }
  
  value_c::~value_c()
  {}

  // Conversions
  value_c::value_c(const std::nullptr_t)
    : m_pImpl(make_null_value())
  { }
  
  value_c& value_c::operator=(const std::nullptr_t)
  {
    m_pImpl= make_null_value();
    return *this;
  }
  
  value_c::value_c(const int value)
    : m_pImpl(make_int_value(value))
  { }
  
  value_c& value_c::operator=(const int value)
  {
    m_pImpl= make_int_value(value);
    return *this;
  }
  
  value_c::value_c(const double value)
    : m_pImpl(make_double_value(value))
  { }
  
  value_c& value_c::operator=(const double value)
  {
    m_pImpl= make_double_value(value);
    return *this;
  }

  // 
  bool value_c::is_object() const
  {
    return m_pImpl->is_object();
  }
  bool value_c::is_number() const
  {
    return m_pImpl->is_number();
  }
  bool value_c::is_string() const
  {
    return m_pImpl->is_string();
  }

  // Equality nullptr
  bool operator==(const value_c& lhs, std::nullptr_t rhs)
  {
    return lhs.m_pImpl->equals(nullptr);
  }
  bool operator==(std::nullptr_t lhs, const value_c& rhs)
  {
    return rhs.m_pImpl->equals(nullptr);
  }
  bool operator!=(const value_c& lhs, std::nullptr_t rhs)
  {
    return !(lhs==rhs);
  }
  bool operator!=(std::nullptr_t lhs, const value_c& rhs)
  {
    return !(lhs==rhs);
  }

  // Equality int
  bool operator==(const value_c& lhs, int rhs)
  {
    return lhs.m_pImpl->equals(rhs);
  }
  
  bool operator==(int lhs, const value_c& rhs)
  {
    return rhs.m_pImpl->equals(lhs);
  }
  
  bool operator!=(const value_c& lhs, int rhs)
  {
    return !(lhs == rhs);
  }
  
  bool operator!=(int lhs, const value_c& rhs)
  {
    return !(lhs == rhs);
  }
 
  // Equality double
  bool operator==(const value_c& lhs, double rhs)
  {
    return lhs.m_pImpl->equals(rhs);
  }
  
  bool operator==(double lhs, const value_c& rhs)
  {
    return rhs.m_pImpl->equals(lhs);
  }
  
  bool operator!=(const value_c& lhs, double rhs)
  {
    return !(lhs == rhs);
  }
  
  bool operator!=(double lhs, const value_c& rhs)
  {
    return !(lhs == rhs);
  }
 
}
