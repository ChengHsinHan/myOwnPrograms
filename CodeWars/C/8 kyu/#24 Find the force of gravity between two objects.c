// Your job is to find the gravitational force between two spherical objects
// (obj1 , obj2).
//
// input
// Two arrays are given :
//
// arr_val (value array), consists of 3 elements
// 1st element : mass of obj 1
// 2nd element : mass of obj 2
// 3rd element : distance between their centers
// arr_unit (unit array), consists of 3 elements
// 1st element : unit for mass of obj 1
// 2nd element : unit for mass of obj 2
// 3rd element : unit for distance between their centers
// mass units are :
//
// kilogram (kg)
// gram (g)
// milligram (mg)
// microgram (μg)
// pound (lb)
// distance units are :
//
// meter (m)
// centimeter (cm)
// millimeter (mm)
// micrometer (μm)
// feet (ft)
// Note
// value of G = 6.67 × 10−11 N⋅kg−2⋅m2
//
// 1 ft = 0.3048 m
//
// 1 lb = 0.453592 kg
//
// return value must be Newton for force (obviously)
//
// μ copy this from here to use it in your solution

#include <string.h>

double solution(const double* values, const char** units)
{
    double objectInfo[] = { values[0], values[1], values[2] };
    for (unsigned int index = 0; index < 3; ++index)
    {
        if (strcmp(units[index], "cm") == 0)
            objectInfo[index] *= 1e-2;
        else if ((strcmp(units[index], "g") == 0) || (strcmp(units[index], "mm") == 0))
            objectInfo[index] *= 1e-3;
        else if ((strcmp(units[index], "mg") == 0) || (strcmp(units[index], "μm") == 0))
            objectInfo[index] *= 1e-6;
        else if (strcmp(units[index], "μg") == 0)
            objectInfo[index] *= 1e-9;
        else if (strcmp(units[index], "lb") == 0)
            objectInfo[index] *= 0.453592;
        else if (strcmp(units[index], "ft") == 0)
            objectInfo[index] *= 0.3048;
    }
    return (6.67 * 1e-11 * objectInfo[0] * objectInfo[1]) / (objectInfo[2] * objectInfo[2]);
}
