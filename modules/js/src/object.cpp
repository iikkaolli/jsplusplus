#include "object.hpp"

namespace js
{
  object_c::object_c()
  {}
  
  object_c::~object_c()
  {}
  
  void object_c::add_property(const std::string& name, const value_c& value)
  {
    m_properties.insert(std::make_pair(name, value));
  }
  
  bool object_c::has_property(const std::string& name)
  {
    auto iter = m_properties.find(name);
    return iter != m_properties.end();
  }
}
