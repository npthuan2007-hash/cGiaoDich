#include "GiaoDich.h"
#include <string>
#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

GiaoDich:: GiaoDich() {
    maGD = ngay = thang = nam = donGia = dienTich = 0;
}
GiaoDich:: GiaoDich(int maGD, int ngay, int thang, int nam, long double donGia, double dienTich) {
    this-> maGD = maGD;
    this-> ngay = ngay;
    this->thang = thang;
    this->nam = nam;
    this-> donGia = donGia;
    this->dienTich = dienTich;
}
GiaoDich::~GiaoDich() {

}
int GiaoDich:: getNam() {
    return this->nam;
}
int GiaoDich:: getThang() {
    return this-> thang;
}
void GiaoDich:: nhap() {
    cout << "Nhap ma giao dich: "; cin >> maGD; cout << '\n';
    cout << "Nhap ngay thang nam giao dich (dd/mm/yy): "; cin >> ngay >> thang >> nam; cout << '\n';
    cout << "Nhap don gia: "; cin >> donGia; cout << '\n';
    cout << "Nhap dien tich: "; cin >> dienTich; cout << '\n';
}
void GiaoDich::xuat() {
    cout << "Ma giao dich: " << maGD << ". Ngay giao dich: " << ngay << "/" << thang << '/' << nam << ". Don gia " << donGia << ". Dien tich: " <<  dienTich << ".";
}
long double GiaoDich:: getDonGia() {
    return this->donGia;
}
void GDDat:: nhap() {
    GiaoDich::nhap();
    cout << "Nhap loai dat: ";
    cin >> loaiDat;
}
void GDDat:: xuat() {
    GiaoDich:: xuat();
    cout << " Loai dat: " << loaiDat << fixed << setprecision(0) << ". Thanh tien: " << tinhGia() << '\n';
}
long double GDDat:: tinhGia() {
    if (loaiDat == 'B' || loaiDat == 'C') {
        return dienTich * donGia;
    }
    return dienTich * donGia * 1.5;
}
char GDDat:: getLoaiDat() {
    return this-> loaiDat;
}
void GDNhaPho:: nhap() {
    GiaoDich::nhap();
    cout << "Nhap dia chi nha: ";
    cin.ignore();
    getline(cin, diaChi);
    cout << "Nhap loai nha: ";
    getline(cin, loaiNha);

}
void GDNhaPho:: xuat() {
    GiaoDich:: xuat();
    cout << " Loai nha (cao cap, thuong): " << loaiNha << ". Dia chi: " << diaChi << fixed << setprecision(0)  << ". Thanh tien: " << tinhGia() << '\n';
}
string GDNhaPho:: getLoaiNha() {
    return this->getLoaiNha();
}
long double GDNhaPho:: tinhGia() {
    if (loaiNha == "cao cap") {
        return dienTich * donGia;
    }
    return dienTich * donGia * 0.9;
}
void GDCanHo:: nhap() {
    GiaoDich:: nhap();
    cout << "Nhap ma can ho: ";
    cin >> maCan;
    cout << '\n';
    cout << "Nhap vi tri tang: ";
    cin >> viTriTang;
    cout << '\n';
}
void GDCanHo:: xuat() {
    GiaoDich:: xuat();
    cout << " Ma can ho: " << maCan << ". Vi tri tang: " << viTriTang << fixed << setprecision(0)  << ". Thanh tien: " << tinhGia() << '\n';
}
long double GDCanHo:: tinhGia() {
    if (viTriTang == 1) return dienTich * donGia * 2;
    else if (viTriTang >= 15) return dienTich * donGia * 1.2;
    else return dienTich * donGia;
}