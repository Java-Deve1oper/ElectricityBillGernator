/**
 * Write a program to calculate electricity bill value
 * by using following information :-
 * 1) Serial number considered as = 4235 
 * 2) Tariff data  1 -  50   1.75
 *                51 - 150   3.75
 *               151 - 250   5.00
 *                  >= 251   6.50
 * 3) Previous Reading value is 1234
 * 4) Min charge amt. is 40rs
 * 5) Service tax needed to applied to 12.45%
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int Sno, Cur_read, Pre_read = 1234, nUnits, t;
    float rps;
    printf(" Please ! Enter your serial number --> ");
    scanf("%d", &Sno);

    if (Sno == 4321)
    {
        printf("Please !! Enter your current reading --> ");
        scanf("%d", &Cur_read);
        if (Cur_read >= Pre_read) // Compare previous reading to Current reading
        {
            nUnits = Cur_read - Pre_read; // Number of Units
            if (nUnits > 251)   // > 251 
            {
                t = nUnits - 250;
                rps = t * 6.50;
                rps = rps + 100 * 5.00;
                rps = rps + 100 * 3.75;
                rps = rps + 100 * 1.75;
            }
            else if (nUnits >= 151) // >= 151
            {
                t = nUnits - 150;
                rps = t * 5.00;
                rps = rps + 100 * 3.75;
                rps = rps + 100 * 1.75;
            }
            else if (nUnits >= 51)// >= 51
            {
                t = nUnits - 50;
                rps = t * 3.75;
                rps = rps + 100 * 1.75;
            }
            else
            {
                rps = rps * 1.75;
                if (rps < 40)  //Minimum Amount
                    rps = 40 ;
            }

            rps = rps + (rps * 12.36 / 100);  
            printf("Total Amount : %.2f\n ", rps); // Print the final amount
        }
        else // If reading is not currect then this part is execute 
        {
            printf("Invalid Current Reading value ");
        }
    }
    else  // If serial number is not matched then this part is execute 
    {
        printf("Invalid Serial No. ");
    }

    return 0;
}
