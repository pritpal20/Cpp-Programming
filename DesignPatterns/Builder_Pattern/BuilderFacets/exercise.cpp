#include <string>
#include <ostream>
using namespace std;

class CodeBuilder
{
public:
  CodeBuilder(const string& class_name)
  {
      // todo
      
  }

  CodeBuilder& add_field(const string& name, const string& type)
  {
    // todo
  }

  friend ostream& operator<<(ostream& os, const CodeBuilder& obj)
  {
     return os
      << "street_address: " << obj.street_address
      << " post_code: " << obj.post_code
      << " city: " << obj.city
      << " company_name: " << obj.company_name
      << " position: " << obj.position
      << " annual_income: " << obj.annual_income;
  }
};