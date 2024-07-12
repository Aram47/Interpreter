#ifndef INTERSECTION_H
#define INTERSECTION_H

#include <vector>
#include <string>
#include "../__Copywriter/Copywriter.h"

class Intersection
{
    using vec_str = std::vector<std::string>;
    Copywriter* __cpw = nullptr;
public:
    Intersection();
    ~Intersection();
public:
    void resolv(const vec_str&);
};

#endif // INTERSECTION_H