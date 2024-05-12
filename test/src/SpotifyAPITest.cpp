#include "shelljam/SpotifyAPI.hpp"
#include <gtest/gtest.h>

class SpotifyAPITest : public testing::Test {
  protected:
    SpotifyAPITest() : m_testObj{} {}
    SpotifyAPI m_testObj;
};

TEST_F(SpotifyAPITest, requestUserAuthorization_ReturnsToken) {
    EXPECT_TRUE(m_testObj.requestUserAuthorization());
}