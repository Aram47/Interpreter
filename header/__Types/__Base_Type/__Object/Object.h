#ifndef OBJECT_H
#define OBJECT_H

#include <unordered_map>
#include "../Base_Type.h"
#include "../__Fundamental_Type/__String/String.h"
#include "../__Fundamental_Type/__Undef/Undef.h"

class Object : public Base_Type
{
public:
    using pair_type_value = std::pair<std::string, std::string>;
    using object_members = std::unordered_map<std::string, Base_Type*>;
public:
    object_members __members;
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

    pair_type_value operator  []  (const String&);
public:
    Object (const pair_type_value&);
    Object (const Base_Type&);
private:
    std::string __resolve_and_members_initalization(const std::string&);
    std::string __new_lines_and_tabuliation_adder(const std::string&);
    std::string __key_value_catter(const std::string&);
};

#endif // OBJECT_H