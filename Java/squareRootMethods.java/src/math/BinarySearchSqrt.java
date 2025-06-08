package math;

public class BinarySearchSqrt implements SquareRoot{
    private static final double EPSILON = 1e-9;

    @Override
    public double compute(double n) {
        if (n < 0) throw new IllegalArgumentException("Negative input");
        if (n == 0) return 0;

        double left = 0;
        double right = (n < 1) ? 1 : n;

        while ((right - left) > EPSILON * Math.max(1.0, n)) {
            double mid = (left + right) / 2;
            if (mid > n / mid) {
                right = mid;
            } else {
                left = mid;
            }
        }

        return (left + right) / 2;
    }
}
