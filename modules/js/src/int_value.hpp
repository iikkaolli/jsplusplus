#pragma once
#include "value_base.hpp"

namespace js
{
  struct int_value_s : public value_c::value_base_s
  {
    int m_value;

    int_value_s();
    int_value_s(int);
    ~int_value_s();

    value_base_p clone() const override;

    bool equals(int value) const override { return m_value == value; }
    bool is_number() const override { return true; }
  };

  value_base_p make_int_value(const int);
}
