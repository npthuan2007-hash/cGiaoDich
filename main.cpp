#include "GiaoDich.h"
#include <string>
#include <iostream>
#include <vector>


using namespace std;

int main() {
    int nDat, nNhaPho, nCanHo;
    vector<GiaoDich*> ds;
    cout << "Nhap so giao dich dat: "; cin >> nDat;
    cout << '\n';
    for (int i = 0; i < nDat; i++) {
        GiaoDich* gd = new GDDat;
        cout << "Nhap giao dich dat thu " << i + 1 << ": ";
        gd->nhap();
        gd->tinhGia();
        ds.push_back(gd);
        cout << '\n';
    }
    cout << "Nhap so giao dich nha pho: "; cin >> nNhaPho;
    cout << '\n';
    for (int i = 0; i < nNhaPho; i++) {
        GiaoDich* gd = new GDNhaPho;
        cout << "Nhap giao dich nha pho thu " << i + 1 << ": ";
        gd->nhap();
        gd->tinhGia();
        ds.push_back(gd);
        cout << '\n';
    }
    cout << "Nhap so giao dich can ho: "; cin >> nCanHo;
    cout << '\n';
    for (int i = 0; i < nCanHo; i++) {
        GiaoDich* gd = new GDCanHo;
        cout << "Nhap giao dich can ho thu " << i + 1 << ": ";
        gd->nhap();
        gd->tinhGia();
        ds.push_back(gd);
        cout << '\n';
    }
    cout << "Tong so giao dich dat: " << nDat << '\n';
    cout << "Tong so giao dich nha pho: " << nNhaPho << '\n';
    cout << "Tong so giao dich can ho: " << nCanHo << '\n';
    int stt = 0;
    cout << "\nDanh sach cac giao dich:\n";
    for (GiaoDich* gd: ds) {
        stt++;
        cout << "STT " << stt << ": ";
        gd->xuat();
    }
    int demCC = 0;
    long double tongTienCC =0;
    for (GiaoDich* gd : ds) {
        GDCanHo* ch = dynamic_cast<GDCanHo*>(gd);
        if (!(ch == nullptr)) {
            tongTienCC += ch->tinhGia();
            demCC++;
        }
        if (demCC > 0) {
            cout << "\nTrung binh thanh tien cua chung cu: " << tongTienCC/demCC << '\n';
        }
        
    }
    GDNhaPho* maxVal = nullptr;
    for (GiaoDich* gd : ds) {
        GDNhaPho* np = dynamic_cast<GDNhaPho*> (gd);
        if (!(np == NULL)) {
            if (maxVal == nullptr || maxVal->tinhGia() < np->tinhGia()) {
                maxVal = np;
            }
        }
    }
    if (maxVal != nullptr){
        cout << "\nNha pho co gia tri cao nhat la: "; maxVal->xuat();
        cout << '\n';
    }
    bool found = false;
    vector<GiaoDich*> dsT12;
    for (GiaoDich* gd: ds) {
        if (gd->getThang() == 12 && gd->getNam() == 2024) {
            found = true;
            dsT12.push_back(gd);
        }
    }
    if (found) {
        cout << "\nCac giao dich thang 12 nam 2024: ";
        for (GiaoDich* gd: dsT12){
            gd->xuat();
        }
    }
    else {
        cout << "Khong co giao dich trong thang 12 nam 2024!" << endl;
    }
    
    for (GiaoDich* gd: ds) {
        delete gd;
    }
    return 0;

}