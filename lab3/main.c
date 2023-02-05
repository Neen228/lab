#include "lab3.h"
#include "clean.h"
#define NEW_LINE printf ("\n\n\n");


int main(void){
    int number, len = 0, *data = NULL, flag = 1, capacity;
        while (flag!=0){
	    printf("choose option:\n");
	    printf("option 1: create an array\n");
	    printf("option 2: fill an array\n");
	    printf("option 3: insert new elemnt\n");
	    printf("option 4: remove array element\n");
	    printf("option 5: delete elements whose sum of digits is equal to the entered number\n");
	    printf("option 6: print an array\n");
	    printf("option 7: clear console\n");
	    printf("option 8: change array capacity\n");
	    printf("input another integer number to stop\n");
    	if (scaner_int(&number, data)) {
            printf("option must be integer number\n");
            NEW_LINE
            continue;
        }
        else {
    	    switch (number) {
    		    case 1:
    			    create_array (&data, &capacity);
    			    NEW_LINE
                    break;
                case 2:
            	    enter_array (data, &len, capacity);
            	    NEW_LINE
            	    	break;
                case 3:
                    enter_elem (data, &len, capacity);
                    NEW_LINE
                    break;
                case 4:
                    remove_elem (data, &len);                
                    NEW_LINE
                    break;
                case 5:
                    remove_sum_digits(data, &len);
                    NEW_LINE
                    break;
                case 6:
                    print_array(data, len);
                    NEW_LINE
                    break;
                case 7:
                    system("clear");
                    break;
                case 8:
            	    change_capacity(&data, &capacity, &len);
            	    NEW_LINE
            	    break;
                default:
                	flag = 0;
            	    free(data);
                	break;
    	    }
        }
     }
return 0;
}

