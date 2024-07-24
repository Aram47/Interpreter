#ifndef UNDEF_H
#define UNDEF_H

#include "../Fundamental_Type.h"

class Undef : public Fundamental_Type
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
    pair_type_value operator  ++  ()                       override;    // ++value
    pair_type_value operator  --  ()                       override;    // --value
public:
    Undef (const pair_type_value&);
    Undef (const Base_Type&);
};

#endif // UNDEF_H