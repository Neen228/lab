#include "compars.h"


int cmp_mile(const Car *car1, const Car  *car2) {
    return car1->mileage - car2->mileage;
}


int cmp_mile_rev(const Car *car1, const Car *car2) {
    return car2->mileage - car1->mileage;
}


int cmp_name(const Car *car1, const Car  *car2) {
    return strcmp(car1->name, car2->name);
}


int cmp_name_rev(const Car *car1, const Car  *car2) {
    return -strcmp(car1->name, car2->name);
}

int cmp_brand(const Car *car1, const Car *car2) {
    return strcmp(car1->brand, car2->brand);
}

int cmp_brand_rev(const Car *car1, const Car *car2) {
    return -strcmp(car1->brand, car2->brand);
}
