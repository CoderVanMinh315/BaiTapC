#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<conio.h>
using namespace std;
class SinhVien
{
private:
     uint8_t id;
     char tenSinhVien[20];
     char gioiTinh[4];
     uint8_t tuoiSinhVien;
     double diemToan;
     double diemLy;
     double diemHoa;
     double diemTrungBinh;
     char hocLuc[11];
public:
     SinhVien();
     void setTenSinhVien(const char ten[]);
     void setGioiTinh(const char gioiTinh[]);
     void setTuoiSinhVien(uint8_t tuoi);
     void setDiemToan(double toan);
     void setDiemLy(double ly);
     void setDiemHoa(double hoa);

     uint8_t getID();
     char *getTenSinhVien();
     char *getGioiTinh();
     uint8_t getTuoiSinhVien();
     double getDiemToan();
     double getDiemLy();
     double getDiemHoa();
     double getDiemTrungBinh();
     char *getHocLuc();
};

void SinhVien::setTenSinhVien( const char ten[]){
    strcpy(tenSinhVien, ten);
}

char *SinhVien::getTenSinhVien(){
    return tenSinhVien;
}

void SinhVien::setGioiTinh(const char gioiTinh[]){
    if(strcmp((char *)"Nam", gioiTinh) != 0 && strcmp((char *)"Nu", gioiTinh) != 0 ){
       printf("ERROR!! Gioi tinh khong hop le\n");
    }
    else{
        strcpy(SinhVien::gioiTinh, gioiTinh);
    }
}
SinhVien::SinhVien(){
    static uint8_t id = 100;
    SinhVien::id = id;
    id++;
}
uint8_t SinhVien::getID(){
    return id;
}
char *SinhVien::getGioiTinh(){
    return SinhVien::gioiTinh;
}
void SinhVien::setTuoiSinhVien(uint8_t tuoi){
    tuoiSinhVien = tuoi;
}
uint8_t SinhVien::getTuoiSinhVien(){
    return SinhVien::tuoiSinhVien;
}
void SinhVien::setDiemToan(double toan){

     if (toan > 0 && toan <= 10.0)
    {
          SinhVien::diemToan = toan;
    }
    else
    {
        printf("ERROR!! diem khong hop le\n");
    } 
}
double SinhVien::getDiemToan(){
    return SinhVien::diemToan;
}
void SinhVien::setDiemLy(double ly){

     if (ly > 0 && ly <= 10.0)
    {
          SinhVien::diemLy = ly;
    }
    else
    {
        printf("ERROR!! diem khong hop le\n");
    } 
}
double SinhVien::getDiemLy(){
    return SinhVien::diemLy;
}

void SinhVien::setDiemHoa(double hoa){

     if (hoa > 0 && hoa <= 10.0)
    {
          SinhVien::diemHoa = hoa;
    }
    else
    {
        printf("ERROR!! diem khong hop le\n");
    } 
}
double SinhVien::getDiemHoa(){
    return SinhVien::diemHoa;
}
double SinhVien::getDiemTrungBinh(){
     SinhVien::diemTrungBinh = (diemToan + diemLy + diemHoa)/3; 
     return SinhVien::diemTrungBinh;
}
char *SinhVien::getHocLuc(){ 
    getDiemTrungBinh(); 
    if(diemTrungBinh>=8.5)
    {
        strcpy(SinhVien::hocLuc,"Gioi");
    }
    else if(diemTrungBinh >=6.5)
    {
        strcpy(SinhVien::hocLuc,"Kha");
    }
     else if(diemTrungBinh >= 5)
    {
        strcpy(SinhVien::hocLuc,"Trung Binh");
    }
     else
    {
         strcpy(SinhVien::hocLuc,"Yeu");
    }

    return SinhVien::hocLuc;   
}
class menu
{
private:
    vector<SinhVien> DatabaseSV;
public:
    void themSinhVien();
    void capNhatSV(uint8_t id);
    void xoaSV();
    void timKiemSV();
    void sapXepSV();
    void hienThiSV();
};
void menu::themSinhVien(){
    SinhVien sv;
    char ten[20];
    uint8_t tuoi;
    char gioitinh[4];
    double toan;
    double ly;
    double hoa;
    printf("Khai bao thong tin sinh vien:\n");
    printf("Nhap Ten: ");
    scanf("%s",&ten);
    sv.setTenSinhVien(ten);
    printf("Nhap Tuoi:");
    scanf("%d", &tuoi);
    sv.setTuoiSinhVien(tuoi);
    printf("Nhap Gioi Tinh:");
    scanf("%s", &gioitinh);
    sv.setGioiTinh(gioitinh);
    printf("Nhap diem Toan:");
    scanf("%lf",&toan);
    sv.setDiemToan(toan);
    printf("Nhap diem Ly:");
    scanf("%lf",&ly);
    sv.setDiemLy(ly);
    printf("Nhap diem Hoa:");
    scanf("%lf",&hoa);
    sv.setDiemHoa(hoa);
    DatabaseSV.push_back(sv);
}
void menu::hienThiSV(){
    printf("Hien thi danh sach Sinh Vien:\n");
    printf("ID\t Ten\t Tuoi\t Gioi\t Toan\t Ly\t Hoa\t TB\t Hoc Luc\t\n");
    for(SinhVien sv : DatabaseSV)
    {
        printf("%d\t %s\t %d\t %s\t %.1f\t %.1f\t %.1f\t %.1f\t %s\t\n",sv.getID(),sv.getTenSinhVien(),sv.getTuoiSinhVien(),sv.getGioiTinh(),sv.getDiemToan(),sv.getDiemLy(),sv.getDiemHoa(),sv.getDiemTrungBinh(),sv.getHocLuc());
    }
}
void menu::capNhatSV(uint8_t id){
    char ten[20];
    uint8_t tuoi;
    char gioitinh[4];
    double toan;
    double ly;
    double hoa;
    for( SinhVien sv : DatabaseSV)
     {
        if(sv.getID()==id){
            printf("Khai bao lai thong tin sinh vien:\n");
            printf("Nhap Ten moi: ");
            scanf("%s",&ten);
            sv.setTenSinhVien(ten);
            printf("Nhap Tuoi moi:");
            scanf("%d", &tuoi);
            sv.setTuoiSinhVien(tuoi);
            printf("Nhap Gioi Tinh moi:");
            scanf("%s", &gioitinh);
            sv.setGioiTinh(gioitinh);
            printf("Nhap diem Toan moi:");
            scanf("%lf",&toan);
            sv.setDiemToan(toan);
            printf("Nhap diem Ly moi:");
            scanf("%lf",&ly);
            sv.setDiemLy(ly);
            printf("Nhap diem Hoa moi:");
            scanf("%lf",&hoa);
            sv.setDiemHoa(hoa);
        }
        else{
            printf("MSV khong ton tai\n");
        }
    }

}
int main(int argc, char const *argv[])
{
    uint8_t key;
    bool daNhap = false;
    menu mn;
    //  mn.themSinhVien();
    //  mn.themSinhVien();
    //  mn.hienThiSV();
    //  mn.capNhatSV(100);
    //  mn.hienThiSV();
    while(true){
        system("cls");
        printf("******************************************\n");
        printf("**    CHUONG TRINH QUAN LY SINH VIEN    **\n");
        printf("**      1. Nhap danh sach sinh vien     **\n");
        printf("**      2. In danh sach sinh vien       **\n");
        printf("**      3. Sap xep sinh vien theo DTB   **\n");
        printf("**      4. Cap nhat sinh vien           **\n");
        printf("**      5. Xoa sinh vien                **\n");
        printf("**      6. Tim Kiem sinh vien           **\n");
        printf("**      0. Thoat                        **\n");
        printf("******************************************\n");
        printf("**       Nhap lua chon cua ban          **\n");
        scanf("%d",&key);
        switch(key){
            case 1:
                printf("Ban da chon nhap DS sinh vien!\n");
                mn.themSinhVien();
                printf("\nBan da nhap thanh cong!");
                daNhap = true;
                printf("\nBam phim bat ky de tiep tuc!");
                break;
            case 2:
                // if(daNhap){
                //     printf("\nBan da chon xuat DS sinh vien!");
                //     mn.hienThiSV();
                // }else{
                //     printf("\nNhap DS SV truoc!!!!");
                // }
                mn.hienThiSV();
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 3:
                if(daNhap){
                    printf("\nBan da chon sap xep SV theo STB!");
                    // sapxep(a, n);
                    // xuatN(a, n);
                }else{
                    printf("\nNhap DS SV truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 4:
                uint8_t id;
                printf("Ban da chon cap nhat thong tin SV!\n");
                printf("Nhap ma sinh vien can sua:");
                scanf("%d",&id);
                mn.capNhatSV(id);
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 5:
                if(daNhap){
                    printf("\nBan da chon xuat DS SV!");
                    // xuatFile(a, n, fileName);
                }else{
                    printf("\nNhap DS SV truoc!!!!");
                }
                // printf("\nXuat DSSV thanh cong vao file %s!", fileName);
                printf("\nBam phim bat ky de tiep tuc!");
                // getch();
                break;
            case 6:
                break;    
            case 0:
                printf("\nBan da chon thoat chuong trinh!");
                getch();
                break;
            default:
                printf("\nKhong co chuc nang nay!");
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
        }
    }
    // double a ;
    // double b ;
    // double c;
    // scanf("%lf",&a);
    // scanf("%lf",&b);
    // scanf("%lf",&c);

    // SinhVien sv;
    // sv.setDiemToan(a);
    // sv.setDiemLy(b);
    // sv.setDiemHoa(c);
    // printf("Diem Toan %.1f || Diem Ly: %.1f  ||Diem Hoa : %.1f || Diem TB: %.1f ||Hoc Luc: %s \n",sv.getDiemToan(),sv.getDiemLy(),sv.getDiemHoa(),sv.getDiemTrungBinh(),sv.getHocLuc());
    return 0;
}


