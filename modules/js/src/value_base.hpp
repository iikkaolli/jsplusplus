#pragma once
#include "value.hpp"

namespace js
{
  struct value_c::value_base_s
  {
    value_base_s() {}
    virtual ~value_base_s(){}
    
    virtual bool is_object() const {return true;}
    virtual bool is_number() const {return false;}
    virtual bool is_string() const {return false;}
  };
}
