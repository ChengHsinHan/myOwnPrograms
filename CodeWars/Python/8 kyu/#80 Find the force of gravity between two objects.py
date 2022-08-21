# Your job is to find the gravitational force between two spherical objects
# (obj1 , obj2).
#
# input
# Two arrays are given :
#
# arr_val (value array), consists of 3 elements
# 1st element : mass of obj 1
# 2nd element : mass of obj 2
# 3rd element : distance between their centers
# arr_unit (unit array), consists of 3 elements
# 1st element : unit for mass of obj 1
# 2nd element : unit for mass of obj 2
# 3rd element : unit for distance between their centers
# mass units are :
#
# kilogram (kg)
# gram (g)
# milligram (mg)
# microgram (μg)
# pound (lb)
# distance units are :
#
# meter (m)
# centimeter (cm)
# millimeter (mm)
# micrometer (μm)
# feet (ft)
# Note
# value of G = 6.67 × 10^(−11) N⋅ kg^(−2)⋅ m^2
#
# 1 ft = 0.3048 m
#
# 1 lb = 0.453592 kg
#
# return value must be Newton for force (obviously)
#
# μ copy this from here to use it in your solution

def solution(arr_val, arr_unit):
    convert_table = {
        "kg": 1,
        "g" : 1e-3,
        "mg": 1e-6,
        "μg": 1e-9,
        "lb": 0.453592,

        "m" : 1,
        "cm": 1e-2,
        "mm": 1e-3,
        "μm": 1e-6,
        "ft": 0.3048,
    }
    mass_1, mass_2, distance = (arr_val[index] * convert_table[arr_unit[index]] for index in range(len(arr_val)))
    return (6.67 * 1e-11 * mass_1 * mass_2) / (distance ** 2)
