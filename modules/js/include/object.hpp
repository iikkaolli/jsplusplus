#pragma once
#include "value.hpp"
#include <string>
#include <unordered_map>

namespace js
{
  class object_c
  {
    std::unordered_map<std::string, value_c> m_properties;
    
  public:
    object_c();
    ~object_c();

    void add_property(const std::string&, const value_c&);

    bool has_property(const std::string&);
  };
}