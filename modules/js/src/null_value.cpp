#include "null_value.hpp"

namespace js
{
  null_value_s::null_value_s()
  {}
  
  null_value_s::~null_value_s()
  {}
    
  bool null_value_s::is_object() const
  {
    return true;
  }
  
  bool null_value_s::is_number() const
  {
    return false;
  }
  
  bool null_value_s::is_string() const
  {
    return false;
  }
  
  value_base_p make_null_value()
  {
    return value_base_p{new null_value_s{}};
  }
}
