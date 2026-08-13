class Solution {

    private double Pow(double x, long n) {

        // Base case
        if (n == 0) {
            return 1.0;
        }

        // Handle negative exponent
        if (n < 0) {
            return 1.0 / Pow(x, -n);
        }

        // Calculate x^(n/2)
        double half = Pow(x, n / 2);

        // If n is even:
        // x^n = x^(n/2) * x^(n/2)
        if (n % 2 == 0) {
            return half * half;
        }

        // If n is odd:
        // x^n = x * x^(n/2) * x^(n/2)
        return x * half * half;
    }

    public double myPow(double x, int n) {
        return Pow(x, (long) n);
    }
}