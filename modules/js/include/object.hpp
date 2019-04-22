#pragma once
#include "value.hpp"
#include <string>
#include <unordered_map>
#include <memory>
#include <initializer_list>

namespace js
{
  class object_c
  {
    std::unordered_map<std::string, value_c> m_properties;
    
  public:
    using keyValueType = std::pair<std::string, value_c>;

    object_c();
    object_c(std::initializer_list<keyValueType>);
    ~object_c();

    const value_c& operator[](const std::string&) const;
    value_c& operator[](const std::string&);

    bool has_property(const std::string&);
    void add_property(const std::string&, const value_c&);
    void add_property(std::pair<std::string, value_c>);

  };
}
