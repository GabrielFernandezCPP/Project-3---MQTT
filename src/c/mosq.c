#include <stdio.h>
#include <mosquitto.h>

int main() {
    int res = mosquitto_lib_init();

    if (res == MOSQ_ERR_SUCCESS) printf("Success!");
    else printf("Failed...");
    
    return 0;
}