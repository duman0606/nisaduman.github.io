#include <stdio.h>
#include <math.h>

#define PI 3.14159265


void serbestDusme(double *gDizisi);
void yukariAtis(double *gDizisi);
void agirlikDeneyi(double *gDizisi);
void potansiyelEnerji(double *gDizisi);
void hidrostatikBasinc(double *gDizisi);
void kaldirmaKuvveti(double *gDizisi);
void basitSarkac(double *gDizisi);
void ipGerilmesi(double *gDizisi);
void asansorDeneyi(double *gDizisi);
void sonuclariYazdir(const char *deneyAdi, double sonuc, const char *birim, int indis);

int main() {

    double yercekimiIvmeleri[] = {3.70, 8.87, 9.81, 3.71, 24.79, 10.44, 8.69, 11.15};
    char bilimInsani[50];
    int secim = 0;

    printf("**** HOSGELDINIZ BU BIR UZAY SIMULASYONUDUR ****\n");
    printf("Lutfen adinizi giriniz: ");
    scanf("%s", bilimInsani);
    printf("\nSayin %s, simulasyon hazir.\n", bilimInsani);

    while (1) {
        printf("\n--- DENEY MENUSU ---\n");
        printf("1. Serbest Dusme Deneyi\n2. Yukari Atis Deneyi\n3. Agirlik Deneyi \n4. Kutlecekimsel Potansiyel Enerji Deneyi\n");
        printf("5. Hidrostatik Basinc Deneyi\n6. Arsimet Kaldirma Kuvveti Deneyi\n7. Basit Sarkac Periyodu Deneyi\n");
        printf("8. Sabit Ip Gerilmesi Deneyi\n9. Asansor Deneyi\n-1. Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);

        if (secim == -1) break;

        switch (secim) {
            case 1: serbestDusme(yercekimiIvmeleri); break;
            case 2: yukariAtis(yercekimiIvmeleri); break;
            case 3: agirlikDeneyi(yercekimiIvmeleri); break;
            case 4: potansiyelEnerji(yercekimiIvmeleri); break;
            case 5: hidrostatikBasinc(yercekimiIvmeleri); break;
            case 6: kaldirmaKuvveti(yercekimiIvmeleri); break;
            case 7: basitSarkac(yercekimiIvmeleri); break;
            case 8: ipGerilmesi(yercekimiIvmeleri); break;
            case 9: asansorDeneyi(yercekimiIvmeleri); break;
            default: printf("Hatali secim!\n");
        }
    }
    return 0;
}


void sonuclariYazdir(const char *deneyAdi, double sonuc, const char *birim, int indis) {
    const char *gezegenler[] = {"Merkur", "Venus", "Dunya", "Mars", "Jupiter", "Saturn", "Uranus", "Neptun"};
    printf("%s: %.2f %s (%s)\n", deneyAdi, sonuc, birim, *(gezegenler + indis));
}


void serbestDusme(double *gDizisi) {
    double t, h;
    printf("Sure (s): "); scanf("%lf", &t);
    t = (t < 0) ? -t : t;
    for (int i = 0; i < 8; i++) {
        h = 0.5 * (*(gDizisi + i)) * t * t;
        sonuclariYazdir("Yol", h, "metre", i);
    }
}

void yukariAtis(double *gDizisi) {
    double v0, hmax;
    printf("Ilk Hiz (m/s): "); scanf("%lf", &v0);
    v0 = (v0 < 0) ? -v0 : v0;
    for (int i = 0; i < 8; i++) {
        hmax = (v0 * v0) / (2 * (*(gDizisi + i)));
        sonuclariYazdir("Maksimum Yukseklik", hmax, "metre", i);
    }
}

void agirlikDeneyi(double *gDizisi) {
    double m, G;
    printf("Kutle (kg): "); scanf("%lf", &m);
    m = (m < 0) ? -m : m;
    for (int i = 0; i < 8; i++) {
        G = m * (*(gDizisi + i));
        sonuclariYazdir("Agirlik", G, "Newton", i);
    }
}

void potansiyelEnerji(double *gDizisi) {
    double m, h, Ep;
    printf("Kutle (kg) ve Yukseklik (m): "); scanf("%lf %lf", &m, &h);
    m = (m < 0) ? -m : m; h = (h < 0) ? -h : h;
    for (int i = 0; i < 8; i++) {
        Ep = m * (*(gDizisi + i)) * h;
        sonuclariYazdir("Potansiyel Enerji", Ep, "Joule", i);
    }
}

void hidrostatikBasinc(double *gDizisi) {
    double rho, h, P;
    printf("Yogunluk (kg/m3) ve Derinlik (m): "); scanf("%lf %lf", &rho, &h);
    h = (h < 0) ? -h : h;
    for (int i = 0; i < 8; i++) {
        P = rho * (*(gDizisi + i)) * h;
        sonuclariYazdir("Hidrostatik Basinc", P, "Pascal", i);
    }
}

void kaldirmaKuvveti(double *gDizisi) {
    double rho, V, Fk;
    printf("Sivi Yogunlugu (kg/m3) ve Batan Hacim (m3): "); scanf("%lf %lf", &rho, &V);
    V = (V < 0) ? -V : V;
    for (int i = 0; i < 8; i++) {
        Fk = rho * (*(gDizisi + i)) * V;
        sonuclariYazdir("Kaldirma Kuvveti", Fk, "Newton", i);
    }
}

void basitSarkac(double *gDizisi) {
    double L, T;
    printf("Ipin Uzunlugu (m): "); scanf("%lf", &L);
    L = (L < 0) ? -L : L;
    for (int i = 0; i < 8; i++) {
        T = 2 * PI * sqrt(L / (*(gDizisi + i)));
        sonuclariYazdir("Periyot", T, "saniye", i);
    }
}

void ipGerilmesi(double *gDizisi) {
    double m, T;
    printf("Kutle (kg): "); scanf("%lf", &m);
    m = (m < 0) ? -m : m;
    for (int i = 0; i < 8; i++) {
        T = m * (*(gDizisi + i));
        sonuclariYazdir("Ip Gerilmesi", T, "Newton", i);
    }
}

void asansorDeneyi(double *gDizisi) {
    double m, a, N;
    int durum;
    printf("Kutle (kg) ve Asansor Ivmesi (m/s2): "); scanf("%lf %lf", &m, &a);
    printf("1: Yukari Hizlanma/Asagi Yavaslama\n2: Asagi Hizlanma/Yukari Yavaslama\nSecim: ");
    scanf("%d", &durum);
    m = (m < 0) ? -m : m; a = (a < 0) ? -a : a;
    for (int i = 0; i < 8; i++) {
        if (durum == 1) N = m * ((*(gDizisi + i)) + a);
        else N = m * ((*(gDizisi + i)) - a);
        sonuclariYazdir("Etkin Agirlik", N, "Newton", i);
    }
}
