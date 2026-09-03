#include "state.hpp"
#include "timed_state.hpp"
#include "trajectory.hpp"

#include <cassert>
#include <cmath>
#include <iostream>
#include <stdexcept>

namespace {
void inspect(State state)
{
    state[0] = -1.0;
}
}

int main()
{
    State a{3};
    a[0] = 4.0;
    State b{a};
    b[0] = 9.0;
    assert(a[0] == 4.0 && b[0] == 9.0);

    TimedState u{3, 1.0};
    u[0] = 3.0;
    u[1] = 4.0;
    assert(l2_norm(u) == 5.0);
    const State& view{u};
    assert(l2_norm(view) == 5.0);
    scale(u, 2.0);
    assert(l2_norm(u) == 10.0 && u.time() == 1.0);

    State snapshot{u};
    snapshot[0] = 99.0;
    assert(u[0] == 6.0);
    inspect(u);
    assert(u[0] == 6.0);

    Trajectory trajectory;
    trajectory.append(TimedState{2, 0.0});
    trajectory.append(TimedState{2, 0.5});
    trajectory.append(TimedState{2, 1.0});
    assert(trajectory.size() == 3);

    bool rejected{};
    try {
        trajectory.append(TimedState{2, 0.75});
    } catch (const std::invalid_argument&) {
        rejected = true;
    }
    assert(rejected);

    std::cout << "session 5: OK\n";
}
