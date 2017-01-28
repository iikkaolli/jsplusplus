#pragma once
#include "value_base.hpp"

namespace js
{
  struct null_value_s : public value_c::value_base_s
  {
    null_value_s();
    ~null_value_s();

    value_base_p clone() const override;

    bool equals(std::nullptr_t) const override { return true; }

    bool is_object() const override { return true; }
  };
  
  value_base_p make_null_value();
}
