#ifndef NUMBER_H
#define NUMBER_H

#include "../Fundamental_Type.h"

class Number : public Fundamental_Type
{
    using pair_type_value = std::pair<std::string, std::string>;
public:
    // Logic 
    pair_type_value operator  &&  (const Base_Type&) const override;
    pair_type_value operator  ||  (const Base_Type&) const override;
    pair_type_value operator  ==  (const Base_Type&) const override;
    pair_type_value operator  !=  (const Base_Type&) const override;
    pair_type_value operator  <   (const Base_Type&) const override;
    pair_type_value operator  >   (const Base_Type&) const override;
    pair_type_value operator  <=  (const Base_Type&) const override;
    pair_type_value operator  >=  (const Base_Type&) const override;

    // Ariphmetic
    pair_type_value operator  +   (const Base_Type&) const override;
    pair_type_value operator  -   (const Base_Type&) const override; 
    pair_type_value operator  *   (const Base_Type&) const override;
    pair_type_value operator  /   (const Base_Type&) const override;
    pair_type_value operator  %   (const Base_Type&) const override;
    pair_type_value operator  <<  (const Base_Type&) const override;
    pair_type_value operator  >>  (const Base_Type&) const override;
    pair_type_value operator  |   (const Base_Type&) const override;
    pair_type_value operator  &   (const Base_Type&) const override;
    pair_type_value operator  ^   (const Base_Type&) const override;

    // // Assignments
    pair_type_value operator =    (const Base_Type&)       override;

    // // Ariphmetic postfix and prefix inc/dec
    pair_type_value operator  ++  (int)                    override;    // value++
    pair_type_value operator  --  (int)                    override;    // value--
    pair_type_value operator ++   ()                       override;    // ++value
    pair_type_value operator --   ()                       override;    // --value
public:
    Number (const pair_type_value&);
    Number (const Base_Type&);
};

#endif // NUMBER_H