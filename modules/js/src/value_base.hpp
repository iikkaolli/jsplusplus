#pragma once
#include "value.hpp"
#include <ostream>

namespace js
{
  using value_base_p = std::unique_ptr<value_c::value_base_s>;
  
  struct value_c::value_base_s
  {
    value_base_s() = default;
    virtual ~value_base_s() = default;

    virtual value_base_p clone() const = 0;

    virtual bool equals(const value_base_s&) const = 0;
    virtual bool equals(std::nullptr_t) const { return false; }
    virtual bool equals(int) const { return false; }
    virtual bool equals(double) const { return false; }
    virtual bool equals(const std::string&) const { return false; }

    virtual bool is_object() const { return false; }
    virtual bool is_number() const { return false; }
    virtual bool is_string() const { return false; }

    virtual std::ostream& write(std::ostream&) const = 0; 
  };
}
