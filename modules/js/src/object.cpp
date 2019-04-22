#include "object.hpp"

namespace js
{
  object_c::object_c()
  {}
  
  object_c::object_c(std::initializer_list<keyValueType> initList)
  {
    m_properties.insert(initList.begin(), initList.end());
  }

  object_c::~object_c()
  {}

  const value_c& object_c::operator[](const std::string& name) const
  {
    auto valueIter = m_properties.find(name);
    if(valueIter != m_properties.end())
    {
      return valueIter->second;
    }
    
    return EmptyValue;
  }
  
  value_c& object_c::operator[](const std::string& name)
  {
    auto valueIter = m_properties.find(name);
    if(valueIter != m_properties.end())
    {
      return valueIter->second;
    }
    else
    {
      auto returnValue = m_properties.insert(std::make_pair(name, value_c{}));
      return returnValue.first->second;
    }
  }

  bool object_c::has_property(const std::string& name)
  {
    auto iter = m_properties.find(name);
    return iter != m_properties.end();
  }

  void object_c::add_property(const std::string& name, const value_c& value)
  {
    this->add_property(std::make_pair(name, value));
  }

  void object_c::add_property(std::pair<std::string, value_c> keyValuePair)
  {
    m_properties.insert(keyValuePair);
  }
}
