#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variabel global untuk menyimpan informasi pelanggan
int pulsa = 100000;
int kuota = 0;
int paketTelepon = 0;

// Pembersih tampilan
void clearScreen() {
    system("cls");
}

// Fungsi cek pulsa
void cekPulsa() {
	
	clearScreen();
    printf("Pulsa Anda saat ini: %d\n", pulsa);
}

// Fungsi cek kuota
void cekKuota() {
	
	clearScreen();
    if (kuota >= 1000) {
        printf("Kuota internet Anda saat ini: %.2f GB\n", kuota / 1000.0);
    } else {
        printf("Kuota internet Anda saat ini: %d MB\n", kuota);
    }
    printf("Paket telepon Anda saat ini: %d Menit\n", paketTelepon);
}


// Fungsi beli kuota
void beliKuota() {
    int pilihan;
    int kuotaPaket[] = {900, 5000, 10000};
    int hargaPaket[] = {10000, 45000, 80000};
    
    clearScreen();
    printf("===================================\n");
    printf("        KUOTA INTERNET\n");
    printf("===================================\n");
    printf("Pilih paket kuota:\n");
    printf("1. 900 MB (Rp 10000)\n");
    printf("2. 5 GB (Rp 45000)\n");
    printf("3. 10 GB (Rp 80000)\n");
    printf("Masukkan pilihan Anda: ");
    scanf("%d", &pilihan);

    if (pilihan >= 1 && pilihan <= 3) {
        if (pulsa >= hargaPaket[pilihan - 1]) {
            kuota += kuotaPaket[pilihan - 1];
            pulsa -= hargaPaket[pilihan - 1];
            clearScreen();
            if(kuotaPaket[pilihan - 1] >= 1000) {
                printf("Anda telah berhasil membeli kuota sebesar %.2f GB.\n", kuotaPaket[pilihan - 1] / 1000.0);
            } else {
                printf("Anda telah berhasil membeli kuota sebesar %d MB.\n", kuotaPaket[pilihan - 1]);
            }
        } else {
            clearScreen();
            printf("Pulsa tidak cukup untuk membeli paket ini.\n");
        }
    } else {
        clearScreen();
        printf("Pilihan tidak valid.\n");
    }
}

// Fungsi beli paket telepon
void beliPaketTelepon() {
    int pilihan;
    int teleponPaket[] = {30, 100, 200};
    int hargaPaket[] = {5000, 15000, 25000};
    
    clearScreen();
    printf("===================================\n");
    printf("        PAKET TELEPON\n");
    printf("===================================\n");
    printf("Pilih paket telepon:\n");
    printf("1. 30 menit (Rp 5000)\n");
    printf("2. 100 menit (Rp 15000)\n");
    printf("3. 200 menit (Rp 25000)\n");
    printf("Masukkan pilihan Anda: ");
    scanf("%d", &pilihan);

    if (pilihan >= 1 && pilihan <= 3) {
        if (pulsa >= hargaPaket[pilihan - 1]) {
            paketTelepon += teleponPaket[pilihan - 1];
            pulsa -= hargaPaket[pilihan - 1];
            clearScreen();
            printf("Anda telah berhasil membeli paket telepon %d menit.\n", teleponPaket[pilihan - 1]);
        } else {
            clearScreen();
            printf("Pulsa tidak cukup untuk membeli paket ini.\n");
        }
    } else {
        clearScreen();
        printf("Pilihan tidak valid.\n");
    }
}

// Fungsi beli paket kuota dengan telepon
void beliKuota_dan_telepon() {
    int pilihan;
    int kuotaPaket[] = {2000, 3000, 8000};
    int teleponPaket[] = {10, 60, 180};
    int hargaPaket[] = {22000, 31000, 95000};
    
    clearScreen();
    printf("===================================\n");
    printf("    PAKET KUOTA dengan TELEPON    \n");
    printf("===================================\n");
    printf("Pilih paket kuota dengan telepon:\n");
    printf("1. 2 GB, telepon sampai 10 menit (Rp 22000)\n");
    printf("2. 3 GB, telepon sampai 60 menit (Rp 31000)\n");
    printf("3. 8 GB, telepon sampai 180 menit (Rp 95000)\n");
    printf("Masukkan pilihan Anda: ");
    scanf("%d", &pilihan);

    if (pilihan >= 1 && pilihan <= 3) {
        if (pulsa >= hargaPaket[pilihan - 1]) {
            kuota += kuotaPaket[pilihan - 1];
            paketTelepon += teleponPaket[pilihan - 1];
            pulsa -= hargaPaket[pilihan - 1];
            clearScreen();
            if(kuotaPaket[pilihan - 1] >= 1000) {
                printf("Anda telah berhasil membeli kuota sebesar %.2f GB, telepon sd %d menit.\n", kuotaPaket[pilihan - 1] / 1000.0, teleponPaket[pilihan - 1]);
            } else {
                printf("Anda telah berhasil membeli kuota sebesar %d MB, telepon sd %d menit.\n", kuotaPaket[pilihan - 1], teleponPaket[pilihan - 1]);
            }
        } else {
            clearScreen();
            printf("Pulsa tidak cukup untuk membeli paket ini.\n");
        }
    } else {
        clearScreen();
        printf("Pilihan tidak valid.\n");
    }
}

// Fungsi utama program
int main() {
    int pilihan;
    int kuotaLagi;
    int teleponLagi;
    int kuotaTeleponLagi;
    int keluarCekKuota;
    int keluarCekPulsa;

    struct data {
        char cek_Pulsa[20];
        char cek_KuotaTelepon[50];
        char beli_Kuota[50];
        char beli_Telepon[50];
        char beli_KuotaTelepon[50];
        char keluar[10];
        int transaksiLagi;
    }; 

    struct data menu;	
    strcpy(menu.cek_Pulsa,"Cek pulsa");
    strcpy(menu.cek_KuotaTelepon,"Cek kuota & paket telepon");
    strcpy(menu.beli_Kuota,"Beli kuota internet");
    strcpy(menu.beli_Telepon,"Beli paket telepon");
    strcpy(menu.beli_KuotaTelepon,"Beli paket kuota dengan telepon");
    strcpy(menu.keluar,"Keluar");
    menu.transaksiLagi = 1;
    
    do {
        // Tampilan menu utama
        clearScreen();
        printf("===================================\n");
        printf("         MENU LAYANAN KAMI         \n");
        printf("===================================\n");
        printf("Pilihan menu:\n");
        printf("1. %s\n", menu.cek_Pulsa);
        printf("2. %s\n", menu.cek_KuotaTelepon);
        printf("3. %s\n", menu.beli_Kuota);
        printf("4. %s\n", menu.beli_Telepon);
        printf("5. %s\n", menu.beli_KuotaTelepon);
        printf("6. %s\n", menu.keluar);
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &pilihan);
        clearScreen();

        // Pilihan pada menu
        switch (pilihan) {
            case 1:
				cekPulsa();
                printf("keluar? (1 untuk ya): ");
                scanf("%d", &keluarCekPulsa);
                if (keluarCekPulsa != 1) {
                    printf("pilihan tidak valid");
                    exit(0);
                }
                else if(keluarCekPulsa = 1){
                	break;
				}
                
            case 2:
                cekKuota();
                printf("keluar? (1 untuk ya): ");
                scanf("%d", &keluarCekKuota);
                if (keluarCekKuota != 1) {
                    printf("pilihan tidak valid");
                    exit(0);
                    
                }
				else if(keluarCekKuota = 1){
                	break;
				}
                
            case 3:
                do {
                    beliKuota();
                    printf("apakah anda ingin membeli kuota lagi? (1 untuk ya, 0 untuk tidak): ");
                    scanf("%d", &kuotaLagi);
                    if (kuotaLagi != 0 && kuotaLagi != 1) {
                        printf("pilihan tidak valid");
                        exit(0);
                    }
                } while (kuotaLagi == 1);
                break;
            case 4:
                do {
                    beliPaketTelepon();
                    printf("apakah anda ingin membeli paket telepon lagi? (1 untuk ya, 0 untuk tidak): ");
                    scanf("%d", &teleponLagi);
                    if (teleponLagi != 0 && teleponLagi != 1) {
                        printf("pilihan tidak valid");
                        exit(0);
                    }
                } while (teleponLagi == 1);
                break;
            case 5:
                do {
                    beliKuota_dan_telepon();
                    printf("apakah anda ingin membeli kuota dengan paket telepon lagi? (1 untuk ya, 0 untuk tidak): ");
                    scanf("%d", &kuotaTeleponLagi);
                    if (kuotaTeleponLagi != 0 && kuotaTeleponLagi != 1) {
                        printf("pilihan tidak valid");
                        exit(0);
                    }
                } while (kuotaTeleponLagi == 1);
                break;
            case 6:
                menu.transaksiLagi = 0;
                break;
            default:
                clearScreen();
                printf("Pilihan tidak valid.\n");
				menu.transaksiLagi = 0;
        }
    } while (menu.transaksiLagi == 1);

    clearScreen();
    printf("Terima kasih telah menggunakan layanan kami.\n");
    return 0;
}

/*
kelompok 16 Alpro Kelas D
Ahmad Baihaqi (23081010218)
Fauzan Ilyas Almeyda (23081010188)
*/
