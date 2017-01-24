#pragma once
#include "value_base.hpp"

namespace js
{
  namespace internal
  {
    struct null_value_s : public value_c::value_base_s
    {
      null_value_s();
      ~null_value_s();
      
      bool is_object() const override;
      bool is_number() const override;
      bool is_string() const override;
    };
  }
}
