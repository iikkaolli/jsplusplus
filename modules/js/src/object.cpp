#include "object.hpp"

namespace js
{
  object_c::object_c()
  {}
  
  object_c::~object_c()
  {}

  const value_c& object_c::operator[](const std::string& name)
  {
    auto valueIter = m_properties.find(name);
    if(valueIter != m_properties.end())
    {
      return valueIter->second;
    }
    
    return EmptyValue;
  }
  
  bool object_c::has_property(const std::string& name)
  {
    auto iter = m_properties.find(name);
    return iter != m_properties.end();
  }

  void object_c::add_property(const std::string& name, const value_c& value)
  {
    m_properties.insert(std::make_pair(name, value));
  }
  
}
