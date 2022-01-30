#include <gtest/gtest.h>

#include <ky/temp_path.h>

TEST(temp_path, test1) {
    std::filesystem::path s1, s2;

    {
        ky::TempPath p1, p2;
        s1 = p1.GetPath();
        s2 = p2.GetPath();

        ASSERT_NE(s1, s2);
    }

    ASSERT_FALSE(std::filesystem::exists(s1));
    ASSERT_FALSE(std::filesystem::exists(s2));
}