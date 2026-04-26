# CLASH-SEA BLUBUP
## Game 2D Berbasis C++ dengan Library Graphics.h

---

## Identitas Mahasiswa

| Atribut         | Keterangan                                           |
|-----------------|------------------------------------------------------|
| **Nama**        | Devi Putri Sekar Arum                                |
| **NRP**         | 5024241049                                           |
| **Mata Kuliah** | Pemrograman Lanjut (EC234201)                        |
| **Program Studi** | S-1 Teknik Komputer                               |


---

## Daftar Isi

1. [Deskripsi Game](#1-deskripsi-game)
2. [Latar Belakang](#2-latar-belakang)
3. [Konsep dan Mekanisme Gameplay](#3-konsep-dan-mekanisme-gameplay)
4. [Aset Game](#4-aset-game)
5. [Arsitektur Kelas (Class Architecture)](#5-arsitektur-kelas-class-architecture)
6. [Penjelasan Kode Program](#6-penjelasan-kode-program)
7. [Logika Permainan](#7-logika-permainan)
8. [Cara Menjalankan Program](#8-cara-menjalankan-program)
9. [Cara Bermain](#9-cara-bermain)
10. [Analisis Teknis](#10-analisis-teknis)
11. [Batasan Sistem](#11-batasan-sistem)
12. [Struktur Direktori](#12-struktur-direktori)

---

## 1. Deskripsi Game

**Clash-Sea Blubup** merupakan permainan berbasis antarmuka grafis 2D yang dikembangkan menggunakan bahasa pemrograman C++ terintegrasi dengan pustaka grafis `graphics.h`. Permainan ini mengangkat skenario penyelamatan karakter bernama **Ruby**, seorang manusia mungil yang terjun bebas dari pesawat tempur dan menghadapi bahaya samudra lepas. Pemain berperan sebagai kapten kapal penyelamat yang bertanggung jawab untuk menangkap Ruby sebelum Ruby dimangsa oleh ikan predator yang mengintai di bawah permukaan laut.

Proyek ini dirancang sebagai implementasi nyata dari konsep-konsep fundamental dalam bidang pemrograman berorientasi objek (object-oriented programming), rendering grafik 2D secara real-time, serta sinkronisasi audio-visual. Seluruh entitas permainan direpresentasikan sebagai kelas-kelas independen, yang masing-masing memiliki atribut dan metode perilaku tersendiri sesuai prinsip enkapsulasi.

---

## 2. Latar Belakang

Perkembangan teknologi digital telah memicu inovasi pesat di industri permainan interaktif. Game tidak hanya berfungsi sebagai media rekreasi, tetapi juga mampu merangsang keterampilan kognitif, motorik, dan ketangkasan pengambilan keputusan. Dalam konteks akademik, pengembangan game menjadi wahana implementasi teori object-oriented programming dan graphic rendering untuk memvisualisasikan simulasi interaktif secara nyata.

Penggunaan pustaka `graphics.h` bersama bahasa C++ memungkinkan proses manipulasi bitmap, collision detection, dan buffer swapping dilakukan dengan kontrol yang mendalam. Implementasi game **Clash-Sea Blubup** hadir sebagai contoh nyata integrasi konsep-konsep tersebut dalam skenario penyelamatan karakter di lingkungan laut yang dinamis, sekaligus menjadi prototipe interaktif yang mendemonstrasikan pengolahan citra raster sederhana, double buffering, dan sinkronisasi efek audio dengan respons visual.

---

## 3. Konsep dan Mekanisme Gameplay

### 3.1 Cerita

> *"Ruby's life is in your hands!"*

Dalam Clash-Sea Blubup, pemain berperan sebagai kapten kapal penyelamat yang bertanggung jawab menangkap Ruby, seorang manusia pemberani yang terjun payung dari pesawat tempur yang melintas di angkasa. Di bawah permukaan laut, ikan-ikan predator lapar mengintai untuk memangsa Ruby apabila luput dari tangkapan kapal.

### 3.2 Mekanisme Inti

| Peristiwa                         | Konsekuensi                                        |
|-----------------------------------|----------------------------------------------------|
| Kapal berhasil menangkap Ruby     | Skor pemain bertambah +1, suara "poin" diputar     |
| Ruby gagal ditangkap, dimakan ikan| Skor ikan bertambah +1, ikan tumbuh lebih besar, suara "eat" diputar |
| Skor ikan mencapai 10 poin        | Permainan berakhir (Game Over)                     |

### 3.3 Alur Permainan

```
[Mulai Program]
      |
      v
[Welcome Screen]
  |         |
[PLAY]     [HOW]
  |         |
  |    [How To Play Screen]
  |         |
  v         v
   [runGame() -- Game Loop Utama]
        |
   [Deteksi Tabrakan]
   [Perbarui Skor]
   [Perbarui Animasi]
        |
   [Skor Ikan >= 10?]
   |              |
  [Ya]           [Tidak]
   |              |
[Game Over]   [Lanjutkan Loop]
   |
[Tampilkan Skor Akhir]
   |
[Selesai]
```

---

## 4. Aset Game

Seluruh aset permainan terdiri dari file gambar berformat GIF dan file audio berformat WAV atau MP3. Aset gambar ditempatkan pada folder `img/`, sedangkan file audio ditempatkan pada direktori root proyek.

### 4.1 Aset Visual

| No. | Nama File                                          | Keterangan                                    |
|-----|----------------------------------------------------|-----------------------------------------------|
| 1   | `img/sea.gif`                                      | Latar belakang laut                           |
| 2   | `img/jet.gif`                                      | Pesawat tempur (berwarna)                     |
| 3   | `img/jetbw.gif`                                    | Pesawat tempur (hitam putih, masker)          |
| 4   | `img/rubydrop.gif`                                 | Animasi Ruby jatuh bebas (berwarna)           |
| 5   | `img/rubydrop-bw.gif`                              | Animasi Ruby jatuh bebas (masker)             |
| 6   | `img/rubypar.gif`                                  | Animasi Ruby berparasut (berwarna)            |
| 7   | `img/rubypar-bw.gif`                               | Animasi Ruby berparasut (masker)              |
| 8   | `img/die.gif`                                      | Animasi kehancuran Ruby (berwarna)            |
| 9   | `img/diebw.gif`                                    | Animasi kehancuran Ruby (masker)              |
| 10  | `img/ship.gif`                                     | Kapal penyelamat (berwarna)                   |
| 11  | `img/shipbw.gif`                                   | Kapal penyelamat (masker)                     |
| 12  | `img/fish.gif`                                     | Animasi ikan (berwarna, arah normal)          |
| 13  | `img/fishbw.gif`                                   | Animasi ikan (masker, arah normal)            |
| 14  | `img/fishmirror.gif`                               | Animasi ikan (berwarna, arah cermin)          |
| 15  | `img/fishbw-mirror.gif`                            | Animasi ikan (masker, arah cermin)            |
| 16  | `img/gui.gif`                                      | Layar sambutan (Welcome Screen)               |
| 17  | `img/howtoplay.gif`                                | Layar panduan bermain (How To Play)           |
| 18  | `img/gameover.gif`                                 | Layar permainan selesai (Game Over)           |

### 4.2 Aset Audio

| No. | Nama File     | Keterangan                              |
|-----|---------------|-----------------------------------------|
| 1   | `click.wav`   | Efek suara klik tombol antarmuka        |
| 2   | `poin.wav`    | Efek suara saat Ruby berhasil ditangkap |
| 3   | `eat.wav`     | Efek suara saat ikan memangsa Ruby      |
| 4   | `sound.mp3`   | Musik latar yang diputar berulang       |

---

## 5. Arsitektur Kelas (Class Architecture)

Program dibangun menggunakan paradigma berorientasi objek dengan enam kelas utama yang merepresentasikan seluruh entitas dalam permainan.

```
+----------------+     +----------------+     +-----------------+
|      Sea       |     |   FighterJet   |     |     Bullet      |
+----------------+     +----------------+     +-----------------+
| - img          |     | - x, y, dx, dy |     | - x, y, speed   |
| - imgWidth     |     | - imgWidth     |     | - imgWidth      |
| - imgHeight    |     | - imgHeight    |     | - imgHeight     |
+----------------+     | - colorImg     |     | - drop[8]       |
| + draw()       |     | - maskImg      |     | - parasut[8]    |
+----------------+     +----------------+     | - indexBullet   |
                       | + draw()       |     +-----------------+
                       | + move()       |     | + draw(maxY)    |
                       | + isOutOf..()  |     | + move()        |
                       | + getGunX()    |     +-----------------+
                       | + getGunY()    |
                       +----------------+

+----------------+     +----------------+     +-----------------+
|     Kapal      |     |      Fish      |     |    Tbuffer      |
+----------------+     +----------------+     +-----------------+
| - x, y         |     | - x, y         |     | - img           |
| - width, height|     | - radius, dx   |     | - mask          |
| - colorShip    |     | - frames[5]    |     +-----------------+
| - maskShip     |     | - mirror[5]    |     (Struktur pembantu
+----------------+     | - indexFish    |      untuk pasangan
| + draw()       |     +----------------+      gambar + masker)
| + move(newX,..)| |   | + draw()       |
+----------------+     | + move(maxX)   |
                       | + grow()       |
                       | + reloadImages()|
                       +----------------+
```

### Fungsi Global Utama

| Fungsi                          | Keterangan                                                     |
|---------------------------------|----------------------------------------------------------------|
| `showWelcomeScreen()`           | Menampilkan layar sambutan, mengembalikan `bool` keputusan navigasi |
| `showHowToPlayScreen()`         | Menampilkan panduan cara bermain                               |
| `showGameOverScreen(p, f)`      | Menampilkan layar akhir permainan beserta skor akhir           |
| `checkCollision(...)`           | Menghitung deteksi tabrakan berbasis bounding box dan radius   |
| `runGame()`                     | Loop utama permainan; mengelola semua entitas dan logika skor  |
| `main()`                        | Titik masuk program; memutar musik latar dan mengorkestrasi alur|

---

## 6. Penjelasan Kode Program

### 6.1 Header dan Dependensi

```cpp
#include <windows.h>     // Windows API untuk multimedia
#include <graphics.h>    // Pustaka grafis 2D (BGI)
#include <stdlib.h>      // Manajemen memori (malloc, srand, rand)
#include <time.h>        // Inisialisasi seed acak
#include <conio.h>       // Deteksi input keyboard (kbhit)
#include <vector>        // Kontainer dinamis untuk bullets dan fishes
#include <algorithm>     // std::min, std::max untuk collision detection
#include <cstdio>        // snprintf untuk format teks skor
#include <mmsystem.h>    // mciSendString untuk kontrol audio
```

### 6.2 Kelas Sea

Kelas `Sea` bertanggung jawab memuat dan menampilkan gambar latar belakang laut.

```cpp
class Sea {
public:
    void *img;
    int imgWidth, imgHeight;

    Sea() {
        imgWidth  = getmaxx();
        imgHeight = getmaxy();
        img = malloc(imagesize(0, 0, imgWidth, imgHeight));
        readimagefile("img/sea.gif", 0, 0, imgWidth, imgHeight);
        getimage(0, 0, imgWidth, imgHeight, img);
    }

    void draw() {
        putimage(0, 0, img, COPY_PUT);
    }
};
```

**Penjelasan:** Konstruktor membaca file GIF ke dalam buffer memori menggunakan `readimagefile`, lalu `getimage` menyimpan piksel ke pointer `img`. Metode `draw()` menampilkan gambar ke layar dengan `putimage` menggunakan mode `COPY_PUT`.

### 6.3 Kelas FighterJet

Kelas `FighterJet` merepresentasikan pesawat tempur yang bergerak melintasi layar dan menjatuhkan Ruby.

```cpp
class FighterJet {
public:
    int x, y, dx, dy;
    int imgWidth, imgHeight;
    void *colorImg;
    void *maskImg;

    FighterJet(int startX, int startY, int startDx, int startDy) {
        // ... inisialisasi posisi dan ukuran ...
        // Memuat masker hitam putih (jetbw.gif) terlebih dahulu
        readimagefile("img/jetbw.gif", 0, 0, imgWidth, imgHeight);
        getimage(0, 0, imgWidth, imgHeight, maskImg);
        // Memuat gambar berwarna (jet.gif)
        readimagefile("img/jet.gif", 0, 0, imgWidth, imgHeight);
        getimage(0, 0, imgWidth, imgHeight, colorImg);
    }

    void draw() {
        putimage(x, y, maskImg, AND_PUT);   // Terapkan masker
        putimage(x, y, colorImg, OR_PUT);   // Tempelkan warna
    }

    void move() {
        x += dx;
        y += dy;
        if (y < 0 || y > 300) { dy = -dy; y += dy; } // Pantul vertikal
    }

    bool isOutOfWindow(int maxX) { return x > maxX; }
    int getGunX() { return x + 20; }
    int getGunY() { return y + 20; }
};
```

**Penjelasan:** Teknik masker AND/OR digunakan untuk menampilkan gambar transparan di atas latar belakang. Gambar hitam putih (`jetbw.gif`) berfungsi sebagai masker yang diterakan dengan `AND_PUT` untuk membersihkan area piksel, kemudian gambar berwarna diterakan dengan `OR_PUT` untuk mengisi piksel. Metode `getGunX()` dan `getGunY()` mengembalikan koordinat posisi penembakan Ruby.

### 6.4 Struktur Tbuffer

```cpp
struct Tbuffer {
    void *img;   // Pointer ke gambar berwarna
    void *mask;  // Pointer ke gambar masker hitam putih
};
```

**Penjelasan:** `Tbuffer` adalah struktur pembantu yang menyimpan pasangan pointer gambar (berwarna) dan masker (hitam putih) untuk setiap frame animasi. Struktur ini digunakan oleh kelas `Bullet` dan `Fish` untuk menampung array frame animasi.

### 6.5 Kelas Bullet

Kelas `Bullet` merepresentasikan Ruby yang jatuh, dengan tiga tahap animasi berdasarkan posisi ketinggiannya.

```cpp
class Bullet {
public:
    int x, y, speed;
    Tbuffer drop[8];     // 8 frame animasi jatuh bebas
    Tbuffer parasut[8];  // 8 frame animasi berparasut
    void *colorBullet3, *maskBullet3; // Animasi kehancuran

    void draw(int maxY) {
        if (y >= 0 && y <= maxY / 3) {
            // Zona atas: animasi jatuh bebas
            indexBullet = (indexBullet + 1) % 8;
            putimage(x, y, drop[indexBullet].mask, AND_PUT);
            putimage(x, y, drop[indexBullet].img,  OR_PUT);
        }
        else if (y > maxY / 3 && y <= maxY / 2 + 100) {
            // Zona tengah: animasi berparasut
            indexBullet = (indexBullet + 1) % 8;
            putimage(x, y, parasut[indexBullet].mask, AND_PUT);
            putimage(x, y, parasut[indexBullet].img,  OR_PUT);
        }
        else if (y > maxY / 2 + 100) {
            // Zona bawah: animasi kehancuran
            putimage(x, y, maskBullet3, AND_PUT);
            putimage(x, y, colorBullet3, OR_PUT);
        }
    }

    void move() { y += speed; }
};
```

**Penjelasan:** Logika animasi Ruby dibagi tiga zona vertikal. Pada sepertiga atas layar, Ruby menampilkan animasi jatuh bebas. Pada zona tengah, parasut terbuka. Pada zona paling bawah dekat permukaan laut, ditampilkan animasi kehancuran. Pergantian frame dilakukan dengan modulo 8 (`% 8`) untuk menghasilkan animasi siklik.

### 6.6 Kelas Kapal

Kelas `Kapal` merepresentasikan kapal penyelamat yang dikendalikan pemain.

```cpp
class Kapal {
public:
    int x, y, width, height;
    void *colorShip, *maskShip;

    void draw() {
        putimage(x, y, maskShip,  AND_PUT);
        putimage(x, y, colorShip, OR_PUT);
    }

    void move(int newX, int maxX) {
        // Batasi pergerakan agar kapal tidak keluar layar
        if (newX >= 0 && newX + width <= maxX) {
            x = newX;
        }
    }
};
```

**Penjelasan:** Kapal digerakkan berdasarkan koordinat X klik mouse. Metode `move()` menerima koordinat horizontal baru dan memvalidasi agar posisi kapal tidak melampaui batas layar kiri maupun kanan.

### 6.7 Kelas Fish

Kelas `Fish` merepresentasikan ikan predator yang bergerak horizontal dan dapat bertumbuh setiap kali memangsa Ruby.

```cpp
class Fish {
public:
    int x, y, radius, dx;
    Tbuffer frames[5];  // 5 frame animasi arah normal
    Tbuffer mirror[5];  // 5 frame animasi arah cermin

    void move(int maxX) {
        x += dx;
        if (x < 0 || x >= maxX - 100) { dx = -dx; } // Pantul di tepi
    }

    void grow() {
        radius += 2;
        if (radius > 20) radius = 30;
        reloadImages(); // Muat ulang gambar dengan ukuran lebih besar
    }

    void draw() {
        indexFish = (indexFish + 1) % 5;
        if (dx >= 0) {
            // Bergerak ke kanan: tampilkan frame normal
            putimage(x, y, frames[indexFish].mask, AND_PUT);
            putimage(x, y, frames[indexFish].img,  OR_PUT);
        } else {
            // Bergerak ke kiri: tampilkan frame cermin
            putimage(x, y, mirror[indexFish].mask, AND_PUT);
            putimage(x, y, mirror[indexFish].img,  OR_PUT);
        }
    }
};
```

**Penjelasan:** Ikan bergerak memantul di antara tepi kiri dan kanan layar. Arah gerak ikan (nilai `dx`) menentukan frame animasi yang ditampilkan, apakah frame normal atau frame cermin. Metode `grow()` meningkatkan nilai `radius` dan memuat ulang gambar dalam resolusi yang lebih besar melalui `reloadImages()`, sehingga ikan tampak membesar secara visual setiap kali berhasil memangsa Ruby.

### 6.8 Fungsi checkCollision

```cpp
bool checkCollision(int x1, int y1, int w1, int h1,
                    int x2, int y2, int r2) {
    int closestX = std::max(x1, std::min(x2, x1 + w1));
    int closestY = std::max(y1, std::min(y2, y1 + h1));
    int dx = x2 - closestX;
    int dy = y2 - closestY;
    return (dx * dx + dy * dy) <= (r2 * r2);
}
```

**Penjelasan:** Fungsi ini menerapkan deteksi tabrakan antara objek bujur sangkar (kapal/bounding box ikan) dan objek berbasis radius (Ruby). Titik terdekat pada bujur sangkar dihitung terhadap pusat lingkaran, kemudian jarak Euclidean dibandingkan dengan kuadrat radius. Penggunaan kuadrat jarak menghindari operasi `sqrt` yang mahal secara komputasi.

### 6.9 Fungsi showWelcomeScreen

```cpp
bool showWelcomeScreen() {
    // Menampilkan gui.gif dan mendeteksi klik mouse
    // Klik pada area [300-500, 320-390] --> PLAY --> return true
    // Klik pada area [300-500, 430-500] --> HOW --> return false
}
```

**Penjelasan:** Fungsi ini menampilkan layar sambutan dan mengembalikan nilai `true` apabila pemain memilih tombol PLAY, atau `false` apabila memilih tombol HOW (panduan bermain). Deteksi tombol dilakukan dengan memeriksa koordinat klik mouse terhadap area tombol yang telah ditentukan secara manual.

### 6.10 Fungsi runGame (Game Loop Utama)

```cpp
void runGame() {
    initwindow(800, 800, "Clash Sea");
    // Inisialisasi semua objek: Sea, Kapal, FighterJet[3],
    //   straightJets[2], vector<Bullet>, vector<Fish>[6]

    while (!kbhit() && !gameOver) {
        cleardevice();          // Hapus frame sebelumnya
        sea.draw();             // Gambar latar
        // Gambar dan gerakkan semua jet
        // Tembakkan Ruby setiap shootInterval frame
        // Gambar dan gerakkan semua bullets
        // Gambar dan gerakkan semua ikan

        kapal.draw();

        // Deteksi klik mouse -> gerakkan kapal
        // Deteksi tabrakan Ruby vs Kapal -> playerScore++
        // Deteksi tabrakan Ruby vs Ikan  -> fishScore++, fish.grow()

        if (fishScore >= 10) gameOver = true;

        delay(20);
        frameCounter++;
        swapbuffers();          // Tampilkan frame baru (double buffering)
    }
}
```

**Penjelasan:** Fungsi `runGame()` menjalankan game loop utama yang berulang selama tidak ada penekanan keyboard dan permainan belum berakhir. Setiap iterasi loop merupakan satu frame permainan. Teknik double buffering melalui `swapbuffers()` memastikan seluruh objek digambar terlebih dahulu ke buffer di balik layar sebelum ditampilkan, sehingga animasi tampak halus tanpa kedip (flicker).

### 6.11 Fungsi main

```cpp
int main() {
    mciSendString("open \"sound.mp3\" type mpegvideo alias bgm", NULL, 0, NULL);
    mciSendString("play bgm repeat", NULL, 0, NULL);  // Putar musik latar

    bool goToGame = showWelcomeScreen();
    if (!goToGame) showHowToPlayScreen();
    runGame();
    return 0;
}
```

**Penjelasan:** Titik masuk program memulai dengan memutar musik latar secara berulang menggunakan `mciSendString`. Kemudian menampilkan layar sambutan dan mengorkestrasi navigasi antarlayar sebelum memulai permainan.

---

## 7. Logika Permainan

### 7.1 Sistem Penembakan Ruby

Ruby ditembakkan dari pesawat setiap `shootInterval` frame (default 100 frame). Terdapat tiga pesawat yang bergerak dengan kecepatan acak (`dx` antara 5 hingga 9) dan variasi arah vertikal (`dy` antara 1 hingga 3), serta dua pesawat tambahan yang bergerak lurus horizontal. Setiap interval, satu Ruby baru ditambahkan ke dalam `vector<Bullet>` untuk masing-masing dari ketiga pesawat utama.

### 7.2 Animasi Bertahap Ruby

Posisi vertikal Ruby (`y`) menentukan animasi yang ditampilkan:

| Zona Vertikal           | Kondisi                        | Animasi         |
|-------------------------|--------------------------------|-----------------|
| Zona Atas (Langit)      | `0 <= y <= maxY / 3`           | Jatuh bebas     |
| Zona Tengah (Udara)     | `maxY/3 < y <= maxY/2 + 100`   | Berparasut      |
| Zona Bawah (Laut)       | `y > maxY/2 + 100`             | Kehancuran      |

### 7.3 Deteksi Tabrakan Ruby vs Kapal

Deteksi tabrakan antara Ruby dan kapal menggunakan perbandingan koordinat langsung:

```
Ruby tertangkap jika:
  bullets[i].y >= kapal.y       (Ruby sudah sejajar atau melewati kapal)
  bullets[i].x >= kapal.x       (Ruby tidak berada di kiri kapal)
  bullets[i].x <= kapal.x + kapal.width  (Ruby tidak berada di kanan kapal)
```

### 7.4 Deteksi Tabrakan Ruby vs Ikan

Deteksi tabrakan antara Ruby dan ikan menggunakan fungsi `checkCollision()` yang mengimplementasikan algoritma jarak terdekat antara titik dan persegi panjang:

```
Titik terdekat pada bounding box ikan:
  closestX = clamp(ruby.x, ikan.x - radius, ikan.x + radius)
  closestY = clamp(ruby.y, ikan.y - radius, ikan.y + radius)

Tabrakan terjadi jika:
  (ruby.x - closestX)^2 + (ruby.y - closestY)^2 <= radius^2
```

### 7.5 Sistem Pertumbuhan Ikan

Setiap kali ikan berhasil memangsa Ruby, metode `grow()` dipanggil:

```
radius baru = radius lama + 2
Jika radius > 20, maka radius = 30 (batas maksimum)
reloadImages() dipanggil untuk memuat ulang sprite ikan
  dengan dimensi yang lebih besar (imgWidth += radius, imgHeight += radius)
```

### 7.6 Kondisi Akhir Permainan

Permainan berakhir apabila `fishScore >= 10`. Layar Game Over ditampilkan beserta skor akhir pemain dan skor ikan.

---

## 8. Cara Menjalankan Program

### 8.1 Persyaratan Sistem

| Komponen           | Persyaratan                                                       |
|--------------------|-------------------------------------------------------------------|
| Sistem Operasi     | Microsoft Windows (32-bit atau 64-bit)                            |
| Compiler           | MinGW-w64 (GCC untuk Windows) atau Turbo C++ (lingkungan legacy) |
| Pustaka Grafis     | `graphics.h` (WinBGIm / BGI for Windows)                        |
| Pustaka Audio      | `mmsystem.h` (termasuk dalam Windows SDK, link dengan `winmm`)   |
| RAM                | Minimum 256 MB                                                    |
| Resolusi Layar     | Minimum 800 x 800 piksel                                          |

### 8.2 Instalasi WinBGIm (graphics.h)

Apabila menggunakan compiler MinGW dan Code::Blocks:

1. Unduh paket WinBGIm dari sumber resmi.
2. Salin file `graphics.h` dan `winbgim.h` ke direktori `include` MinGW.
   ```
   C:\MinGW\include\
   ```
3. Salin file `libbgi.a` ke direktori `lib` MinGW.
   ```
   C:\MinGW\lib\
   ```
4. Pastikan linker diarahkan ke pustaka berikut pada konfigurasi proyek:
   ```
   -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 -lwinmm
   ```

### 8.3 Konfigurasi Proyek di Code::Blocks

1. Buka Code::Blocks dan buat proyek baru bertipe **Console Application** dengan bahasa C++.
2. Tambahkan file `main.cpp` ke dalam proyek.
3. Buka menu **Project > Build Options > Linker Settings**.
4. Pada kolom **Other linker options**, tambahkan:
   ```
   -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 -lwinmm
   ```
5. Klik **OK** untuk menyimpan pengaturan.

### 8.4 Struktur Direktori yang Diperlukan

Sebelum menjalankan program, pastikan struktur direktori proyek telah terbentuk dengan benar:

```
CLASH-SEA-BLUBUP/
|-- main.cpp
|-- click.wav
|-- poin.wav
|-- eat.wav
|-- sound.mp3
|-- img/
    |-- sea.gif
    |-- jet.gif
    |-- jetbw.gif
    |-- rubydrop.gif
    |-- rubydrop-bw.gif
    |-- rubypar.gif
    |-- rubypar-bw.gif
    |-- die.gif
    |-- diebw.gif
    |-- ship.gif
    |-- shipbw.gif
    |-- fish.gif
    |-- fishbw.gif
    |-- fishmirror.gif
    |-- fishbw-mirror.gif
    |-- gui.gif
    |-- howtoplay.gif
    |-- gameover.gif
```

> **Perhatian:** Seluruh aset gambar dan audio harus berada pada lokasi yang tepat sesuai struktur di atas. Apabila salah satu aset tidak ditemukan, program akan mengalami error saat memuat gambar.

### 8.5 Kompilasi Melalui Command Line

Apabila menggunakan MinGW secara langsung melalui Command Prompt:

```bash
g++ main.cpp -o clash_sea_blubup.exe -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 -lwinmm
```

### 8.6 Kompilasi Melalui Code::Blocks

1. Buka proyek di Code::Blocks.
2. Tekan **F9** atau klik **Build > Build and Run**.
3. Program akan dikompilasi dan dijalankan secara otomatis.

### 8.7 Menjalankan Executable

Apabila file `.exe` telah berhasil dikompilasi:

1. Pastikan semua aset berada di direktori yang benar relatif terhadap file `.exe`.
2. Klik ganda pada file `clash_sea_blubup.exe`, atau jalankan melalui Command Prompt:
   ```bash
   .\clash_sea_blubup.exe
   ```
3. Jendela permainan berukuran 800x800 piksel akan terbuka secara otomatis.

---

## 9. Cara Bermain

### 9.1 Navigasi Layar

| Layar              | Tombol/Aksi                                    | Fungsi                      |
|--------------------|------------------------------------------------|-----------------------------|
| Welcome Screen     | Klik area PLAY (x: 300-500, y: 320-390)        | Memulai permainan langsung  |
| Welcome Screen     | Klik area HOW (x: 300-500, y: 430-500)         | Menampilkan panduan bermain |
| How To Play Screen | Klik tombol PLAY di bagian bawah               | Memulai permainan           |
| Game Over Screen   | Klik tombol EXIT (x: 300-500, y: 500-550)      | Menutup permainan           |

### 9.2 Kontrol Dalam Permainan

| Aksi           | Cara                                                      |
|----------------|-----------------------------------------------------------|
| Gerakkan kapal | Klik kiri mouse di posisi horizontal mana pun pada layar  |
| Keluar game    | Tekan sembarang tombol pada keyboard                      |

### 9.3 Strategi Bermain

1. Perhatikan posisi horizontal pesawat tempur untuk memprediksi lokasi jatuhnya Ruby.
2. Gerakkan kapal secara antisipatif, bukan reaktif, karena Ruby jatuh dengan kecepatan tetap.
3. Prioritaskan Ruby yang sudah memasuki zona parasut karena kecepatannya melambat.
4. Waspadai posisi ikan predator di zona bawah layar karena radius deteksi ikan akan semakin besar seiring bertambahnya skor ikan.

---

## 10. Analisis Teknis

### 10.1 Teknik Double Buffering

Permainan menggunakan `swapbuffers()` yang disediakan oleh WinBGIm untuk mengimplementasikan double buffering. Seluruh objek digambar ke buffer di balik layar pada setiap frame, kemudian buffer tersebut ditukar secara atomik dengan buffer yang ditampilkan. Teknik ini mengeliminasi artefak visual (flickering) yang umumnya terjadi apabila objek digambar langsung ke layar.

### 10.2 Teknik Masker AND/OR untuk Transparansi

Pustaka `graphics.h` tidak mendukung transparansi alfa secara native. Oleh karena itu, setiap sprite menggunakan dua gambar: gambar berwarna dan gambar masker hitam putih. Proses rendering dua langkah ini bekerja sebagai berikut:

```
Langkah 1: putimage(x, y, maskImg, AND_PUT)
  Piksel putih pada masker -> mempertahankan latar belakang (AND dengan 1 = tetap)
  Piksel hitam pada masker -> menghapus area sprite (AND dengan 0 = 0)

Langkah 2: putimage(x, y, colorImg, OR_PUT)
  Piksel berwarna pada gambar -> menambahkan warna sprite (OR dengan warna = warna)
  Piksel hitam pada gambar   -> tidak mengubah piksel yang sudah ada (OR dengan 0 = tetap)
```

Hasil akhirnya adalah sprite yang tampak transparan di atas latar belakang mana pun.

### 10.3 Manajemen Memori Gambar

Setiap gambar yang dimuat ke buffer menggunakan alokasi memori dinamis melalui `malloc` dengan ukuran yang dihitung oleh fungsi `imagesize()`. Pemindahan gambar dari file GIF ke buffer memori dilakukan melalui urutan perintah:

```
readimagefile() -> membaca file GIF ke layar sementara
getimage()      -> menyalin piksel dari layar ke buffer memori
putimage()      -> menyalin piksel dari buffer memori ke layar
```

### 10.4 Sinkronisasi Audio

Efek suara dikelola menggunakan antarmuka `mciSendString` dari Windows Multimedia API. Setiap efek suara ditutup terlebih dahulu sebelum dibuka kembali untuk menghindari konflik sumber daya audio:

```cpp
mciSendString("close poin", NULL, 0, NULL);
mciSendString("open \"poin.wav\" type waveaudio alias poin", NULL, 0, NULL);
mciSendString("play poin from 0", NULL, 0, NULL);
```

Musik latar diputar dengan parameter `repeat` agar berjalan berulang sepanjang sesi permainan.

### 10.5 Kompleksitas Algoritma

| Operasi                             | Kompleksitas        |
|-------------------------------------|---------------------|
| Render semua objek per frame        | O(j + b + f)        |
| Deteksi tabrakan Ruby vs Kapal      | O(b)                |
| Deteksi tabrakan Ruby vs Ikan       | O(b x f)            |
| Pertumbuhan ikan (reloadImages)     | O(f x 5 x 4)        |

Di mana `j` = jumlah jet, `b` = jumlah bullets, `f` = jumlah fish.

---

## 11. Batasan Sistem

1. Program hanya dapat dijalankan pada sistem operasi **Microsoft Windows** karena ketergantungan pada `mmsystem.h`, `windows.h`, dan WinBGIm.
2. Resolusi jendela tetap pada **800 x 800 piksel** dan tidak dapat diubah secara dinamis.
3. Skor ikan dibatasi maksimum **10 poin** sebagai kondisi Game Over.
4. Tidak terdapat fitur penyimpanan skor secara persisten (scoreboard online maupun lokal).
5. Tidak terdapat fitur multiplayer; permainan hanya mendukung satu pemain.
6. Kapal hanya dapat digerakkan secara **horizontal** menggunakan perangkat penunjuk (mouse).
7. Manajemen memori tidak menyertakan `free()` secara eksplisit untuk buffer gambar yang dialokasikan, yang dapat menjadi potensi kebocoran memori (memory leak) pada sesi permainan yang panjang.
8. Fungsi `reloadImages()` pada kelas `Fish` mengalokasikan blok memori baru setiap kali ikan bertumbuh tanpa membebaskan alokasi sebelumnya.

---

## 12. Struktur Direktori

```
CLASH-SEA-BLUBUP/
|
|-- main.cpp                  <- Kode sumber utama program
|-- clash_sea_blubup.exe      <- File executable hasil kompilasi
|
|-- click.wav                 <- Efek suara klik tombol
|-- poin.wav                  <- Efek suara penangkapan Ruby
|-- eat.wav                   <- Efek suara ikan memangsa Ruby
|-- sound.mp3                 <- Musik latar permainan
|
|-- img/                      <- Direktori aset visual
|   |-- sea.gif               <- Latar belakang laut
|   |-- jet.gif               <- Pesawat tempur (berwarna)
|   |-- jetbw.gif             <- Pesawat tempur (masker)
|   |-- rubydrop.gif          <- Ruby jatuh bebas (berwarna)
|   |-- rubydrop-bw.gif       <- Ruby jatuh bebas (masker)
|   |-- rubypar.gif           <- Ruby berparasut (berwarna)
|   |-- rubypar-bw.gif        <- Ruby berparasut (masker)
|   |-- die.gif               <- Kehancuran Ruby (berwarna)
|   |-- diebw.gif             <- Kehancuran Ruby (masker)
|   |-- ship.gif              <- Kapal penyelamat (berwarna)
|   |-- shipbw.gif            <- Kapal penyelamat (masker)
|   |-- fish.gif              <- Ikan arah normal (berwarna)
|   |-- fishbw.gif            <- Ikan arah normal (masker)
|   |-- fishmirror.gif        <- Ikan arah cermin (berwarna)
|   |-- fishbw-mirror.gif     <- Ikan arah cermin (masker)
|   |-- gui.gif               <- Layar sambutan
|   |-- howtoplay.gif         <- Layar panduan bermain
|   |-- gameover.gif          <- Layar permainan selesai
|
|-- README.md                 <- Dokumentasi proyek (file ini)
```

---

## Referensi

1. Stroustrup, B. (2013). *The C++ Programming Language* (4th ed.). Addison-Wesley.
2. Documentation WinBGIm -- Windows BGI Library. Colorado School of Mines.
3. Microsoft Developer Network. *MCI Command Strings*. Microsoft Corporation.
4. LaMothe, A. (1999). *Tricks of the Windows Game Programming Gurus*. Sams Publishing.
5. Leler, W. (1988). *Constraint Programming Languages*. Addison-Wesley.

---

*Dokumen ini disusun sebagai bagian dari Laporan Akhir Final Project mata kuliah Pemrograman Lanjut (EC234201), Program Studi S-1 Teknik Komputer, Institut Teknologi Sepuluh Nopember, Surabaya, 2025.*
