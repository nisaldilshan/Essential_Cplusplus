#define aASSERT_GLUE(a, b) a ## b
#define ASSERT_GLUE(a, b) aASSERT_GLUE(a, b)
#define STATIC_ASSERT(expr) \
    enum \
    { \
        ASSERT_GLUE(g_assert_fail_, __LINE__) \
        = 1 / (int)(!!(expr)) \
    }
STATIC_ASSERT(sizeof(int) == 4); // should pass
STATIC_ASSERT(sizeof(float) == 4); // should pass
//STATIC_ASSERT(sizeof(float) == 1); // should fail

int main()
{
    return 0;
}
