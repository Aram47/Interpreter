#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include "../__Fundamental_Type/Fundamental_Type.h"

class Number : public Fundamental_Type {
public:
    Number(const std::string&);
public:
    virtual std::pair<std::string, std::string>   operator+   (Base_Type*)   override;
    virtual std::pair<std::string, std::string>   operator-   (Base_Type*)   override;
    // virtual std::pair<std::string, std::string>   operator++  (    int   );
    // virtual std::pair<std::string, std::string>   operator--  (    int   );
    // virtual std::pair<std::string, std::string>   operator++  (          );
    // virtual std::pair<std::string, std::string>   operator--  (          );
    // virtual std::pair<std::string, std::string>   operator*   (Base_Type*);
    // virtual std::pair<std::string, std::string>   operator/   (Base_Type*);
    // virtual std::pair<std::string, std::string>   operator%   (Base_Type*);
};

#endif // NUMBER_H