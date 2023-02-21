#include "lab5.h"
#include "gen.h"

int main(void) {
    Car *cars = (Car *) calloc(4, sizeof(Car));
    //for (int j = 0; j < 4; j++) {
    //    for (int  i = 0; i < 4; i++) {
    //        getElem(cars, 4);
    //    }
    getElem(cars, 0);
    getElem(cars, 1);
    printf("%s\n", cars[0].name);
    printf("%s\n", cars[1].name);
    //fprint_struct(cars, 4);
    //}
}
