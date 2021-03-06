#pragma once
#include "value_base.hpp"

namespace js
{
  struct string_value_s : public value_c::value_base_s
  {
    std::string m_value;

    string_value_s();
    string_value_s(const std::string&);
    ~string_value_s();

    value_base_p clone() const override;

    bool equals(const value_base_s&) const override;
    bool equals(int) const override;
    bool equals(double) const override;
    bool equals(const std::string& value) const override;
    
    bool is_string() const override { return true; }

    std::ostream& write(std::ostream&) const override; 

  };

  value_base_p make_string_value(const std::string&);
}
