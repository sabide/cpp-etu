#include "state.hpp"
#include "timed_state.hpp"

#include <iostream>

int main()
{
    State state{3};
    state[0] = 1.0;
    state[1] = 2.0;
    state[2] = 2.0;

    TimedState timed{3, 0.25};
    timed[0] = 3.0;
    timed[1] = 4.0;

    const State& view{timed};
    State copy{timed};

    std::cout << "||state|| = " << l2_norm(state) << '\n'
              << "||view|| = " << l2_norm(view) << '\n'
              << "||copy|| = " << l2_norm(copy) << '\n'
              << "time(timed) = " << timed.time() << '\n';
}
