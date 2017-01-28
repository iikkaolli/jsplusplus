#pragma once
#include "value_base.hpp"

namespace js
{
  struct double_value_s : public value_c::value_base_s
  {
    double m_value;

    double_value_s();
    double_value_s(double);
    ~double_value_s();

    value_base_p clone() const override;

    bool equals(double value) const override { return m_value == value; }
    bool is_number() const override { return true; }
  };

  value_base_p make_double_value(const double);
}
