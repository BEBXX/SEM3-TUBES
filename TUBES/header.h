#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

/*

NAMA : ALBERTUS IVAN MARTINO
NIM : 1301204114

NAMA : DWINA SARAH DELVA
NIM : 1301204123

*/

#include <iostream>
//DEFINE PARENT
#define info_parent(P) P->info_parent
#define next_parent(P) P->next_parent
#define prev_parent(P) P->prev_parent
#define first_parent(L) L.first_parent

//DEFINE CHILD
#define info_child(P) P->info_child
#define next_child(P) P->next_child
#define prev_child(P) P->prev_child
#define first_child(P) P->first_child

using namespace std;

struct dosen{
    string Nama_dos;
    string Kepakaran;
    int Jumlah_bimb;
};

struct mahasiswa{
    string Nama_mhs;
    int NIM;
    string TopikTA;
    int SKS_Lulus;
    int Relasi;
};

typedef struct elm_dosen *adr_dosen;

typedef struct elm_mhs *adr_mhs;

struct elm_dosen{
    dosen info_parent;
    adr_dosen next_parent;
    adr_dosen prev_parent;
    adr_mhs first_child;
};

struct elm_mhs{
    mahasiswa info_child;
    adr_mhs next_child;
    adr_mhs prev_child;
};

struct mll{
    adr_dosen first_parent;
};

//PROCEDURE DAN FUNGSI
void createList(mll &list_dosen);
void showall_data(mll list_dosen);
void showdosen_data(mll list_dosen);
void showmhs_data(mll list_dosen,adr_dosen d);
void showmhs_data_topik(mll list_dosen, string topik_ta);
void showAvailDosen_data(mll list_dosen);
int countmhs_data(mll list_dosen);
int countrelasi_mhs(mll list_dosen, int nim);
bool dupli_dosen(mll &list_dosen, string nama_dosen);
int selectMenu();

//PARENT(DOSEN)
void new_elm_dosen(dosen info, adr_dosen &d);
void insertLast_dosen(mll &list_dosen, adr_dosen d);
void deleteFirst_dosen(mll &list_dosen, adr_dosen &d);
void deleteAfter_dosen(mll &list_dosen, adr_dosen prec, adr_dosen &d);
void deleteLast_dosen(mll &list_dosen, adr_dosen &d);
void delete_dosen(mll &list_dosen, adr_dosen d);
adr_dosen searh_dosen(mll &list_dosen, string nama_dosen);

//CHILD(MAHASISWA)
void new_elm_mhs(mahasiswa info, adr_mhs &m);
void insertLast_mhs(mll &list_mhs, adr_dosen d, adr_mhs m);
void deleteFirst_mhs(mll &list_mhs, adr_dosen d, adr_mhs &m);
void deleteLast_mhs(mll &list_mhs, adr_dosen d, adr_mhs &m);
void deleteAfter_mhs(mll &list_mhs, adr_dosen d, adr_mhs prec, adr_mhs &m);
void delete_mhs(mll &list_mhs,adr_dosen d, string nama_mhs);
adr_mhs searh_mhs(mll &list_dosen,adr_dosen d, string nama_mhs);

#endif // HEADER_H_INCLUDED
