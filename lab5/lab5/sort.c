#include "sort.h"

int bin_search(Car *cars, Car *item, int low, int high, int(*compar)(const Car *, const Car *)) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (compar(item, &cars[mid]) == 0)
            return mid + 1;
        else 
            if (compar(item, &cars[mid]) > 0)
                low = mid + 1;
            else
                high = mid - 1;
    }
    return low;
}
  
void ins_sort(Car *cars, int len, int(*compar)(const Car *, const Car*)) {
    int  place, j;
    Car item ;
    for (int i = 1; i < len; ++i) {
        j = i - 1;
        item = cars[i];
          place = bin_search(cars, &item, 0, j, compar);
        while (j >= place) {
            cars[j + 1] = cars[j];
            j--;
        }
        cars[j + 1] = item;
    }
}



void comb_sort(Car *cars, int len, int(*compar)(const Car *, const Car *)) {	
    Car tmp;
	int s = len, k; 
	while(len > 1) {
		s /= 1.247f; 
        if (s < 1) 
            s = 1;
		k = 0; 
		for (int i = 0; i + s < len; ++i) { 
			if (compar(&cars[i], &cars[i + s])) {
				tmp = cars[i];
				cars[i] = cars[i + s];
				cars[i + s] = tmp; 	
				k = i;
			}
		}
		if (s == 1) 
			len = k + 1; 
	}
}
