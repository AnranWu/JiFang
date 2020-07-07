int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a%b);
}

int lcm(int a, int b)
{
    return a * (b/gcd(a, b));  // 建议先除再乘，避免乘法溢出
}
