#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


//nhap vao 1 so tu ban phim toi da 7 chu so
uint32_t number;
uint8_t ktra_zero = 0;

void printNum(uint8_t num, uint8_t vitri){
    switch (num)
    {
    case 0:
        if(vitri % 3 == 1) printf("LINH "); //HANG CHUC
        else printf("KHONG ");
        break;
    case 1:
        if(vitri % 3 != 1) printf("MOT ");
        break;
    case 2:
        printf("HAI ");
        break;
    case 3:
        printf("BA ");
        break;
    case 4:
        printf("BON ");
        break;
    case 5:
        if((vitri % 3 == 0) && ktra_zero == 0) printf("LAM "); //Check dung truoc la 0
        else printf("NAM ");
        break;
    case 6:
        printf("SAU ");
        break;
    case 7:
        printf("BAY ");
        break;
    case 8:
        printf("TAM ");
        break;
    case 9:
        printf("CHIN ");
        break;
    
    default:
        break;
    }
}

void printUnit(uint8_t num, uint8_t vitri){
    switch (vitri % 3)
    {
    case 2:
        /* code */
        printf("TRAM ");
        break;

    case 1:
        /* code */
        if(num != 0) printf("MUOI "); //Check chuc bang 0
        break;

    case 0:
        if(vitri / 3 == 1) printf("NGHIN ");
        else if(vitri / 3 == 2) printf("TRIEU ");
        break;

    default:
        break;
    }
}

void readNumber(uint32_t num){
    uint8_t size = 1;
    uint8_t *ptr = (uint8_t *)malloc(size*sizeof(uint8_t));
    uint8_t check_first = 0;

    while(1){
        *(ptr + size - 1) = num % 10;
        num /= 10;
        if(num == 0) break;
        ++size;
        realloc(ptr, size*sizeof(uint8_t)); 
    }

    for(int i=size-1; i>=0; i--)
    {
        if(check_first > 0){
            if(*(ptr+i) == 0) 
            {
                ktra_zero = 1;
                uint8_t tam = check_first / 3 * 3;
                if(i == tam) printUnit(*(ptr+i), i);
                continue;
            }
            else
            {
                if(ktra_zero == 1)
                {
                    printNum(*(ptr+i+1), i+1);
                    printUnit(*(ptr+i+1), i+1);  
                }
                printNum(*(ptr+i), i);
                printUnit(*(ptr+i), i);
                ktra_zero = 0;
                continue;
            }
            
        }
        if(*(ptr+i) == 0 && check_first == 0) continue;
        else
        {
            if(i % 3 != 1) printNum(*(ptr+i), i); //Chuc va chuc nghin
            printUnit(*(ptr+i), i);
            check_first = i;
        }
    }

    if(check_first == 0) printf("KHONG");
    free(ptr);
}

int main(int argc, char const *argv[])
{
    /* code */
    printf("Nhap mot so: ");
    scanf("%lu", &number);
    printf("So duoc nhap: %lu\n", number);
    readNumber(number);
    return 0;
}
