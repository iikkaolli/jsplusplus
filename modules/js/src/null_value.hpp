#pragma once
#include "value_base.hpp"

namespace js
{
  struct null_value_s : public value_c::value_base_s
  {
    null_value_s();
    ~null_value_s();

    value_base_p clone() const override;

    bool equals(const value_base_s&) const override;
    bool equals(std::nullptr_t) const override { return true; }

    std::ostream& write(std::ostream&) const override; 

  };
  
  value_base_p make_null_value();
}
