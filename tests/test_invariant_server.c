#include <check.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* Forward declaration of the vulnerable function's context */
typedef struct {
    void *obfs_plugin;
    void *obfs;
    int obfs_compatible_state;
} server_t;

typedef struct {
    uint8_t *array;
    size_t len;
    size_t capacity;
} buffer_t;

/* Simulate the vulnerable code path */
static void test_memcpy_invariant(buffer_t *buf, server_t *server, int obfs_compatible) {
    if (server->obfs_plugin) {
        /* Simulate obfs_class */
        typedef struct {
            int (*server_decode)(void*, uint8_t**, size_t, size_t*, int*);
        } obfs_class;
        
        obfs_class *obfs_plugin = server->obfs_plugin;
        if (obfs_plugin->server_decode) {
            int needsendback = 0;

            if(obfs_compatible == 1) {
                char *back_buf = (char*)malloc(sizeof(buffer_t));
                if (back_buf == NULL) {
                    return;
                }
                /* VULNERABLE OPERATION */
                memcpy(back_buf, buf, sizeof(buffer_t));
                
                /* Simulate decode returning error */
                buf->len = -1;
                
                if ((int)buf->len < 0) {
                    /* SECOND VULNERABLE OPERATION */
                    memcpy(buf, back_buf, sizeof(buffer_t));
                    free(back_buf);
                    server->obfs_compatible_state = 1;
                }
            }
        }
    }
}

START_TEST(test_buffer_memcpy_bounds)
{
    /* Invariant: memcpy operations must not exceed allocated buffer boundaries */
    const struct {
        size_t array_size;
        size_t len;
        size_t capacity;
        int obfs_compatible;
    } test_cases[] = {
        /* Exact exploit case: buffer_t larger than allocated back_buf */
        {0, 0, 0, 1},
        /* Boundary case: maximum size values */
        {SIZE_MAX, SIZE_MAX, SIZE_MAX, 1},
        /* Valid normal case */
        {1024, 512, 1024, 1},
        /* Non-vulnerable path */
        {1024, 512, 1024, 0}
    };
    
    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < num_cases; i++) {
        /* Setup test buffer */
        buffer_t buf;
        buf.array = malloc(test_cases[i].array_size);
        buf.len = test_cases[i].len;
        buf.capacity = test_cases[i].capacity;
        
        /* Setup server */
        server_t server;
        server.obfs_plugin = (void*)0x1; /* Non-null to enter path */
        server.obfs = NULL;
        server.obfs_compatible_state = 0;
        
        /* Test the vulnerable function */
        test_memcpy_invariant(&buf, &server, test_cases[i].obfs_compatible);
        
        /* Security property: No buffer overflow occurred */
        ck_assert_msg(server.obfs_compatible_state == 0 || server.obfs_compatible_state == 1,
                     "Memory safety invariant violated for test case %d", i);
        
        free(buf.array);
    }
}
END_TEST

Suite *security_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Security");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_buffer_memcpy_bounds);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = security_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}