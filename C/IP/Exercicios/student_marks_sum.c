// Explicação do exercício: https://www.hackerrank.com/contests/monitoria-ip/challenges/students-marks-sum/problem

int marks_summation(int* marks, int number_of_students, char gender) {
    int sum = 0;
    for (int i = 0; i < number_of_students; i++) {
        if (gender == 'b' && i % 2 == 0) {
            sum += marks[i];
        } else if (gender == 'g' && i % 2 != 0) {
            sum += marks[i];
        }
    }
    return sum;
}