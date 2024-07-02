#ifndef FUNDAMENTAL_TYPE_H
#define FUNDAMENTAL_TYPE_H

#include "../__Base_Type/Base_Type.h"

class Fundamental_Type : public Base_Type
{
    std::string __value;
public:
    virtual ~Fundamental_Type                           (                      ) = 0;
public:
    void          set_value                             (   const std::string&     );
    std::string   get_value                             (                          );
public:
    virtual std::pair<std::string, std::string>   operator+   (Base_Type*)        = 0;
    virtual std::pair<std::string, std::string>   operator-   (Base_Type*)        = 0;
};

#endif // FUNDAMENTAL_TYPE_H