

```markdown
# 🎲 Şanslı Sayılar Oyunu (C)

📅 **Tarih:** 03.02.2026  
🔗 **GitHub:** [github.com/muratkadiryilmaz/sansli-sayilar-oyunu](https://github.com/muratkadiryilmaz/sansli-sayilar-oyunu)  
🔗 **LinkedIn:** https://www.linkedin.com/in/murat-kadir-yılmaz-148b8b387/  
📄 **C dilinde yazılmış rastgele sayı tahmin oyunu projesi.**

---

## 🎯 Proje İçeriği
- Program 1–100 arasında **25 farklı rastgele sayı** üretir.  
- Kullanıcı tahmin hakkını belirler (1–25 arası).  
- Tahminler alınır, doğru tahminler sayılır.  
- Program sonucu ve 10 üzerinden puanı gösterir.  
- Tekrar oynama veya çıkış seçeneği sunar.

---

## ⚙️ Nasıl Çalışır
1. Program rastgele 25 sayı üretir.  
2. Kullanıcı tahmin sayısını girer.  
3. Her tahmin için:
   - 1–100 dışında sayı girilirse uyarı verir.  
   - Aynı tahmin girilirse tekrar ister.  
4. Program doğru tahminleri kontrol eder, puanı hesaplar.  
5. Tüm sonuçları ekranda gösterir.

---

## 🧩 Kullanılan Teknolojiler
- C  
- stdio.h  
- stdlib.h  
- time.h  

---

# 🌍 English Version

# 🎲 Lucky Numbers Game (C)

📅 **Date:** February 3, 2026  
🔗 **GitHub:** [github.com/muratkadiryilmaz/sansli-sayilar-oyunu](https://github.com/muratkadiryilmaz/sansli-sayilar-oyunu)  
📄 **A simple number guessing game written in C.**

---

## 🎯 Project Overview
- Generates 25 unique random numbers between 1 and 100.  
- User selects number of guesses (1–25).  
- Program compares guesses with lucky numbers and calculates score (out of 10).  
- Displays correct guesses and offers replay or exit.

---

## ⚙️ How It Works
- 25 random numbers are generated using `rand()` and `srand(time(NULL))`.  
- User enters guesses within 1–100.  
- Invalid or repeated inputs are handled gracefully.  
- Final results and score are displayed.

---

🧩 **Technologies Used:**  
C, stdio.h, stdlib.h, time.h

```bash
gcc sansli_sayilar.c -o sansli_sayilar
./sansli_sayilar
