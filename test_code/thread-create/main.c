#include <stdio.h>
//#include <unistd.h>

#include <uv.h>

void hare(void *arg) {
    int tracklen = *((int *) arg);
    while (tracklen) {
        tracklen--;
#ifdef _MSC_VER
        Sleep(1000);
#else
        sleep(1);
#endif
        fprintf(stderr, "Hare ran another step\n");
    }
    fprintf(stderr, "Hare done running!\n");
}

void tortoise(void *arg) {
    int tracklen = *((int *) arg);
    while (tracklen) {
        tracklen--;
        fprintf(stderr, "Tortoise ran another step\n");
#ifdef _MSC_VER
        Sleep(1000);
#else
        sleep(1);
#endif
    }
    fprintf(stderr, "Tortoise done running!\n");
}

int main() {
    int tracklen = 10;
    uv_thread_t hare_id;
    uv_thread_t tortoise_id;
    uv_thread_create(&hare_id, hare, &tracklen);
    uv_thread_create(&tortoise_id, tortoise, &tracklen);

    uv_thread_join(&hare_id);
    uv_thread_join(&tortoise_id);
    return 0;
}
