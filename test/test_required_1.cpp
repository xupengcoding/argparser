#include <catch.hpp>

#include <argparser.hpp>

TEST_CASE("Test required args", "[required]") {
    constexpr int argc = 1;
    const char* argv[argc] = {
        "test.exe"
    };

    ap::parser p(argc, const_cast<char**>(argv));
    REQUIRE(p.add("-n", "--name", "My name", ap::mode::REQUIRED));
    
    REQUIRE(!p.parse().parsed_successfully());
}
