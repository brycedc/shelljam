#include <gtest/gtest.h>

// File being tested
#include "shelljam/CurlUtil.hpp"

class CurlUtilTest : public testing::Test {
  protected:

};
    

TEST(CurlUtilTesting, encodedURL_ReturnsEncodedString) {
    std::string expectedResult{};
    EXPECT_EQ(expectedResult, CurlUtil::instance().encodeURL("Test"));
}
