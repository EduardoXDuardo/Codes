import java.util.Arrays;
import java.util.List;
import math.SquareRoot;
import math.NewtonRaphsonSqrt;
import math.BinarySearchSqrt;

public class Main {
    public static void main(String[] args) {
        List<Double> testValues = Arrays.asList(0.0001, 0.01, 0.5, 1.0, 2.0, 10.0, 100.0, 10000.0, 1e6, 1e15, 1e100);

        List<SquareRoot> methods = Arrays.asList(
                new NewtonRaphsonSqrt(),
                new BinarySearchSqrt()
        );

        List<String> methodNames = Arrays.asList("Newton", "Binary");

        System.out.printf("%-10s %-10s %-15s %-15s\n", "Method", "Input", "Result", "Time (ns)");
        System.out.println("---------------------------------------------------------------");

        for (double value : testValues) {
            for (int i = 0; i < methods.size(); i++) {
                SquareRoot method = methods.get(i);
                String name = methodNames.get(i);

                try {
                    long start = System.nanoTime();
                    double result = method.compute(value);
                    long end = System.nanoTime();

                    System.out.printf("%-10s %-10.4f %-15.8f %-15d\n", name, value, result, end - start);
                } catch (IllegalArgumentException e) {
                    System.out.printf("%-10s %-10.4f %-15s %-15s\n", name, value, "N/A", "Invalid input");
                }
            }
            System.out.println();
        }
        System.out.println("---------------------------------------------------------------");
    }
}