package math;

public class NewtonRaphsonSqrt implements SquareRoot{
    private static final double EPSILON = 1e-9;

    @Override
    public double compute(double n) {
        if (n < 0) throw new IllegalArgumentException("Negative input");
        if (n == 0) return 0;

        double x = n;
        while (Math.abs(x * x - n) / n > EPSILON) {
            x = (x + n / x) / 2;
        }
        return x;
    }
}
