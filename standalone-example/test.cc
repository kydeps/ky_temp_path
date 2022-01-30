#include <iostream>
#include <filesystem>

#include <ky/temp_path.h>

#define CHECK(X) std::cout << #X << " = " << (X) << std::endl;

int main(int argc, char **argv) {
    std::filesystem::path s1, s2;

    {
        ky::TempPath p1, p2;
        s1 = p1.GetPath();
        s2 = p2.GetPath();

        CHECK(s1 != s2);
    }

    CHECK(!std::filesystem::exists(s1));
    CHECK(!std::filesystem::exists(s2));
}
