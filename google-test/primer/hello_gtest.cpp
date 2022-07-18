#include <gtest/gtest.h>
#include "hello_world.h"

namespace {
    TEST(HellowGtest, ReturnsHelloWorld) {
        EXPECT_EQ(hello_world(), "Hello World!");
    }
}
