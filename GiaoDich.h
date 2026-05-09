#ifndef GIAODICH_H
#define GIAODICH_H

#include <string.h>
#include <string>

using namespace std;


class GiaoDich{
protected: 
    int maGD;
    int ngay, thang, nam;
    long double donGia;
    double dienTich;
public: 
    GiaoDich();
    GiaoDich(int, int, int , int, long double, double);
    virtual ~GiaoDich(); 
    virtual void nhap();
    virtual void xuat();
    long double getDonGia();
    virtual long double tinhGia() = 0; 
    int getThang();
    int getNam();
};

class GDDat: public GiaoDich {
private:
    char loaiDat;
public:
    void nhap() override;
    void xuat() override;
    long double tinhGia() override;
    char getLoaiDat();
};

class GDNhaPho: public GiaoDich {
private:
    string diaChi, loaiNha;
public: 
    void nhap() override;
    void xuat() override;
    string getLoaiNha();
    long double tinhGia() override;
};

class GDCanHo: public GiaoDich{
private: 
    int maCan;
    int viTriTang;
public:
    void nhap() override;
    void xuat() override;
    string getViTriTang();
    long double tinhGia() override;    
};

#endif