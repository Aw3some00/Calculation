#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "calc.h"

TEST_SUITE_BEGIN("calc");

TEST_CASE("Testing borders") {
    CHECK_THROWS_WITH(input_func({"222222222*2222222222222222"}), "число слишком большое или слишком маленькое");
    CHECK_THROWS_WITH(input_func({"222*0.0000000000000000001"}), "число слишком большое или слишком маленькое");
    CHECK_THROWS_WITH(input_func({"2222222222222*222222222222"}), "число слишком большое или слишком маленькое");
    CHECK_THROWS_WITH(input_func({"1/222222222222222222222222222222"}), "число слишком большое или слишком маленькое");
    CHECK_THROWS(input_func({"9999999-99999999999999999999999999999999999999999"}));
    CHECK_THROWS(input_func({"9999999+99999999999999999999999999999999999999999"}));
}

TEST_CASE("Testing input") {
    CHECK_THROWS_WITH(input_func("либо слишком большое либо слишком маленькое"), "некорректный ввод");
    CHECK_THROWS_WITH(input_func("abc+123"),"некорректный ввод");
    CHECK_THROWS_WITH(input_func("123++456"), "некорректный ввод");
    CHECK_THROWS_WITH(input_func("123/"), "некорректный ввод");
    CHECK_THROWS_WITH(input_func("либо слишком большое либо слишком маленькое"), "некорректный ввод");
    CHECK_THROWS_WITH(input_func(""), "некорректный ввод");
    CHECK_THROWS_WITH(input_func("123 + + 456"), "некорректный ввод");
    CHECK_THROWS_WITH(input_func("12+*56"), "некорректный ввод");
}

TEST_CASE("Testing valid calculations") {
    CHECK(calculate({"123", "+", "456"}) == 579);
    CHECK(calculate({"123", "-", "23"}) == 100);
    CHECK(calculate({"12", "*", "10"}) == 120);
    CHECK(calculate({"120", "/", "10"}) == 12);
}

TEST_CASE("Testing edge cases") {
    CHECK(calculate({"0", "+", "0"}) == 0);
    CHECK(calculate({"-1", "+", "1"}) == 0);
    CHECK(calculate({"-1", "-", "1"}) == -2);
    CHECK(calculate({"1", "*", "0"}) == 0);
    CHECK(calculate({"1", "/", "1"}) == 1);
    CHECK_THROWS_WITH(calculate({"1", "/", "0"}), "деление на ноль");
}

TEST_SUITE_END();