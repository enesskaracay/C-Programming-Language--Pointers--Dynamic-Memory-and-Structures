/*
 * @file Proje1.c
 * @description Burada fonksiyonlarımızı implemente ediyoruz  içeriklerini yazıyoruz
 * @assignment BP-3 PROJE-1
 * @date 02.12.2023 de basladım
 * @author Enes Karaçay enes.karacay@stu.fsm.edu.tr
 */
#include "Proje1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

Ders returningDers(char *dersAdi, unsigned short int kredi, unsigned short int puan) // burda aslında sanırım Ders structı oluşturmamız yetiyor ama ben bir de yazdırıyorum .
{
    Ders newDers; // ders structımız a burada bir isim veriyoruz random bisey olabilir

    newDers.dersAdi = (char *)malloc(256 * sizeof(char)); // Ders adını burda malloc foknsiyonumuz ile bellekte yer ayırıyoruz projede 256 boyut demiş
    strcpy(newDers.dersAdi, dersAdi);                     // sağdakini soldakine eşitliyoruz dersAdı olarak gelen parametremizi newDers.adi ya atıyoruz
    printf("Dersin Adi:%s\n", newDers.dersAdi);           // aldıgımız dersi yazdırıyoruz ve %s kullanmamız gerkiyor cunku string olarak yazdırcaz

    newDers.kredi = kredi; // yukardakiler ile aynı şeyleri tekrarlıyoruz

    printf("Dersin Kredisi:%d\n", newDers.kredi);
    newDers.puan = puan;
    printf("Dersin Puani:%d\n", newDers.puan);

    return newDers; // newDers i döndürüyoruz
}

Ogrenci returningOgrenci(char *ogrAdi, char *ogrSoyadi, char *bolumu, float ortalama, Ders *aldigiDersler, int dersSayisi)
{
    Ogrenci newOgrenci; // iisim veriyoruz

    newOgrenci.ogrAdi = (char *)malloc(256 * sizeof(char)); // Ogrenci adını burda malloc foknsiyonumuz ile bellekte yer ayırıyoruz projede 256 boyut demiş
    strcpy(newOgrenci.ogrAdi, ogrAdi);                      // strcpy fonksiyonumuz ile ogrAdını newOgrenci e atıyoruz

    printf("Ogrencinin Adi :%s\n", newOgrenci.ogrAdi); // burda ogrAdını yazdırıoyurz
    newOgrenci.ogrSoyadi = (char *)malloc(256 * sizeof(char));
    strcpy(newOgrenci.ogrSoyadi, ogrSoyadi);
    printf("Ogrencinin Soy Adi :%s\n", newOgrenci.ogrSoyadi);

    newOgrenci.bolumu = (char *)malloc(256 * sizeof(char));
    strcpy(newOgrenci.bolumu, bolumu);
    printf("Ogrencinin bolumu :%s\n", newOgrenci.bolumu);

    newOgrenci.ortalama = ortalama;
    printf("Ogrencinin ortalamasi :%3f\n", newOgrenci.ortalama);

    newOgrenci.aldigiDersler = (Ders *)malloc(10 * sizeof(Ders)); // En kritik yer aldıgı dersler bir dizi ve ders türünde burada ders sayısı kadar alan ayırıyoruz malloc ile
    for (int i = 0; i < dersSayisi; ++i)                          // parametre olarak ders sayımızı aldık ve ders sayısı kadar for ile aldıgı dersler dizisini içinde geziyoruz
    {
        newOgrenci.aldigiDersler[i] = aldigiDersler[i]; // burda öncelikle aldıgıdersler[i] i newOgrenci.aldıgıDersleri atıyoruz yukarda yaptığımız gibi daha sonrasında assagada bilgileri yazdırıyoruz
        printf("Ogrencinin aldigi dersin adi:%s\n", newOgrenci.aldigiDersler[i].dersAdi);
        printf("Ogrencinin aldigi dersin kredisi :%d\n", newOgrenci.aldigiDersler[i].kredi);
        printf("Ogrencinin aldigi dersin puani: %d\n", newOgrenci.aldigiDersler[i].puan);
    }

    return newOgrenci; // return ile newOgrenci döndürüyoruz
}

void printİnfoOgrenci(Ogrenci ogrenci, int ogrDersSayisi)
{
    printf("********Ogrenci Bilgisi Yazdiriliyor**********\n"); // ggüzel görünmesi için bazı detaylar
    printf("Ogrenci Bilgileri:\n");
    printf("Ad: %s\n", ogrenci.ogrAdi);
    printf("Soyad: %s\n", ogrenci.ogrSoyadi);

    printf("Bolum: %s\n", ogrenci.bolumu);
    printf("Ortalama: %.3f\n", ogrenci.ortalama);

    printf("Aldigi Dersler:\n");
    for (int i = 0; i < ogrDersSayisi; ++i) // ders sayısı kadar dönüyoruz birden fazlaa almış olduğu ders olabilir
    {
        printf("Ders Adi: %s, Kredi: %d, Puan: %d\n", // yanyana bilgileri yazdırıyoruz
               ogrenci.aldigiDersler[i].dersAdi,
               ogrenci.aldigiDersler[i].kredi,
               ogrenci.aldigiDersler[i].puan);
    }
    printf("------------------------------\n");
}

void printİnfoOgrenciArray(Ogrenci *ogrencilerinDizisi, int dizidekiOgrenciSayisi, int dersSayisi)
{                                                   // ogrencilerden oluşturdugumuz bir diziyi bu fonksiyonda geziyoruz ve ogrencilerin ve aldıgı derslerin bilgilerini yazdırıyyoruz
    for (int i = 0; i < dizidekiOgrenciSayisi; ++i) // dizideki ogrenci sayısını parametre olarak atıyoruz
    {
        printf("------------Ogrenci %d----------------\n", i + 1); // i+1 diyerek dizideki ogrenci sayısını önce yazdırıyoruz daha dogrusu kacıncı ogrenci oldugu
        printf("Ad: %s\n", ogrencilerinDizisi[i].ogrAdi);
        printf("Soyad: %s\n", ogrencilerinDizisi[i].ogrSoyadi);
        printf("Bolumu: %s\n", ogrencilerinDizisi[i].bolumu);
        printf("Ortalamasi: %.3f\n", ogrencilerinDizisi[i].ortalama);

        printf("Aldigi Dersler:\n");
        for (int j = 0; j < dersSayisi; ++j) // ders sayısını yine parametre olarak aldıgımız icin isimiz kolay  ders sayısı kadar dönüuoruz
        {
            printf("Ders Adi: %s, Kredi: %d, Puan: %d\n",
                   ogrencilerinDizisi[i].aldigiDersler[j].dersAdi,
                   ogrencilerinDizisi[i].aldigiDersler[j].kredi,

                   ogrencilerinDizisi[i].aldigiDersler[j].puan);
        }
    }
}

float calculatingArithmatic(char *dersAdi, Ogrenci *ogrencilerinDizisi, int dizidekiOgrenciSayisi, int dersSayisiKac)
{

    int totalPuan = 0;                              // totalPuan adında da bi degisken olusturuyoruz totalPuanı tutmak için
    for (int i = 0; i < dizidekiOgrenciSayisi; ++i) // arraydaki ogrenci sayısı kadar
    {
        for (int j = 0; j < dersSayisiKac; ++j) // Ders sayısı kadar dönüyoruz again
        {
            if (strstr(ogrencilerinDizisi[i].aldigiDersler[j].dersAdi, dersAdi) != 0)
            {                                                             // burda farklı olarak strstr fonksiyonumuz var bu fonksiyon sol tarafta yazdıgımız ders adı ile parametre olarak aldıgımız ders adı dogru mu diye konrtol ediyoruz
                totalPuan += ogrencilerinDizisi[i].aldigiDersler[j].puan; // puanları toplamak için += dedik
            }
        }
    }
    if (dizidekiOgrenciSayisi == 0) // ogrenciSayısı eger 0 olursa aritmatik hesaplayamayız
    {
        return -1; //-1 diyorum 0 değil 0 da bir deger olabilir bundan -1
    }

    return (float)totalPuan / dizidekiOgrenciSayisi; // type casting double
}

float calculatingStandardDeviation(char *dersAdi, Ogrenci *ogrencilerinDizisi, int ogrenciSayisi, int dersSayisiKac)
{
    float totalPuan = 0; // aynı sekilde aritmatik ortalama hesaplarken nasıl yazdıysak ayynı
    float courseAverage = calculatingArithmatic(dersAdi, ogrencilerinDizisi, ogrenciSayisi, dersSayisiKac);
    // standart sapma hesaplarken dersin ortalaması lazım bundan dolayı dersin ortalamasını courseAverage a atıyoruz
    int senkronize = 0; // Eğer bir ders bulunursa bu değerii 1 yapacağız

    for (int i = 0; i < ogrenciSayisi; ++i)
    {
        for (int j = 0; j < dersSayisiKac; ++j)
        {
            if (strstr(ogrencilerinDizisi[i].aldigiDersler[j].dersAdi, dersAdi) != 0)
            {
                totalPuan += pow(ogrencilerinDizisi[i].aldigiDersler[j].puan - courseAverage, 2);
                senkronize = 1; // Ders bulundu mesela 1 olcak
                break;          // Dersi bulduktan sonra iç döngüden çık
            }
        }
    }

    if (!senkronize) // senkronize eger 0 olursa yani eslesmezse herhangi bir dersin standart sapması hesaplanamaz yani kod calısır
    {
        printf("Bir dersle eslesmedi Standart sapma hesaplanamaz \n");
        return -1;
    }

    float standardDeviation = sqrt(totalPuan / ogrenciSayisi); // sqrt ile karekök e alıyoruz ve standart sapmayı sonucunu standartDeviation a atıyoruz

    if (ogrenciSayisi > 1) // ogrenci sayıssı 1 den fazla olmalı ki standart sapma hesaplansın bunun konrtolu
    {
        return standardDeviation;
    }
    else
    {
        return -1; // değilse -1 döndürsün 0 değil çünkü standart sapma 0 olabilir
    }
}

void aboveAverageOgrenci(char *dersAdi, Ogrenci *ogrencilerinDizisi, int ogrenciSayisi, int dersSayisiKac)
{ // dersin ortalamasından daha yüksek almış ögrencilerin bilgilerinni yazdırıyoruz

    float courseAveragee = calculatingArithmatic(dersAdi, ogrencilerinDizisi, ogrenciSayisi, dersSayisiKac);
    // dersin ortalaması lazım bana bundan dolayyı daha önce hesapladıgımız aritmatik ortalama fonksiyonunu çağırıp courseAveragee atıyoruz
    printf("Dersin Adi  : %s\n", dersAdi);               // hangi dersi istiyoruz parametre olarak gelen degeri yazıyoruz yani dersin adını
    printf("Ortalama Puani  :  %.3f\n", courseAveragee); // dersin ortalamasını yazıyoruz
    printf("******************************\n");          // outputumuzun daha düzenli oluşması için
    printf("Dersin Ortalama Puanindan Daha Yuksek Not Almis Ogrenciler :\n");

    for (int i = 0; i < ogrenciSayisi; ++i) // Parametre olarak aldıgımız ogrenci sayısı kadar for u dönüyoruz
    {
        for (int j = 0; j < dersSayisiKac; ++j) // aynı sekilde parametre olarak aldıgımız dersSayısıKac kadarr dönüyoruz ders sayısı kadar döndürmemiz lazım yoksa fazladan olursa null degerler alırız
        {
            if (strstr(ogrencilerinDizisi[i].aldigiDersler[j].dersAdi, dersAdi) != 0 &&
                ogrencilerinDizisi[i].aldigiDersler[j].puan > courseAveragee)
            { // aynı sekilde strstr fonksiyonu ile parametre olarak aldııgımız ders ile ogrencinin aldıgı ders uyusuyor mu konrtol ediyoruz bunun yanı sıra aldıgı puan dersin ortalamasından daha yüksek mi onu konrol ediyorruz
                printf("Ogrenci Adi: %s, Puan: %d\n", ogrencilerinDizisi[i].ogrAdi, ogrencilerinDizisi[i].aldigiDersler[j].puan);
            } // eger dersler uyusuyor ve aldıgı puan dersin ortalamasından yüksekse ogrencinin adı ve aldıgı puanı yazıyoruz
        }
    }
    printf("************************************\n");
}
float calculateKovaryans(Ders *dersler1, Ders *dersler2, int dersSayisi)
{
    // kovaryans hesaplamak icin 2 vektöre ihtiyacım var ve bir size degerine
    float kovaryans = 0.0;  // kovaryans adında bir degisken tanımlıyoruz
    float totalPuan1 = 0.0; // totalpuanları tanımlıyoruz ayrı ayrı
    float totalPuan2 = 0.0;
    float totalPuan4 = 0.0;
    for (int i = 0; i < dersSayisi; ++i) // ders sayısı kadar dönüyoruz
    {
        totalPuan1 += dersler1[i].puan; // totalPuan1 e derslerde alınan puanlarımızı toplayarak tutuyoruz

        totalPuan2 += dersler2[i].puan; // totalPuan2 e derslerde alınan puanlarımızı toplayarak tutuyoruz
        totalPuan4 += dersler1[i].puan * dersler2[i].puan;
    }

    float average1 = totalPuan1 / dersSayisi; // total puanları ogrenci sayısına  bölüyoruz
    float average2 = totalPuan2 / dersSayisi;
    float average3 = totalPuan4 / dersSayisi;
    // Kovaryansı hesapla

    kovaryans = average3 - average2 * average1; // buldugumuz kovaryansı size a bölüyoruz  ve kovaryansı döndürüyoruz
    return kovaryans;                           // kovaryansı return yapıyoruz
}

void ogrenciBilgileriniDosyayaYazan(Ogrenci *ogrenciArray, int size12, char *dosyaAdi)
{
    FILE *dosya = fopen(dosyaAdi, "w"); // dosyayı yazmak için w modunda acıyoruz

    if (!dosya) // dosya acılıyor mu kontrol ediyoruz burdaa
    {

        fprintf(stderr, "dosya acilamadi: %s\n", dosyaAdi);
        exit(EXIT_FAILURE); // programı herhangi bir hata durumunda sonlandırır
    }
    for (int i = 0; i < size12; ++i) // ogrenci dizimizdeki ogrenci kadar dönüyoruz zaten parametre olarak aldık isimiz easy
    {
        fprintf(dosya, "%s %s %s %.3f\n", ogrenciArray[i].ogrAdi, ogrenciArray[i].ogrSoyadi, ogrenciArray[i].bolumu, ogrenciArray[i].ortalama);
    } // yukarda dosyaya ogrenci bilgilerini yazıyoruz ve fprintf kullanıyoruz çünkü dosyayı yazdırırken fprintf kullanılır

    printf("Ogrenci Bilgileri Dosyaya Yazilmistir \n"); // islem tamamlandıgında bana bi bildiri versin diiye

    fclose(dosya); // dosyamızı kapatıyoruz burda da
}
