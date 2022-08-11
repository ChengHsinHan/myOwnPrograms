// There was a test in your class and you passed it. Congratulations!
// But you're an ambitious person. You want to know if you're better than the
// average student in your class.
//
// You receive an array with your peers' test scores. Now calculate the average
// and compare your score!
//
// Return True if you're better, else False!
//
// Note:
// Your points are not included in the array of your class's points. For
// calculating the average point you may add your point to the given array!

int better_than_average(int class_points[], int class_size, int your_points)
{
    int total_score = 0;
    for (int index = 0; index < class_size; ++index)
        total_score += class_points[index];
    return your_points > ((double)(total_score) / (double)(class_size));
}
