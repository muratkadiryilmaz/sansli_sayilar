/*  Murat Kadir Yılmaz - Computer Engineering Student
    Proje Adı: Şanslı Sayılar Oyunu
    -------------------------------------------

    1–100 arasında 25 farklı sayı rastgele seçilir.  
    Kullanıcı tahmin hakkını belirler ve sayıları girmeye başlar.  
    Program doğru tahminleri, sıralı şanslı sayıları ve 10 üzerinden puanı gösterir.  
    Oyun sonunda tekrar oynama veya çıkış seçeneği sunulur.
*/
// --- Kütüphaneler:
#include <stdio.h> // Giriş/çıkış fonksiyonları (printf, scanf)
#include <stdlib.h> // rand(), srand() için
#include <time.h> // time() fonksiyonu için

int main() {

    srand(time(NULL)); // Rastgele sayı üretimini zaman temelli başlat

    int secim; // Kullanıcının menüdeki seçimi (1: tekrar, 2: çıkış)

    // --- Karşılama mesajı ---
    printf("=== SANSLI SAYILAR OYUNU ===\n");
    printf("Sansli sayilar seciliyor...\n");
    printf("----------------------------------\n");

do { 
    // --- Değişken tanımlamaları ---
    int sanslisayilar[25]; // Rastgele oluşturulacak 25 şanslı sayı
    int tahminsayisi; // Kullanıcının kaç tahminde bulunacağı
    int sayac = 0; // Doğru tahmin sayısı
    float puan = 0; // Hesaplanacak puan

    // --- Rastgele 25 farklı sayı üret ---
    for(int i = 0; i < 25; i++){
    int sayi, varmi;
    do {
        sayi = rand () % 100 + 1; // 1–100 arası sayı üret
        varmi = 0; // Sayının daha önce üretilip üretilmediğini kontrol et

        for(int j=0; j < i; j++){
            if(sanslisayilar[j] == sayi){
            varmi = 1; // Eğer aynı sayı varsa
            break; // Tekrar üret işaretle
        }
    }
    } while (varmi); // Tekrarlıysa yeniden üret
        sanslisayilar[i] = sayi; // Farklıysa diziye ekle
    }
    
    // --- Kullanıcıdan tahmin hakkı al --- 
do {
    printf("Bir tahmin sayisi giriniz (1-25): ");
    scanf("%d", &tahminsayisi);

    if (tahminsayisi <= 0 || tahminsayisi > 25) {
        printf("Gecersiz giris! Tahmin sayisi 1 ile 25 arasinda olmali.\n");
    }
} while (tahminsayisi <= 0 || tahminsayisi > 25);
    
    // --- Tahmin girişleri ---
    printf("----------------------------------\n");
    printf("%d tahmin hakkiniz bulunmaktadir.\n",tahminsayisi);
    printf("1-100 arasinda tahminde bulunun.\n");
    int tahmin[tahminsayisi]; // Kullanıcının tahmin dizisi

    for(int i = 0; i < tahminsayisi; i++) {
        int tekrarmi; // tekrar girilecek mi
    do {
        tekrarmi = 0; // her döngü başında sıfırla

        printf("%d. tahmini giriniz: ", i + 1);
        scanf("%d", &tahmin[i]);

        // 1-100 aralığı kontrolü
        if (tahmin[i] < 1 || tahmin[i] > 100) {
            printf("Gecersiz sayi! Lutfen 1 ile 100 arasinda bir sayi giriniz.\n");
            tekrarmi = 1;
            continue; // başa dön
        }

        // aynı tahmini iki kez girme kontrolü
        for (int j = 0; j < i; j++) {
            if (tahmin[j] == tahmin[i]) {
                printf("Bu sayiyi zaten girdiniz, farkli bir sayi giriniz.\n");
                tekrarmi = 1;
                break; // içteki for'dan çık
            }
        }

    } while (tekrarmi); // eğer tekrarmi == 1 ise aynı i için tekrar iste
}
     
        // --- Doğru tahminleri kontrol et ---
        for(int i = 0; i < tahminsayisi; i++){
            for(int j = 0; j < 25; j++){
            if(tahmin[i] == sanslisayilar[j]){ // Tahmin, şanslı sayı ile eşleşirse
                sayac++; // Doğru sayacı artır
                break;  // Aynı tahmini bir kez say
            }
        }
    }
    
    // --- Şanslı sayıları küçükten büyüğe sırala ---
    printf("----------------------------------\n");
    printf("Sansli sayilar (kucukten buyuge):\n");

    for(int i = 0; i < 24; i++){
        for(int j = i+1; j < 25; j++){
            if(sanslisayilar[i] > sanslisayilar[j]){
                int tutucu = sanslisayilar[i]; // Geçici değişken ile yer değiştirme
                sanslisayilar[i] = sanslisayilar[j];
                sanslisayilar[j] = tutucu;
            }
        }
    }
    
    // --- Şanslı sayıları yazdır ---
    for(int i = 0; i < 25; i++){
        printf("%d ",sanslisayilar[i]);
    }

    printf("\n");
    // --- Tahmin Sonuçları:
    // --- Tahminlerin hepsi doğruysa ---
    if(sayac == tahminsayisi){
        printf("Tebrikler! tum tahminleriniz dogru.\n");
        puan = 10.0;
        printf("Puaniniz: %.1f / 10\n", puan);
    }

    // --- Doğru tahmin varsa ---
    else if(sayac > 0){
    printf("%d sayi dogru bildiniz. \n",sayac);
    printf("Dogru sayilar: ");

    // --- Doğru tahmin edilen sayıları göster ---
    for(int i = 0; i < tahminsayisi; i++){
        for(int j = 0; j < 25; j++){
            if(tahmin[i] == sanslisayilar[j]){
                printf("%d ",tahmin[i]);
                }   
            }   
        }
        
        // --- Puan hesaplama ---
        puan = ((float)sayac / tahminsayisi) * 10.0;
        printf("\nPuaniniz: %.1f / 10\n", puan);
    }
        
    // --- Hiç doğru tahmin yoksa ---
    else{
        printf("Dogru tahmin bulunamadi.\n");
        printf("Puaniniz: 0 / 10\n");
    }

    // --- Menü seçenekleri ---
do {
    printf("----------------------------------\n");
    printf("1 - Tekrar oyna\n");
    printf("2 - Oyunu sonlandir\n");
    printf("Seciminiz: ");
    scanf("%d",&secim);
    printf("----------------------------------\n");

    if(secim != 1 && secim != 2){
        printf("Gecersiz secim! Lutfen 1 veya 2 giriniz.\n");
        }
    } while (secim != 1 && secim != 2);
    
} while (secim == 1); // Oyunu tekrar başlat

    printf("\nOyun sona erdi. Iyi gunler!\n\n");
    
    return 0; // Programı sonlandır
}
