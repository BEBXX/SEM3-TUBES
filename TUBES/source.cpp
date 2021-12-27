#include "header.h"

//CREATE SECTION
void createList(mll &list_dosen){
    first_parent(list_dosen) = NULL;
}

void new_elm_dosen(dosen info, adr_dosen &d){
    d = new elm_dosen;
    info_parent(d) = info;
    next_parent(d) = NULL;
    prev_parent(d) = NULL;
    first_child(d) = NULL;
}

void new_elm_mhs(mahasiswa info, adr_mhs &m){
    m = new elm_mhs;
    info_child(m) = info;
    next_child(m) = NULL;
    prev_child(m) = NULL;
}

//INSERT SECTION

void insertLast_dosen(mll &list_dosen, adr_dosen d){
    if (first_parent(list_dosen) == NULL){
        first_parent(list_dosen) = d;
    } else{
        adr_dosen p;
        p = first_parent(list_dosen);
        while (next_parent(p) != NULL){
            p = next_parent(p);
        }
        next_parent(p) = d;
        prev_parent(d) = p;
    }
}

void insertLast_mhs(mll &list_mhs, adr_dosen d, adr_mhs m){
    adr_mhs p;
    p = first_child(d);
    if (p != NULL){
        while (next_child(p) != NULL){
            p = next_child(p);
        }
        next_child(p) = m;
        prev_child(m) = p;
    } else {
        first_child(d) = m;
    }
}

//DELETE CHILD SECTION
void delete_mhs(mll &list_dosen, adr_dosen d, string nama_mhs){
    adr_mhs m = first_child(d);
    bool status = false;
    while (m != NULL){
        if(info_child(m).Nama_mhs == nama_mhs){
            if(first_child(d) == m){
                deleteFirst_mhs(list_dosen,d,m);
                status = true;
                cout<<"Data berhasil dihapus"<<endl;
            }else if(next_child(m) == NULL){
                deleteLast_mhs(list_dosen,d,m);
                status = true;
                cout<<"Data berhasil dihapus"<<endl;
            }else{
                adr_mhs prec;
                prec = prev_child(m);
                deleteAfter_mhs(list_dosen,d,prec,m);
                status = true;
                cout<<"Data berhasil dihapus"<<endl;
            }
        }
        m = next_child(m);
    }
    if (status == false){
        cout<<"Data Mahasiswa tidak ditemukan"<<endl;
        cout<<endl;
    }
}

void deleteFirst_mhs(mll &list_mhs, adr_dosen d, adr_mhs &m){
    if (next_child(first_child(d))== NULL){
        m = first_child(d);
        first_child(d) = NULL;
    } else {
        m = first_child(d);
        first_child(d) = next_child(m);
        next_child(m) = NULL;
        prev_child(first_child(d)) = NULL;
    }
}

void deleteLast_mhs(mll &list_mhs, adr_dosen d, adr_mhs &m){
    adr_mhs p;
    p = first_child(d);
    while (next_child(next_child(p)) != NULL){
        p = next_child(p);
    }
    m = next_child(p);
    next_child(p) = NULL;
    next_child(m) = NULL;
    prev_child(m) = NULL;
}

void deleteAfter_mhs(mll &list_mhs, adr_dosen d, adr_mhs prec, adr_mhs &m){
    next_child(prec) = next_child(m);
    prev_child(next_child(m)) = prec;
    next_child(m) = NULL;
    prev_child(m) = NULL;
}

//DELETE PARENT SECTION
void delete_dosen(mll &list_dosen, adr_dosen d){
    adr_dosen p = first_parent(list_dosen);
    bool status = false;
    while (p != NULL){
        if(p == d){
            if(first_parent(list_dosen) == d){
                deleteFirst_dosen(list_dosen,d);
                status = true;
            }else if(next_parent(p) == NULL){
                deleteLast_dosen(list_dosen,d);
                status = true;
            }else{
                adr_dosen prec;
                prec = prev_parent(d);
                deleteAfter_dosen(list_dosen,prec,d);
                status = true;
            }
        }
        p = next_parent(p);
    }
    if (status == false){
        cout<<"Data Dosen tidak tersedia"<<endl;
        cout<<endl;
    }
}

void deleteFirst_dosen(mll &list_dosen, adr_dosen &d){
    if (next_parent(first_parent(list_dosen))== NULL){
        d = first_parent(list_dosen);
        first_parent(list_dosen) = NULL;
    } else {
        d = first_parent(list_dosen);
        first_parent(list_dosen) = next_parent(d);
        prev_parent(next_parent(d)) = NULL;
        next_parent(d) = NULL;
    }
}

void deleteLast_dosen(mll &list_dosen, adr_dosen &d){
    d = first_parent(list_dosen);
    while(next_parent(d) != NULL){
        d = next_parent(d);
    }
    next_parent(prev_parent(d)) = NULL;
    prev_parent(d) = NULL;
}

void deleteAfter_dosen(mll &list_dosen, adr_dosen prec, adr_dosen &d){
    d = next_parent(prec);
    next_parent(prec) = next_parent(d);
    prev_parent(next_parent(d)) = prec;
    next_parent(d) = NULL;
    prev_parent(d) = NULL;
}

//SHOW SECTION

void showall_data(mll list_dosen){
    adr_dosen d;
    adr_mhs m;
    d = first_parent(list_dosen);
    while (d != NULL){
        cout <<"Nama Dosen       : "<<info_parent(d).Nama_dos << endl;
        cout <<"Kepakaran        : "<<info_parent(d).Kepakaran << endl;
        cout <<"Jumlah Bimbingan : "<<info_parent(d).Jumlah_bimb << endl;
        cout<<"===== MAHASISWA YANG DIBIMBING ====="<<endl;
        m = first_child(d);
        if (m != NULL){
            while (m != NULL){
                cout << "Nama Mahasiswa : "<<info_child(m).Nama_mhs <<endl;
                cout << "NIM            : "<<info_child(m).NIM <<endl;
                cout << "Topik TA       : "<<info_child(m).TopikTA <<endl;
                cout << "SKS Lulus      : "<<info_child(m).SKS_Lulus <<endl;
                cout <<endl;
                m = next_child(m);
            }
        }else{
            cout<<"Tidak ada Mahasiswa dalam bimbingan"<<endl;
        }
        cout<<endl;
        d = next_parent(d);
    }
}

void showdosen_data(mll list_dosen){
    adr_dosen d;
    d = first_parent(list_dosen);
    while (d != NULL){
        cout <<"Nama Dosen       : "<<info_parent(d).Nama_dos << endl;
        cout <<"Kepakaran        : "<<info_parent(d).Kepakaran << endl;
        cout <<"Jumlah Bimbingan : "<<info_parent(d).Jumlah_bimb << endl;
        cout<<endl;
        d = next_parent(d);
    }
}

void showmhs_data(mll list_dosen,adr_dosen d){
    adr_mhs m = first_child(d);
    if (m != NULL){
        while (m != NULL){
            cout << "Nama Mahasiswa : "<<info_child(m).Nama_mhs <<endl;
            cout << "NIM            : "<<info_child(m).NIM <<endl;
            cout << "Topik TA       : "<<info_child(m).TopikTA <<endl;
            cout << "SKS Lulus      : "<<info_child(m).SKS_Lulus <<endl;
            cout <<endl;
            m = next_child(m);
        }
    }else{
        cout<<"Tidak ada Mahasiswa dalam bimbingan"<<endl;
        cout<<endl;
    }
}

void showAvailDosen_data(mll list_dosen){
    adr_dosen d;
    d = first_parent(list_dosen);
    while (d != NULL){
        if (info_parent(d).Jumlah_bimb < 10){
        cout<<"Nama Dosen       : "<<info_parent(d).Nama_dos << endl;
        cout<<"Kepakaran        : "<<info_parent(d).Kepakaran << endl;
        cout<<"Jumlah Bimbingan : "<<info_parent(d).Jumlah_bimb<<"/10" << endl;
        cout<<endl;
        }
        d = next_parent(d);
    }
}

void showmhs_data_topik(mll list_dosen, string topik_ta){
    adr_dosen d;
    adr_mhs m;
    bool status = true;
    d = first_parent(list_dosen);
    while (d != NULL){
        m = first_child(d);
        if (m != NULL){
            while (m != NULL){
                if(info_child(m).TopikTA == topik_ta){
                    cout << "Nama Mahasiswa : "<<info_child(m).Nama_mhs <<endl;
                    cout << "NIM            : "<<info_child(m).NIM <<endl;
                    cout << "Topik TA       : "<<info_child(m).TopikTA <<endl;
                    cout << "SKS Lulus      : "<<info_child(m).SKS_Lulus <<endl;
                    cout <<endl;
                    status = false;
                }
                m = next_child(m);
            }
        }
        d = next_parent(d);
    }
    if (status == true){
        cout<<"Data Mahasiswa Tidak Tersedia"<<endl;
    }
}

//ADITIONAL FUNCTION SECTION
int countmhs_data(mll list_dosen){
    adr_dosen d;
    adr_mhs m;
    int count = 0;
    d = first_parent(list_dosen);
    while (d != NULL){
        m = first_child(d);
        if (m != NULL){
            while (m != NULL){
                count += 1;
                m = next_child(m);
            }
        }
        d = next_parent(d);
    }
    return count;
}

adr_dosen searh_dosen(mll &list_dosen, string nama_dosen){
    adr_dosen p;
    p = first_parent(list_dosen);
    while(p!=NULL){
        if(info_parent(p).Nama_dos == nama_dosen){
            return p;
        }
        p = next_parent(p);
    }
}

adr_mhs searh_mhs(mll &list_dosen,adr_dosen d, string nama_mhs){
    adr_mhs m;
    m = first_child(d);
    while(m!=NULL){
        if(info_child(m).Nama_mhs == nama_mhs){
            return m;
        }
        m = next_child(m);
    }
}

int countrelasi_mhs(mll list_dosen, int nim){
    adr_dosen d;
    adr_mhs m;
    int count = 0;
    d = first_parent(list_dosen);
    while (d != NULL){
        m = first_child(d);
        if (m != NULL){
            while (m != NULL){
                if (info_child(m).NIM == nim){
                    count += 1;
                }
                m = next_child(m);
            }
        }
        d = next_parent(d);
    }
    return count;
}

bool dupli_dosen(mll &list_dosen, string nama_dosen){
    adr_dosen p;
    p = first_parent(list_dosen);
    while(p!=NULL){
        if(info_parent(p).Nama_dos == nama_dosen){
            return true;
        }
        p = next_parent(p);
    }
}

int selectMenu(){
    cout<<"================MENU================"<<endl;
    cout<<"1. Menambahkan Data Dosen"<<endl;
    cout<<"2. Menambahkan Data Mahasiswa ke Data Dosen"<<endl;
    cout<<"3. Menghapus Data Dosen"<<endl;
    cout<<"4. Menghapus Data Mahasiswa Beserta Relasinya"<<endl;
    cout<<"5. Menampilkan data semua dosen pembimbing beserta jumlah mahasiswa bimbingannya"<<endl;
    cout<<"6. Menampilkan data mahasiswa bimbingan dari dosen tertentu"<<endl;
    cout<<"7. Menampilkan data mahasiswa dengan topik tertentu"<<endl;
    cout<<"8. Menampilkan seluruh dosen pembimbing beserta mahasiswa bimbingannya"<<endl;
    cout<<"9. Mencari nama dosen tertentu dengan kuota masih tersedia"<<endl;
    cout<<"10.Menghitung seluruh jumlah mahasiswa yang mengambil TA"<<endl;
    cout<<"0. Exit"<<endl;

    int input = 0;
    cout<< "Masukkan menu: ";
    cin >> input;

    return input;
}
