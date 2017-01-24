#include "value.hpp"
#include "null_value.hpp"

namespace js
{
  value_c::value_c() : m_pImpl(new value_base_s{}){}
  value_c::~value_c(){}

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

  bool operator==(const value_c& lhs, std::nullptr_t rhs)
  {
    return true;
  }
  bool operator==(std::nullptr_t lhs, const value_c& rhs)
  {
    return true;
  }
}
