/*
 * @file Main.c
 * @description Bu bir main dosyası yazdıgımız kodları burda test ediyoruz fonksiyonları calıstırıp konrtol ediyoruz
 * @assignment BP-3 PROJE-1
 * @date 02.12.2023 de basladım
 * @author Enes Karaçay enes.karacay@stu.fsm.edu.tr
 */
#include <stdio.h>
#include <stdlib.h>
#include "Proje1.h"

int main(int argc, char *argv[])
{
    printf("Dersler Olusturuluyor\n");
    Ders ders1 = returningDers("Beden egitimi", 3, 95);
    printf("*********************\n");
    Ders ders2 = returningDers("Saglik Bilgisi", 6, 55);
    printf("*********************\n");
    Ders ders3 = returningDers("Beden egitimi", 3, 55);
    printf("*********************\n");
    Ders ders4 = returningDers("Elektrik Devreleri", 5, 60);
    printf("*********************\n");
    Ders ders5 = returningDers("Kimya", 8, 30);
    printf("*********************\n");
    Ders ders6 = returningDers("Kimya", 8, 90);

    Ders aldigiDersler1[] = {ders1, ders2, ders5};
    size_t dersSayisi1 = sizeof(aldigiDersler1) / sizeof(Ders);
    Ders aldigiDersler2[] = {ders3, ders4, ders6};
    size_t dersSayisi2 = sizeof(aldigiDersler2) / sizeof(Ders);

    printf("*******Dersler Olusturuldu*******\n");
    printf("*******Ogrenciler Olusturuluyor*******\n");
    Ogrenci ogrenci1 = returningOgrenci(" Dusan", "Tadic", "Gida Muhendisligi", 75, aldigiDersler1, dersSayisi1);
    printf("******************************\n");
    Ogrenci ogrenci2 = returningOgrenci(" Enes", "karacay", "Kimya Muhendisligi", 10, aldigiDersler2, dersSayisi2);

    printf("*******Ogrenciler Olusturuldu*******\n");
    printİnfoOgrenci(ogrenci2, dersSayisi2);

    Ogrenci ogrenciArray[] = {ogrenci1, ogrenci2};
    size_t ogrenciSayisi1 = sizeof(ogrenciArray) / sizeof(Ogrenci);

    printf("Ogrenci Dizisi Bilgileri:\n");
    printİnfoOgrenciArray(ogrenciArray, ogrenciSayisi1, dersSayisi1);

    float ortalamaBedenEgitimi = calculatingArithmatic("Beden egitimi", ogrenciArray, ogrenciSayisi1, dersSayisi1);
    printf("Beden egitimi dersinin Aritmatik ortalamasi:%.3f\n", ortalamaBedenEgitimi);

    printf("************************************************\n");
    float ortalamaKimya = calculatingArithmatic("Kimya", ogrenciArray, ogrenciSayisi1, dersSayisi2);
    printf("kimya  dersinin Aritmatik ortalamasi:%.3f\n", ortalamaKimya);

    printf("/////////////////////////////////////////\n");
    float standartBedenEgitimi = calculatingStandardDeviation("Beden egitimi", ogrenciArray, ogrenciSayisi1, dersSayisi1);
    printf("Beden Egitimi Dersinin Standart Sapmasi : %.3f\n", standartBedenEgitimi);

    printf("***********************************************\n");
    float standartKimya = calculatingStandardDeviation("Kimya", ogrenciArray, ogrenciSayisi1, dersSayisi1);
    printf("Kimya Dersinin Standart Sapmasi : %.3f\n", standartKimya);

    printf("//////////////////////////////////////////\n");

    aboveAverageOgrenci("Kimya", ogrenciArray, ogrenciSayisi1, dersSayisi1);

    Ders ders10[3] = {{"Ticaret", 3, 90}, {"Finansman", 4, 80}, {"Bankacilik", 3, 70}};
    Ders ders12[3] = {{"Ticaret", 3, 80}, {"Finansman", 4, 70}, {"Bankacilik", 3, 50}};
    size_t aldigiDerslerSayisiSize = sizeof(ders10) / sizeof(Ders);

    float kovaryansSonucu = calculateKovaryans(ders10, ders12, aldigiDerslerSayisiSize);
    printf("Dersler arasindaki kovaryans sonucu: %.3f\n", kovaryansSonucu);

    ogrenciBilgileriniDosyayaYazan(ogrenciArray, ogrenciSayisi1, "ogrenci_bilgileriniyaz.txt");

    printf("***********************FONSIYONLAR SONLANMISTIR*************************\n");
    /*
        free(ders1.dersAdi);
        free(ders2.dersAdi);

        free(ogrenci1.ogrAdi);
        free(ogrenci1.ogrSoyadi);
        free(ogrenci1.bolumu); // Free ile  bellekteki    alanımızı boşaltıyoruz


        free(ogrenci2.ogrAdi);
        free(ogrenci2.ogrSoyadi);
        free(ogrenci2.bolumu);
        */
    for (int i = 0; i < 2; i++)
    {
        free(ogrenciArray[i].ogrAdi);
        free(ogrenciArray[i].ogrSoyadi);
        free(ogrenciArray[i].bolumu);

        for (int j = 0; j < 3; ++j)
        {
            // Her öğrencinin dersleri için ayrılan belleği serbest bırakıyoruz
            free(ogrenciArray[i].aldigiDersler[j].dersAdi);
        }
    }

    return 0;
}