// There are pillars near the road. The distance between the pillars is the same
// and the width of the pillars is the same. Your function accepts three
// arguments:
//
// number of pillars (≥ 1);
// distance between pillars (10 - 30 meters);
// width of the pillar (10 - 50 centimeters).
// Calculate the distance between the first and the last pillar in centimeters
// (without the width of the first and last pillar).

long pillars(int num_of_pillars, int distance, int width)
{
    return (distance * (num_of_pillars - 1) * 100 + width * (num_of_pillars - 2) * (num_of_pillars > 1));
}
