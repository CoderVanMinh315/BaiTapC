#include <stdio.h>

char arr[] = "The Grammy award-winning singer. Who has been less active on digital platforms in recent weeks. Explained her decision to distance herself from social media platforms during an appearance on the Conan OBrien Needs a Friend podcast, alongside her brother Finneas";

//Cau 1: Viet mot chuyen dao nguoc VD: "Finneas brother her alongside .... Grammy The"
//cau 2: In Hoa chu cai dau tien sau dau cham
//Cau 3: Chuyen doi tat ca doan van thanh chu thuong
//Cau 4: Chuyen doi tat ca doan van thanh chu hoa
int string_length(char arr[])  // tim kich thuoc cua mang
 {
    int i = 0;

    while (arr[i] != NULL)
   {
        i++;
   }
    return i;
}


/**
 * ham dao nguoc chuoi
 */
void string_reverse(char arr[])
 {
    int i, j;
    char temp;

    j = string_length(arr) - 1;
    i = 0;

    while (i < j) {
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
        i++;
        j--;
    }
}

void INHOA (char arr[])
{
  int length=string_length(arr);
  printf("\n\n In hoa sau dau cham\n");
  for (int i = 0; i < length; i++)
  {
    if(arr[i-2]=='.' && arr[i]>='a') // phan tu sau dau cham
    {
        printf("%c",arr[i]-32);
       
    }else
    {
    printf("%c",arr[i]);
    }
  }
  
}


void CHU_THUONG (char arr[])  // in ra toan bo chu viet thuong
{
  int length=string_length(arr);
  printf(" \n\nIn ra chu in thuong \n");
   for (int i = 0; i < length; i++)
   {
    if(arr[i]>='a' || arr[i]==' ' || arr[i]=='.' ) // a==97 va phim cach 32
    {
        printf("%c",arr[i]);
    }
    else{
        printf("%c",arr[i]+32);  // 32 la khoang cach tu in hoa den in thuong
    }
   } 
}

void CHU_HOA (char arr[])  // in ra toan bo chu viet hoa
{
  int length=string_length(arr);
  printf(" \n\n In ra chu in hoa \n");
   for (int i = 0; i < length; i++)
   {
    if(arr[i]<='Z' || arr[i]==' ' ) // a==97 va phim cach 32
    {
        printf("%c",arr[i]);
    }
    else{
        printf("%c",arr[i]-32);  // 32 la khoang cach tu in hoa den in hoa
    }
   } 
}


int main(int argc, char const *argv[])
{
   printf("Chuoi ban dau:\n %s", arr);
  
char reverse[100] = "";
    char temp[50];
    int i, j, n;
    n = string_length(arr);

    printf("\n\nChuoi sau khi da duoc dao nguoc:\n");

    for (i = n - 1; i >= 0; --i) {

        for (j = 0; i >= 0 && arr[i] != ' '; --i, ++j)
        {
            temp[j] = arr[i];
        }
        temp[j] = '\0';
        string_reverse(temp);
        printf("%s ", temp);
    }

    INHOA(arr);

    CHU_THUONG(arr);

    CHU_HOA(arr);
    
    return 0;
}
