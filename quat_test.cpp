#include "quat.hpp"


int main(int argc, char* argv[])
{
    quat<float> q1{0.0f, 1.0f, 2.0f, 3.0f};
    std::cout << "q1: " << q1 << '\n';

    quat<float> q2{0.0f, 4.0f, 5.0f, 6.0f};
    std::cout << "q2: " << q2 << '\n';

    std::cout << "q1 + q2 = " << (q1 + q2) << '\n';
    std::cout << "q2 - q1 = " << (q2 - q1) << '\n';

    quat<float> q3 = q1*q2;
    std::cout << "q3: q1 * q2 = " << q3 << '\n';
    std::cout << "negate(q3)    = " << (-q3) << '\n';
    std::cout << "conjugate(q3) = " << (conjugate(q3)) << '\n';

    quat<float> q4{0.0f, 1.0f, 0.0f, 0.0f};
    std::cout << "q4: " << q4 << '\n';
    std::cout << "magnitude(q4) = " << magnitude(q4) << '\n';
    std::cout << "inverse(q4)   = " << inverse(q4) << '\n';
    std::cout << "magnitude(inverse(q4)) = " << magnitude(inverse(q4)) << '\n';
    std::cout << "conjugate(q4) = " << conjugate(q4) << '\n';

    quat<double> q5{27.0, -5.2, 3.88, 1.9};
    quat<double> q5_inv = inverse(q5);
    std::cout << "q5: " << q5 << '\n';
    std::cout << "inverse(q5) = " << q5_inv << '\n';
    std::cout << "q5*inverse(q5) = " << (q5*q5_inv) << '\n';
    std::cout << "inverse(q5)*q5 = " << (q5_inv*q5) << '\n';
    std::cout << "magnitude(q5*inverse(q5)) = " << magnitude(q5*q5_inv) << '\n';
    std::cout << "magnitude(inverse(q5)*q5) = " << magnitude(q5_inv*q5) << '\n';

    return 0;
}
