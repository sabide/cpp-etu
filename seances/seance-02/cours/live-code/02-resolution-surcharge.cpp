#include <iostream>

void evaluate(int)
{
    std::cout << "evaluate(int)\n";
}

void evaluate(double)
{
    std::cout << "evaluate(double)\n";
}

void scale(long)
{
}

void scale(double)
{
}

int main()
{
    evaluate(4);
    evaluate(0.25);
    evaluate('a');

#ifdef TRY_AMBIGUOUS
    scale(2);
#endif
}
