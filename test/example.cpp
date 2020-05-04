#include <gtest/gtest.h>

extern "C" {
#include "dp3t.h"
}

TEST(version, ok) {
  ASSERT_EQ(version(), 0x3);
}
