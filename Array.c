#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

//mang bat ky vd arr[] = {1, 7, 8, 2, 3, 8, 3, 7, 6, 7, 8, 8, 2}
// sap xep mang theo thu tu tang dan
// liet ke cac phan tu co so lan xuat hien vd: 1 xuat hien 1 lan
//                                             7 xuat hien 2 lan
//                                             8 xuat hien 3 lan

typedef struct{
    uint8_t size;
    uint8_t *firstAdd;
}typeArray;

int randomA(int minN, int maxN){
 return minN + rand() % (maxN + 1 - minN);
}

void randomArray(typeArray *value, uint8_t length){
    srand((int)time(0));

    value->size = length;

    value->firstAdd = (uint8_t *)malloc(sizeof(uint8_t)*value->size);
    int r;
    for(int i = 0; i < value->size; i++){
        value->firstAdd[i] = randomA(0,10);
    }    
}

void sortArray(typeArray *arr){
    for(int i=0;i<(arr->size)-1;i++)
    {
        for(int j=i+1;j<(arr->size);j++)
        {
            uint8_t tg=0;
            if(arr->firstAdd[i]>arr->firstAdd[j])
            {
                tg=arr->firstAdd[i];
                arr->firstAdd[i]=arr->firstAdd[j];
                arr->firstAdd[j]=tg;
            }
        }
    }
    
}
void countArray(typeArray *arr){
    int count =1;
    int i;
    printf("Dem Cach1:\n");
    for (i = arr->size-1; i > 0; --i) {
        //printf("Phan tu %d",array[i-1]);
        if (arr->firstAdd[i] == arr->firstAdd[i-1]) ++count; //Tìm thấy phần tử trùng nhau
        else{
             printf("Phan tu %d xuat hien %d lan\n",arr->firstAdd[i], count);
             count = 1;
        }
        
    }
   printf("Phan tu %d xuat hien %d lan\n",arr->firstAdd[i], count);
    
}
void countArray2(typeArray *arr){
    printf("demCach2\n");
int dem=1;
int static i;

for (i = 0; i < arr->size - 1; ++i) {
        for (int j=i+1; j < arr->size; ++j) {
            if (arr->firstAdd[i] == arr->firstAdd[j]) {
                dem++;
            break;
            }
             else{
             printf("Phan tu %d xuat hien %d lan\n",arr->firstAdd[i], dem);
             dem = 1;
             break;
            }   
        }
     }
     printf("Phan tu %d xuat hien %d lan\n",arr->firstAdd[i], dem);
    
}

int main(int argc, char const *argv[])
{
    typeArray arr;

    randomArray(&arr, 20);
    sortArray(&arr);

    for (int i = 0; i < arr.size; i++)
    {
        printf("arr[%d] = %d\n",i, arr.firstAdd[i]);
    }
    
    countArray(&arr);
    countArray2(&arr);
    return 0;
}
