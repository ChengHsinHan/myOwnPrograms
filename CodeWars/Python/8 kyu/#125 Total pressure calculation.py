# Given the molecular mass of two molecules M_1 and M_2, their masses present
# m_1 and m_2 in a vessel of volume V at a specific temperature T, find the
# total pressure P_{total} exerted by the molecules. Formula to calculate the
# pressure is:
#
# P_{total} = (m_1 / M_1 + m_2 / M_2) * RT / V

# Input
# Six values :
#
# M_1, M_2: molar masses of both gases, in grams (g)
# m_1 and m_2: present mass of both gases, in  g⋅mol^(−1)
# V: volume of the vessel, in dm^3
# T: temperature, in °C
# Output
# One value: P_{total}, in units of atm.
#
# Notes
# Remember: Temperature is given in Celsius while SI unit is Kelvin (K). 0°C =
# 273.15K
#
# The gas constant R = 0.082 dm^3⋅atm⋅K^(−1)⋅mol^(−1)

def solution(molar_mass1, molar_mass2, given_mass1, given_mass2, volume, temp):
    return ((given_mass1 / molar_mass1 + given_mass2 / molar_mass2) * 0.082 * (temp + 273.15)) / volume
