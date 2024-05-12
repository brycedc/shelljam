#include <gtest/gtest.h>

// File being tested
#include "shelljam/CurlUtil.hpp"

class CurlUtilTest : public testing::Test {
  protected:

};
    

TEST(CurlUtilTesting, encodedURL_ReturnsEncodedString) {
    std::string expectedResult{"https%3A%2F%2Fexample.com"};
    EXPECT_EQ(expectedResult, CurlUtil::instance().encodeURL("https://example.com"));
}
