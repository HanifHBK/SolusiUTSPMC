#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _OPEN_SYS_ITOA_EXT

#define MAXLEN 255
typedef struct dp{
    int urutan;
    char NIK[MAXLEN];
    char NAMA[MAXLEN];
    char TEMPATLAHIR[MAXLEN];
    char TANGGAL[MAXLEN];
    int UMUR;
    char JK[MAXLEN];
    char GOLDAR[MAXLEN];
    char STATUS[MAXLEN];
    char PROFESI[MAXLEN];
} dp;

dp* readfile(char namafile[MAXLEN], dp* data, int* test){
    FILE* dpfile = fopen(namafile, "r");
    if(dpfile == NULL){
        printf("File dengan nama tersebut tidak ada! Program akan keluar");
        exit(0);
    }
    char line[MAXLEN];
    char* token;
    int count = 0;
    while(fgets(line, MAXLEN, dpfile)){
        token = strtok(line, ";");
        if(count > 0){
            data = (dp*) realloc(data, (count+1)*sizeof(dp));
        }
        (data+count)->urutan = atoi(token);
        token = strtok(NULL, ";");
        strcpy((data + count)->NIK, token);
        token = strtok(NULL, ";");
        strcpy((data + count)->NAMA, token);
        token = strtok(NULL, ";");
        strcpy((data+count)->TEMPATLAHIR, token);
        token = strtok(NULL, ";");
        strcpy((data+count)->TANGGAL, token);
        token = strtok(NULL, ";");
        (data+count)->UMUR = atoi(token);
        token = strtok(NULL, ";");
        strcpy((data+count)->JK, token);
        token = strtok(NULL, ";");
        strcpy((data+count)->GOLDAR, token);
        token = strtok(NULL, ";");
        strcpy((data+count)->STATUS, token);
        token = strtok(NULL,"\n");
        strcpy((data+count)->PROFESI, token);
        count += 1;
    } 
    fclose(dpfile);
    (*test) = count;
    return data;
}

void printfile(dp* data, int count){
    int i;
    for(i = 1; i < count; i++){
        printf("%d %s %s %s %s %d %s %s %s %s\n", (data+i)->urutan,(data+i)->NIK, (data+i)->NAMA, (data+i)->TEMPATLAHIR, (data+i)->TANGGAL, (data+i)->UMUR, (data+i)->JK, (data+i)->GOLDAR, (data+i)->STATUS, (data+i)->PROFESI);
    } 
}

void appendinput(char namafile[MAXLEN], char new[MAXLEN]){
    FILE* dpfile = fopen(namafile, "a+");
    fprintf(dpfile, "%s", new);
}

char* dptostring(dp* data, int index, char string[MAXLEN], int del){
    char sub[MAXLEN];
    if(del != -1){
        itoa((data+index)->urutan-1, string, 10);
    } else {
        itoa((data+index)->urutan, string, 10);
    }
    strcat(string, ";");
    strcat(string, (data+index)->NIK);
    strcat(string, ";");
    strcat(string, (data+index)->NAMA);
    strcat(string, ";");
    strcat(string, (data+index)->TEMPATLAHIR);
    strcat(string, ";");
    strcat(string, (data+index)->TANGGAL);
    strcat(string, ";");
    itoa((data+index)->UMUR, sub, 10);
    strcat(string, sub);
    strcat(string, ";");
    strcat(string, (data+index)->JK);
    strcat(string, ";");
    strcat(string, (data+index)->GOLDAR);
    strcat(string, ";");
    strcat(string, (data+index)->STATUS);
    strcat(string, ";");
    strcat(string, (data+index)->PROFESI);
    strcat(string, "\n");
    return string;
}

void rewrite(char namafile[MAXLEN], dp* data, int count, int del){
    FILE* dpfile = fopen(namafile, "w+");
    fprintf(dpfile, "%s", "No;NIK;NamaLengkap;TempatLahir;TanggalLahir;Umur;JenisKelamin;GolonganDarah;Status;Pekerjaan\n");
    int i;
    char string[MAXLEN];
    for(i = 1; i < count; i++){
        if(del == i){
            continue;
        }else if((i > del) && (del != -1)){
            dptostring(data, i, string, del);
            fprintf(dpfile, "%s", string);
        } else {
            dptostring(data, i, string, -1);
            fprintf(dpfile, "%s", string);
        }
    }
}

void appendfile(char namafile[MAXLEN], dp* data2, int count2){
    FILE* dpfile = fopen(namafile, "a+");
    char string[MAXLEN];
    int i;
    for(i = 0; i < count2; i++){
        dptostring(data2, i, string, -1);
        fprintf(dpfile, "%s", string);
    }
}


dp* write(dp* data, int count){
    printf("Masukkan NIK: ");
    scanf(" %s", &(data+count)->NIK);
    printf("Masukkan Nama Lengkap: ");
    scanf(" %s", &(data+count)->NAMA);
    printf("Masukkan Tempat Lahir: ");
    scanf(" %s", &(data+count)->TEMPATLAHIR);
    printf("Masukkan Tanggal Lahir: ");
    scanf(" %s", &(data+count)->TANGGAL);
    printf("Masukkan Umur: ");
    scanf(" %d", &(data+count)->UMUR);
    printf("Masukkan Jenis Kelamin: ");
    scanf(" %s", &(data+count)->JK);
    printf("Masukkan Golongan Darah: ");
    scanf(" %s", &(data+count)->GOLDAR);
    printf("Masukkan Status: ");
    scanf(" %s", &(data+count)->STATUS);
    printf("Masukkan Pekerjaan: ");
    scanf(" %s", &(data+count)->PROFESI);
    return data;
}

void findnik(dp* data, char nik[MAXLEN], int count){
    int i;
    printf("Berikut merupakan penduduk dengan NIK : %s\n", nik);
    printf("---------------------------------------------------\n");
    int counts = 0;
    for(i = 0; i < count; i++){
        if(!(strcmp((data+i)->NIK, nik))){
            printf("NIK : %s\nNama Lengkap : %s\nTempat Lahir : %s\nTanggal Lahir : %s\nUmur : %d\nJenis Kelamin : %s\nGolongan Darah : %s\nStatus : %s\nPekerjaan : %s\n", (data+i)->NIK, (data+i)->NAMA, (data+i)->TEMPATLAHIR, (data+i)->TANGGAL, (data+i)->UMUR, (data+i)->JK, (data+i)->GOLDAR, (data+i)->STATUS, (data+i)->PROFESI);
            counts += 1;
            printf("---------------------------------------------------");
        }
    }
    if(counts == 0){
        printf("Tidak ditemukan penduduk dengan NIK tersebut!");
    }
}
void findnama(dp* data, char nama[MAXLEN], int count){
    int i;
    printf("Berikut merupakan data penduduk dengan nama %s\n", nama);
    printf("---------------------------------------------------\n");
    int counts = 0;
    for(i = 0; i < count; i++){
        if(!(strcmp((data+i)->NIK, nama))){
            printf("NIK : %s\nNama Lengkap : %s\nTempat Lahir : %s\nTanggal Lahir : %s\nUmur : %d\nJenis Kelamin : %s\nGolongan Darah : %s\nStatus : %s\nPekerjaan : %s\n", (data+i)->NIK, (data+i)->NAMA, (data+i)->TEMPATLAHIR, (data+i)->TANGGAL, (data+i)->UMUR, (data+i)->JK, (data+i)->GOLDAR, (data+i)->STATUS, (data+i)->PROFESI);
            counts += 1;
            printf("---------------------------------------------------");
        }
    }
    if(counts == 0){
        printf("Tidak ditemukan penduduk dengan nama tersebut!");
    }
}

void findumur(dp* data, int umur, int count){
    int i;
    printf("Berikut merupakan penduduk dengan umur %d\n", umur);
    printf("---------------------------------------------------\n");
    int counts = 0;
    for(i = 0; i < count; i++){
        if((data+i)->UMUR == umur){
            printf("NIK : %s\nNama Lengkap : %s\nTempat Lahir : %s\nTanggal Lahir : %s\nUmur : %d\nJenis Kelamin : %s\nGolongan Darah : %s\nStatus : %s\nPekerjaan : %s\n", (data+i)->NIK, (data+i)->NAMA, (data+i)->TEMPATLAHIR, (data+i)->TANGGAL, (data+i)->UMUR, (data+i)->JK, (data+i)->GOLDAR, (data+i)->STATUS, (data+i)->PROFESI);
            counts += 1;
            printf("---------------------------------------------------\n");
        }
    }
    if(counts == 0){
        printf("Tidak ditemukan penduduk dengan NIK tersebut!");
    }
}

int main(){
    char namafile[MAXLEN];
    printf("Program Pencatatan Data Penduduk\n");
    printf("Masukkan nama file berisi data penduduk: ");
    scanf("%s", &namafile);
    dp* data;
    data = (dp*) malloc(sizeof(dp));
    int count;
    data = readfile(namafile, data, &count);
    printf("Program ini memiliki beberapa fitur diantaranya:\n1. Menambahkan, Mengubah atau Menghapus data penduduk\n2. Menambahkan data penduduk baru berdasarkan import file\n3. Mencari penduduk berdasarkan NIK/Nama/Umur.\n");
    int choice;
    printf("Masukkan fitur yang akan digunakan: ");
    scanf(" %d", &choice);
    if(choice == 1){
        int abc;
        printf("Pada fitur ini terdapat 3 fungsi yaitu:\n1. Menambah Data Penduduk\n2. Mengubah Data Penduduk\n3. Menghapus Data Penduduk\n");
        printf("Tolong masukkan fungsi yang ingin digunakan: ");
        scanf(" %d", &abc);
        char test[MAXLEN];
        if(abc == 1){
            count +=1;
            data = (dp*) realloc (data, (count+1)*sizeof(dp));
            (data+count)->urutan = count;
            data = write(data, count);
            dptostring(data, count, test, -1);
            appendinput(namafile, test);
            printf("Data berhasil ditambahkan. Program akan keluar.");
        } else if(abc == 2){
            printf("Berikut merupakan data penduduk yang terdapat pada file\n");
            printfile(data, count);
            printf("Masukkan No. Penduduk yang ingin diubah datanya: ");
            int index;
            scanf(" %d", &index);
            data = write(data, index);
            rewrite(namafile, data, count, -1);
            printf("Data berhasil diubah. Program akan keluar.");
        } else if(abc == 3){
            printf("Berikut merupakan data penduduk yang terdapat pada file\n");
            printfile(data, count);
            printf("Masukkan No. Penduduk yang ingin dihapus datanya: ");
            int index;
            scanf(" %d", &index);
            rewrite(namafile, data, count, index);
            printf("Data berhasil dihapus. Program akan keluar.");
        } else {
            printf("Masukan salah, program akan keluar.");
        }
    } else if(choice ==2){
        char namafile2[MAXLEN];
        dp* data2;
        data2 = (dp*) malloc(sizeof(dp));
        int count2;
        data2 = readfile(namafile2, data2, &count2);
        appendfile(namafile, data2, count2);
    } else if(choice == 3){
        printf("Fitur mencari data penduduk:\n1. Berdasarkan NIK\n2. Berdasarkan Nama\n3. Berdasarkan Umur\n");
        int abc;
        printf("Masukkan pilihan fitur yang akan digunakan: ");
        scanf(" %d", &abc);
        if(abc == 1){
            char nik[MAXLEN];
            printf("Masukkan NIK yang akan dicari: ");
            scanf(" %s", &nik);
            findnik(data, nik, count);
        } else if(abc == 2){
            char Nama[MAXLEN];
            printf("Masukkan Nama Lengkap yang akan dicari: ");
            scanf(" %s", &Nama);
            findnama(data, Nama, count);
        } else if(abc == 3){
            int umur;
            printf("Masukkan umur penduduk yang akan dicari: ");
            scanf(" %d", &umur);
            findumur(data, umur, count);
        }
    }
}