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

    bool equals(const value_base_s&) const override;
    bool equals(int value) const override;
    bool equals(double value) const override;
    bool equals(const std::string&) const override;
    
    bool is_number() const override { return true; }

    std::ostream& write(std::ostream&) const override; 
  };

  value_base_p make_double_value(const double);
}
