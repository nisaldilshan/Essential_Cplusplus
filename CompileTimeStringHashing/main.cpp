#include <cstdint>
#include <iostream>

// FNV-1a 32bit hashing algorithm.
constexpr uint32_t fnv1a_32(char const* s, size_t count)
{
    return ((count ? fnv1a_32(s, count - 1) : 2166136261u) ^ s[count]) * 16777619u;
}

constexpr uint32_t operator"" _hash(char const* s, size_t count)
{
    return fnv1a_32(s, count);
}

int main()
{
    constexpr uint32_t check1 = "0123456789ABCDEF"_hash;
    constexpr uint32_t check2 = "NisalDilshan"_hash;
    // Compare against precomputed value.
    static_assert(check1 == 141695047, "bad hash value");
    static_assert(check2 == 1837667451, "bad hash value");
    return 0;
}