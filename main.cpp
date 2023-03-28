#include<stdio.h>
namespace ConOngA{
    class ChauOngA{
        public:
          void hien(){
            printf("Hello\n");
          }
    };
}

int main(int argc, char const *argv[])
{
    ConOngA::ChauOngA conchau;
    conchau.hien();


    return 0;
}
