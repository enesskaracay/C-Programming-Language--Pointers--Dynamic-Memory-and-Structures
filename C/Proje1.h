/*
 * @file Proje1.h
 * @description Bu bir header dosyası ve fonksiyonların prototiplerini ve struct yapıları bulunuyor
 * @assignment BP-3 PROJE-1
 * @date 02.12.2023 de basladım
 * @author Enes Karaçay enes.karacay@stu.fsm.edu.tr
 */

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
   char *dersAdi;
   unsigned short int kredi;
   unsigned short int puan;

} Ders;

typedef struct
{
   char *ogrAdi;
   char *ogrSoyadi;
   char *bolumu;
   float ortalama;
   Ders *aldigiDersler;

} Ogrenci;

Ders returningDers(char *dersAdi, unsigned short int kredi, unsigned short int puan);
Ogrenci returningOgrenci(char *ogrAdi, char *ogrSoyadi, char *bolumu, float ortalama, Ders *aldigiDersler, int dersSayisi);

void printİnfoOgrenci(Ogrenci ogrenci, int dersSayisi);
void printİnfoOgrenciArray(Ogrenci *ogrencilerinDizisi, int ogrenciSayisi, int dersSayisi);
float calculatingArithmatic(char *dersAdi, Ogrenci *ogrencilerinDizisi, int ogrenciSayisi, int dersSayisiKac);

float calculatingStandardDeviation(char *dersAdi, Ogrenci *ogrencilerinDizisi, int ogrenciSayisi, int dersSayisikac2);
void aboveAverageOgrenci(char *dersAdi, Ogrenci *ogrencilerinDizisi, int ogrenciSayisi, int dersSayisiKac);
float calculateKovaryans(Ders *dersler1, Ders *dersler2, int size);

void ogrenciBilgileriniDosyayaYazan(Ogrenci *ogrenciArray, int size, char *dosyaAdi);
