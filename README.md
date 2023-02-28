# WowBestMatch

_Author: Jericho Russel Sebastian (13521107)_

WowBestMatch merupakan program pencari pasangan titik terdekat (_closest pair_) dari sekumpulan titik _n_-dimensi acak atau diberikan. Program ini dibuat sebagai pemenuhan Tugas Kecil 2 mata kuliah IF2211 Strategi Algoritma.

## Table of Contents

- [Requirements](#requirements)
- [Description](#description)
- [Compilation](#compilation)
- [Usage](#usage)
    - [Run](#run)
    - [Debug](#debug)

## Requirements

- Make, GNU G++, Python, PyInstaller, Matplotlib (untuk kompilasi)
- Make, Python, Matplotlib (opsional untuk menjalankan)

## Description

Program terbagi menjadi dua bagian, yaitu:
1. WowBM (C++): Mencari pasangan titik terdekat dari sekumpulan titik _n_-dimensi:
    - Jika tidak diberikan argumen, program akan menerima masukan banyak titik dan nilai _n_.
    - Jika diberikan argumen _path_ ke file CSV, program akan membaca file dan membentuk daftar titik sesuai dengan isi file.
    
    Program memberikan beberapa keluaran, yaitu:
    - Keluaran ke layar berupa pasangan titik terdekat beserta dengan jaraknya, berikut banyak operasi perhitungan jarak dan durasi total.
    - Keluaran indeks pasangan titik terdekat beserta dengan daftar titik ke file `result.txt`, untuk dibaca oleh WowPlot.
2. WowPlot (Python): Menerima daftar titik dalam file `result.txt` dan menggambarkan semua titik dalam bidang 3D:
    - Variasi 3 komponen pertama titik digambarkan sebagai perbedaan posisi dalam bidang 3D.
    - Variasi komponen ke-4 digambarkan sebagai perbedaan ukuran.
    - Variasi komponen ke-5 digambarkan sebagai perbedaan warna.
    - Variasi komponen di atas dimensi 5 tidak digambarkan.

    Pasangan titik terdekat yang ditemukan oleh WowBM digambarkan dalam warna merah.

## Compilation

Jalankan perintah berikut pada _root_ folder untuk mengkompilasi program (hasil `wowbm.exe` dan `wowplot.exe` dalam folder `bin`):

```
make build-all
```

Jalankan perintah berikut pada _root_ folder untuk mengkompilasi versi _debug_ dari program (hasil `wowbm_debug.exe` dan `wowplot.exe` dalam folder `bin`):

```
make build-debug
```

## Usage

### Run

Untuk menjalankan program, jalankan perintah berikut pada _root_ folder:

```
make run
```

atau, jika Python dan Matplotlib tersedia:

```
make run-nopybin
```

Jika Make tidak tersedia, dapat menjalankan `run.bat` (Windows) atau `run.sh` (Linux) yang tersedia pada _root_ folder.

Program dapat menerima masukan kumpulan titik dari file CSV. Jalankan perintah berikut untuk memberikan masukan file:

```
./bin/wowbm.exe <path/to/file.csv>
./bin/wowplot.exe
```

### Debug

Untuk menjalankan versi _debug_ dari program (melakukan perbandingan terhadap algoritma _brute force_), jalankan perintah berikut pada _root_ folder:

```
make debug
```

atau, jika Python dan Matplotlib tersedia:

```
make debug-nopybin
```

Jika Make tidak tersedia, dapat menjalankan `debug.bat` (Windows) atau `debug.sh` (Linux) yang tersedia pada _root_ folder.

Program dapat menerima masukan kumpulan titik dari file CSV. Jalankan perintah berikut untuk memberikan masukan file:

```
./bin/wowbm_debug.exe <path/to/file.csv>
./bin/wowplot.exe
```
