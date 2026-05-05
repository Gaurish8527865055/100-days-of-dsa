#include <stdlib.h>

typedef struct {
    int pos;
    double time;
} Car;

// Sort by position in descending order
int cmp(const void* a, const void* b) {
    Car* x = (Car*)a;
    Car* y = (Car*)b;
    return y->pos - x->pos;
}

int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {
    
    // Step 1: create car array
    Car* cars = (Car*)malloc(sizeof(Car) * positionSize);

    for (int i = 0; i < positionSize; i++) {
        cars[i].pos = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    // Step 2: sort by position (descending)
    qsort(cars, positionSize, sizeof(Car), cmp);

    // Step 3: count fleets
    int fleets = 0;
    double prevTime = 0.0;

    for (int i = 0; i < positionSize; i++) {
        if (cars[i].time > prevTime) {
            fleets++;
            prevTime = cars[i].time;
        }
    }

    free(cars);
    return fleets;
}