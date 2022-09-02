# Write function bmi that calculates body mass index (bmi = weight / height^2).
#
# if bmi <= 18.5 return "Underweight"
#
# if bmi <= 25.0 return "Normal"
#
# if bmi <= 30.0 return "Overweight"
#
# if bmi > 30 return "Obese"

def bmi(weight, height):
    result = weight / (height ** 2)
    if result <= 18.5:
        return "Underweight"
    elif 18.5 < result <= 25.0:
        return "Normal"
    elif 25.0 < result <= 30.0:
        return "Overweight"
    else:
        return "Obese"
