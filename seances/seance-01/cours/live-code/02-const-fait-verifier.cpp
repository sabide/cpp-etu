#include <iostream>

int main()
{
    const double reference_temperature{293.15};
    std::cout << reference_temperature << '\n';

#ifdef TRY_MODIFY_CONST
    reference_temperature = 300.0;
#endif
}
