#ifndef BASE_TYPE_H
#define BASE_TYPE_H

#include <string>

class Base_Type {
    std::string __type_name;
public:
    virtual ~Base_Type()                           = 0;
public:
    void          set_type_name   (const std::string&);
    std::string   get_type_name   (                  );
};

#endif // BASE_TYPE_H