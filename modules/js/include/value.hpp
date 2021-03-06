#pragma once
#include <memory>
#include <ostream>

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

    value_c(const char*);
    value_c& operator=(const char*);
    
    value_c(const std::string&);
    value_c& operator=(const std::string&);

    bool is_object() const;
    bool is_number() const;
    bool is_string() const;

    friend bool operator==(const value_c&, const value_c&);
    friend bool operator!=(const value_c&, const value_c&);

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
   
    friend bool operator==(const value_c&, const char *);
    friend bool operator==(const char*, const value_c&);
    friend bool operator!=(const value_c&, const char*);
    friend bool operator!=(const char*, const value_c&);
   
    friend bool operator==(const value_c&, const std::string&);
    friend bool operator==(const std::string&, const value_c&);
    friend bool operator!=(const value_c&, const std::string&);
    friend bool operator!=(const std::string&, const value_c&);

    friend std::ostream& operator<<(std::ostream&, const js::value_c&);

  private:
    std::unique_ptr<value_base_s> m_pImpl;
    
  };

  static value_c EmptyValue;

}

