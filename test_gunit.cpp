#include <GUnit.h>
#include <stdexcept>

class Calc {
    public:
    int add(int a, int b) { return a + b;}
    int div(int a, int b) {
        if (b == 0) throw std::runtime_error("Division by 0");
        return a/b;
    }
};


GTEST("Calc Test") {
    Calc calc{};

    SHOULD("return sum of 2 numbers") {
            EXPECT_EQ(5, calc.add(4, 1));
    }
    SHOULD("throw if division by 0") {
            EXPECT_ANY_THROW(calc.div(42, 0));
    }
}
