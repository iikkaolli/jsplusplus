#pragma once
#include "value.hpp"

namespace js
{
  using value_base_p = std::unique_ptr<value_c::value_base_s>;
  
  struct value_c::value_base_s
  {
    value_base_s() = default;
    virtual ~value_base_s() = default;
    
    virtual bool is_object() const = 0;
    virtual bool is_number() const = 0;
    virtual bool is_string() const = 0;
  };
}
