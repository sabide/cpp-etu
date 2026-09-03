#include "../int_array.hpp"

int main()
{
    IntArray values{8};
    values.size_ = 12; // erreur attendue : size_ est privé
}
