#include <stdio.h>
#include <stdlib.h>
#include <mosquitto.h>
#include <stdbool.h>

int main() {
    struct mosquitto *mosq;
    int res = mosquitto_lib_init();

    char c;
    float f;

    bool check;

    if (res == MOSQ_ERR_SUCCESS) printf("Success!\n");
    else printf("Failed...\n");

    mosq = mosquitto_new(NULL, true, NULL);

    //Function returns NULL if there is no memory
    if (mosq == NULL)
    {
        fprintf(stderr, "Error: Out of memory.\n");
        return EXIT_FAILURE;
    }

    res = mosquitto_connect(mosq, "34.53.99.185", 1883, 60);

    if (res != MOSQ_ERR_SUCCESS)
    {
        mosquitto_destroy(mosq);

        fprintf(stderr, "There was an error with connecting! %s\n", mosquitto_strerror(res));

        return EXIT_FAILURE;
    }

    res = mosquitto_loop_start(mosq);

    if (res != MOSQ_ERR_SUCCESS)
    {
        mosquitto_destroy(mosq);

        fprintf(stderr, "There was an error with the loop starting! %s\n", mosquitto_strerror(res));

        return EXIT_FAILURE;
    }

    while (true)
    {
        //Get input
        c = getchar();

        check = ((c == '1') || (c == '2') || (c == '3'));
        
        if (check) mosquitto_publish(mosq, NULL, "inTopic", 1, &c, 2, false);

        if (c == '3') break;
    }


    
    return EXIT_SUCCESS;
}
