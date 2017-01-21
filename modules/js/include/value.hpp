
namespace js
{
  
class value
{
public:
  virtual bool is_object() const;
  virtual bool is_number() const;
  virtual bool is_string() const;
};

}
