#include "header.h"
#include <iostream>
int main(){
    mll list_dosen;

    mahasiswa data_mhs;

    adr_mhs m;
    int menu;
    char status;
    adr_dosen d;
    dosen data_dosen;
    createList(list_dosen);

    //========================== SAMPLE DATA ===========================
    data_dosen.Nama_dos = "Anton";
    data_dosen.Kepakaran = "ComputerVision";
    data_dosen.Jumlah_bimb = 0;
    new_elm_dosen(data_dosen, d);
    insertLast_dosen(list_dosen, d);

    data_mhs.Nama_mhs = "Budi";
    data_mhs.NIM = 123456;
    data_mhs.TopikTA = "ComputerVision";
    data_mhs.SKS_Lulus = 125;
    new_elm_mhs(data_mhs, m);
    insertLast_mhs(list_dosen,d,m);
    info_parent(d).Jumlah_bimb += 1;

    data_mhs.Nama_mhs = "Andi";
    data_mhs.NIM = 123488;
    data_mhs.TopikTA = "ComputerVision";
    data_mhs.SKS_Lulus = 133;
    new_elm_mhs(data_mhs, m);
    insertLast_mhs(list_dosen,d,m);
    info_parent(d).Jumlah_bimb += 1;

    data_dosen.Nama_dos = "Anisa";
    data_dosen.Kepakaran = "Kriptografi";
    data_dosen.Jumlah_bimb = 0;
    new_elm_dosen(data_dosen, d);
    insertLast_dosen(list_dosen, d);

    data_mhs.Nama_mhs = "Tono";
    data_mhs.NIM = 123457;
    data_mhs.TopikTA = "Kriptografi";
    data_mhs.SKS_Lulus = 130;
    new_elm_mhs(data_mhs, m);
    insertLast_mhs(list_dosen,d,m);
    info_parent(d).Jumlah_bimb += 1;

    data_dosen.Nama_dos = "Joko";
    data_dosen.Kepakaran = "IoT";
    data_dosen.Jumlah_bimb = 0;
    new_elm_dosen(data_dosen, d);
    insertLast_dosen(list_dosen, d);

    data_dosen.Nama_dos = "Ani";
    data_dosen.Kepakaran = "NLP";
    data_dosen.Jumlah_bimb = 0;
    new_elm_dosen(data_dosen, d);
    insertLast_dosen(list_dosen, d);

    data_mhs.Nama_mhs = "Toni";
    data_mhs.NIM = 123458;
    data_mhs.TopikTA = "NLP";
    data_mhs.SKS_Lulus = 121;
    new_elm_mhs(data_mhs, m);
    insertLast_mhs(list_dosen,d,m);
    info_parent(d).Jumlah_bimb += 1;

    data_mhs.Nama_mhs = "Tuti";
    data_mhs.NIM = 123499;
    data_mhs.TopikTA = "NLP";
    data_mhs.SKS_Lulus = 127;
    new_elm_mhs(data_mhs, m);
    insertLast_mhs(list_dosen,d,m);
    info_parent(d).Jumlah_bimb += 1;

    data_mhs.Nama_mhs = "Adi";
    data_mhs.NIM = 123477;
    data_mhs.TopikTA = "NLP";
    data_mhs.SKS_Lulus = 128;
    new_elm_mhs(data_mhs, m);
    insertLast_mhs(list_dosen,d,m);
    info_parent(d).Jumlah_bimb += 1;
    //========================== SAMPLE DATA ===========================

    menu = selectMenu();
    while (menu != 0){
        switch(menu){
        case 1:
            {
                cout<<"Masukkan Nama Dosen : ";
                cin>>data_dosen.Nama_dos;
                cout<<"Masukkan Kepakaran : ";
                cin>>data_dosen.Kepakaran;
                data_dosen.Jumlah_bimb = 0;
                if(dupli_dosen(list_dosen,data_dosen.Nama_dos)){
                    cout<<"Data sudah tersedia"<<endl;
                }else{
                    new_elm_dosen(data_dosen, d);
                    insertLast_dosen(list_dosen, d);
                    cout<<"Berhasil ditambahkan"<<endl;
                }
                break;
            }
        case 2:
            {
                string Nama_Dosen;
                cout<<"Masukkan Nama Mahasiswa : ";
                cin>>data_mhs.Nama_mhs;
                cout<<"Masukkan NIM Mahasiswa : ";
                cin>>data_mhs.NIM;
                cout<<"Masukkan Topik mahasiswa : ";
                cin>>data_mhs.TopikTA;
                cout<<"Masukkan Jumlah SKS Mahasiswa : ";
                cin>>data_mhs.SKS_Lulus;
                cout<<"Masukkan Nama Dosen Pembimbing : ";
                cin>>Nama_Dosen;
                data_mhs.Relasi = countrelasi_mhs(list_dosen,data_mhs.NIM);

                d = searh_dosen(list_dosen,Nama_Dosen);
                if (d == NULL){
                    cout<<"Data tidak berhasil, Data Dosen tidak ditemukan"<<endl;
                }else if((d != NULL) && (data_mhs.SKS_Lulus < 120)){
                    cout<<"Data tidak berhasil ditambahkan, dikarenakan sks tidak mencukupi"<<endl;
                }else if((d != NULL) && (data_mhs.SKS_Lulus >= 120) && (info_parent(d).Kepakaran != data_mhs.TopikTA)){
                    cout<<"Data tidak berhasil ditambahkan, dikarenakan kepakaran dosen tidak sesuai dengan topik TA"<<endl;
                }else if((d != NULL) && (data_mhs.SKS_Lulus >= 120) && (info_parent(d).Kepakaran == data_mhs.TopikTA) && (data_mhs.Relasi == 2)){
                    cout<<"Data tidak berhasil ditambahkan, dikarenakan Mahasiswa sudah mencapai batas maksimal pembimbing skripsi"<<endl;
                }else{
                    data_mhs.Relasi += 1;
                    new_elm_mhs(data_mhs, m);
                    insertLast_mhs(list_dosen,d,m);
                    info_parent(d).Jumlah_bimb += 1;
                    cout<<"Data Berhasil ditambahkan"<<endl;
                }
                break;
            }
        case 3:
            {
                string nama_dosen_find;
                cout<<"Masukkan Nama Dosen Yang Ingin Dihapus Datanya : ";
                cin>>nama_dosen_find;
                adr_dosen sd = searh_dosen(list_dosen, nama_dosen_find);
                if (sd == NULL){
                    cout<<"Data tidak ditemukan"<<endl;
                }else{
                    delete_dosen(list_dosen,sd);
                    cout<<"Data berhasil dihapus"<<endl;
                }
                break;
            }
        case 4:
            {
                string nama_dosen_find;
                string nama_mhs_find;
                cout<<"Masukkan Nama Dosen Yang Ingin Dihapus Datanya : ";
                cin>>nama_dosen_find;
                adr_dosen sd = searh_dosen(list_dosen, nama_dosen_find);
                if (sd == NULL){
                    cout<<"Data Dosen tidak ditemukan"<<endl;
                }else{
                    cout<<"Masukkan Nama Mahasiswa yang ingin dihapus : ";
                    cin>>nama_mhs_find;
                    adr_mhs sm = searh_mhs(list_dosen, sd, nama_mhs_find);
                    if (sm == NULL){
                        cout<<"Data Mahasiswa tidak ditemukan"<<endl;
                    }else{
                        delete_mhs(list_dosen,sd,nama_mhs_find);
                        info_parent(sd).Jumlah_bimb -= 1;
                    }
                }
                break;
            }
        case 5:
            {
                showdosen_data(list_dosen);
                break;
            }
        case 6:
            {
                string nama_dosen_find;
                cout<<"Masukkan Nama Dosen Yang Ingin Ditampilkan : ";
                cin>>nama_dosen_find;
                adr_dosen sd = searh_dosen(list_dosen,nama_dosen_find);
                if (sd == NULL){
                    cout<<"Data tidak ditemukan"<<endl;
                }else{
                    showmhs_data(list_dosen,sd);
                }
                break;
            }
        case 7:
            {
                string nama_topik_find;
                cout<<"Masukkan Topik TA Yang Ingin Ditampilkan : ";
                cin>>nama_topik_find;
                showmhs_data_topik(list_dosen,nama_topik_find);
                break;
            }
        case 8:
            {
                showall_data(list_dosen);
                break;
            }
        case 9:
            {
                showAvailDosen_data(list_dosen);
                break;
            }
        case 10:
            {
                cout<<"Banyaknya Mahasiswa yang mengambil TA : "<<countmhs_data(list_dosen)<<endl;
                break;
            }
        }
        cout<< "Kembali ke menu utama (Y/N) : ";
        cin>>status;
        if (status == 'Y'){
            menu = selectMenu();
        }else{
            cout<<endl;
            cout << "ANDA TELAH KELUAR DARI PROGRAM";
            cout<<endl;
            break;
        }
    }

    if (menu == 0){
        cout<<endl;
        cout << "ANDA TELAH KELUAR DARI PROGRAM";
        cout<<endl;
    }

}


