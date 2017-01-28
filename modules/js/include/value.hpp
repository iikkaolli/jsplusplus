#pragma once
#include <memory>

namespace js
{
  
  class value_c
  {
  public:
    struct value_base_s;
    
    value_c();
    value_c(const value_c&);
    value_c& operator=(const value_c&);
    ~value_c();

    value_c(const std::nullptr_t);
    value_c& operator=(const std::nullptr_t);

    value_c(const int);
    value_c& operator=(const int);

    value_c(const double);
    value_c& operator=(const double);

    bool is_object() const;
    bool is_number() const;
    bool is_string() const;

    friend bool operator==(const value_c&, std::nullptr_t);
    friend bool operator==(std::nullptr_t, const value_c&);
    friend bool operator!=(const value_c&, std::nullptr_t);
    friend bool operator!=(std::nullptr_t, const value_c&);

    friend bool operator==(const value_c&, int);
    friend bool operator==(int, const value_c&);
    friend bool operator!=(const value_c&, int);
    friend bool operator!=(int, const value_c&);
   
    friend bool operator==(const value_c&, double);
    friend bool operator==(double, const value_c&);
    friend bool operator!=(const value_c&, double);
    friend bool operator!=(double, const value_c&);
   
  private:
    std::unique_ptr<value_base_s> m_pImpl;
    
  };
}
