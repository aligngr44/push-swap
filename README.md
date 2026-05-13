*This project has been created as part of the 42 curriculum by algungor, bigungor.*

# Push_swap

## Açıklama (Description)

Push_swap, iki adet stack (`a` ve `b`) kullanarak, sınırlı komut seti ile sayıları **artan sırada sıralamayı** amaçlayan bir algoritma projesidir.

Bu projede amaç:

* Verilen sayıları en **az operasyon** ile sıralamak
* Farklı algoritmalar geliştirerek performans karşılaştırması yapmak
* **Algoritma karmaşıklığını (complexity)** pratikte anlamaktır

Önemli nokta:
Bu projede performans, klasik zaman karmaşıklığı ile değil, üretilen **operasyon sayısı** üzerinden ölçülür .

---

## Kurulum ve Kullanım (Instructions)

### Derleme

```bash
make
```

Makefile komutları:

```bash
make
make clean
make fclean
make re
```

---

### Çalıştırma

```bash
./push_swap [opsiyon] sayılar
```

Örnek:

```bash
./push_swap 2 1 3
```

---

### Algoritma seçimi

```bash
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1
```

---

### Benchmark modu

```bash
./push_swap --bench 4 2 1 3
```

Bu mod:

* disorder değeri
* kullanılan algoritma
* toplam operasyon sayısı
* her komutun sayısı

bilgilerini **stderr** üzerinden verir .

---

## Kullanılan Komutlar

* `sa`, `sb`, `ss`
* `pa`, `pb`
* `ra`, `rb`, `rr`
* `rra`, `rrb`, `rrr`

Bu komutlar stack üzerinde işlem yaparak sıralamayı sağlar.

---

## Algoritmalar

Bu projede 4 farklı strateji bulunmaktadır.

### 1. Simple Algorithm (O(n²))

Küçük veri setleri için kullanılan temel algoritmadır.

* Küçük inputlar (özellikle ≤5)
* Basit min/max extraction yaklaşımı
* Düşük maliyetli ve stabil

---

### 2. Medium Algorithm (O(n√n))

Chunk-based yaklaşım kullanılır.

* Veriler parçalara (chunk) bölünür
* Uygun aralıktaki elemanlar stack B’ye gönderilir
* Sonrasında tekrar stack A’ya yerleştirilir

Orta büyüklükte inputlar için optimize edilmiştir.

---

### 3. Complex Algorithm (O(n log n))

Radix sort adaptasyonu kullanılır.

* Değerler önce indexlenir
* Bit seviyesinde sıralama yapılır:

  ```
  (index >> bit) & 1
  ```
* Büyük veri setlerinde en iyi performansı verir

---

### 4. Adaptive Algorithm

Input durumuna göre algoritma seçimi yapılır.

#### Disorder nedir?

Disorder, verinin ne kadar karışık olduğunu gösteren bir değerdir (0 - 1 arası) .

#### Seçim mantığı:

| Disorder  | Algoritma |
| --------- | --------- |
| < 0.2     | Simple    |
| 0.2 - 0.5 | Medium    |
| ≥ 0.5     | Complex   |

Bu sayede her input için en uygun algoritma seçilir.

---

## Hata Yönetimi

Aşağıdaki durumlarda program:

```bash
Error
```

yazdırır:

* Geçersiz input
* Duplicate sayılar
* Integer overflow
* Format hataları

---

## Performans Hedefleri

### 100 sayı

* < 2000 → geçer
* < 1500 → iyi
* < 700 → mükemmel

### 500 sayı

* < 12000 → geçer
* < 8000 → iyi
* < 5500 → mükemmel 

---

## Teknik Detaylar

* Dil: C
* Veri yapısı: Linked List (stack)
* Global değişken yok (Norm uyumlu)
* Memory leak yok
* Modüler yapı:

  * parsing
  * stack işlemleri
  * algoritmalar
  * yardımcı fonksiyonlar

Norm kurallarına tamamen uyulmuştur .

---

## Kaynaklar (Resources)
* YouTube algoritma anlatımları (Radix sort, chunk sorting)
* Stack ve linked list üzerine eğitim içerikleri
* Github mantık akışı
* Stack (data structure)
* Sorting algorithms 
* Radix sort 
* Algorithm complexity (Big-O)

---

## AI Kullanımı

AI araçları şu amaçlarla kullanılmıştır:

* Algoritma mantığını anlamak
* Debug sürecinde yardımcı olmak
* Bitwise işlemleri açıklamak
* README dokümantasyonu oluşturmak

Kodlar doğrudan AI’dan alınmamış, tamamen anlaşılmış ve manuel olarak yazılmıştır .

---

## Katkıda Bulunanlar

* **bigungor** → algoritmaların tasarımı ve implementasyonu
* **algungor** → sistem entegrasyonu, testler ve geliştirmeler

Her iki geliştirici de proje üzerindeki tüm kısımları anlayacak seviyede katkı sağlamıştır.
