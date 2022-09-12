// Write function bmi that calculates body mass index (bmi = weight / height^2).
//
// if bmi <= 18.5 return "Underweight"
//
// if bmi <= 25.0 return "Normal"
//
// if bmi <= 30.0 return "Overweight"
//
// if bmi > 30 return "Obese"

/*    N.B. do not allocate memory,
   instead: return a string literal  */

const char* bmi(int weight, double height)
{
    double result = (double) weight / (height * height);
    if (result <= 18.5)
        return "Underweight";
    else if ((result <= 25.0) && (result > 18.5))
        return "Normal";
    else if ((result <= 30.0) && (result > 25.0))
        return "Overweight";
    else
        return "Obese";
}
