#include "null_value.hpp"

namespace js
{
  namespace internal
  {
    null_value_s::null_value_s() {}
    null_value_s::~null_value_s() {}
    
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
  }
}
