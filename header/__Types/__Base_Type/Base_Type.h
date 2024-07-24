#ifndef BASE_TYPE_H
#define BASE_TYPE_H

#include <string>

// Abstract Class

class Base_Type
{
    using pair_type_value = std::pair<std::string, std::string>;
protected:
    std::string __type  {};
    std::string __value {};
public:
    virtual std::string __get_type  () const;
    virtual std::string __get_value () const;
public:
    // Logic
    virtual pair_type_value operator &&   (const Base_Type&) const  = 0;
    virtual pair_type_value operator ||   (const Base_Type&) const  = 0;
    virtual pair_type_value operator ==   (const Base_Type&) const  = 0;
    virtual pair_type_value operator !=   (const Base_Type&) const  = 0;
    virtual pair_type_value operator <    (const Base_Type&) const  = 0;
    virtual pair_type_value operator >    (const Base_Type&) const  = 0;
    virtual pair_type_value operator <=   (const Base_Type&) const  = 0;
    virtual pair_type_value operator >=   (const Base_Type&) const  = 0;

    // Ariphmetic
    virtual pair_type_value operator  +   (const Base_Type&) const  = 0;
    virtual pair_type_value operator  -   (const Base_Type&) const  = 0; 
    virtual pair_type_value operator  *   (const Base_Type&) const  = 0;
    virtual pair_type_value operator  /   (const Base_Type&) const  = 0;
    virtual pair_type_value operator  %   (const Base_Type&) const  = 0;
    virtual pair_type_value operator  <<  (const Base_Type&) const  = 0;
    virtual pair_type_value operator  >>  (const Base_Type&) const  = 0;
    virtual pair_type_value operator  |   (const Base_Type&) const  = 0;
    virtual pair_type_value operator  &   (const Base_Type&) const  = 0;
    virtual pair_type_value operator  ^   (const Base_Type&) const  = 0;

    // // Assignment
    virtual pair_type_value operator =    (const Base_Type&)        = 0;
    
    // // Ariphmetic postfix and prefix inc/dec
    virtual pair_type_value operator  ++  (int)                     = 0;    // value++
    virtual pair_type_value operator  --  (int)                     = 0;    // value--
    virtual pair_type_value operator ++   ()                        = 0;    // ++value
    virtual pair_type_value operator --   ()                        = 0;    // --value
public:
    virtual ~Base_Type();
};

#endif // BASE_TYPE_H