# Tugas Kecil II IF2211 Strategi Algoritma

## Penyusunan Rencana Kuliah dengan Topological-Sort
Topological sort adalah persoalan mengurutkan simpul-simpul pada suatu Directed Acyclic Graph dimana untuk setiap sisi dari simpul v ke u, maka simpul v akan muncul terlebih dahulu sebelum simpul u pada hasil pengurutan.

Program ini akan menyelesaikan sebuah persoalan penyusunan rencana kuliah dengan topological sort sebagai salah satu pendekatan algortima decrease and conquer dimana sebuah persoalan akan direduksi menjadi sub-persoalan yang lebih kecil, kemudian dilanjutkan dengan memproses sub-persoalan terebut.

Pertama-tama, program akan mengubah daftar mata kuliah ke dalam representasi DAG. Kemudian program akan melakukan pengulangan secara rekursif dimana setiap iterasinya akan dipilih semua mata kuliah yang dapat diambil tanpa prasyarat, dan mata kuliah tersebut akan dihapus dari graf, kemudian proses yang sama dilakukan untuk semester-semester selanjutnya. 

## Instalasi
- Clone repository ini pada terminal : 
```
git clone https://github.com/farishasim/Topological-Sort.git
```
- Anda bisa langsung menggunakan program (ada pada direktori `bin`) atau bisa juga melakukan compile terlebih dahulu. Jika ingin melakukan compile terhadap source-code program diperlukan compiler `g++`.
- Compile program dapat dilakukan dengan menggunakan command berikut :
```
g++ -o bin/Grape.o -c src/Grape.cpp
g++ -o bin/maindish src/Food.cpp bin/Grape.o
```
- atau
```
g++ -o bin/Grape.o -c src/Grape.cpp
g++ -std=c++11 -o bin/maindish src/Food.cpp bin/Grape.o
```
- Selain itu, pada folder bin juga sudah disediakan driver untuk kelas graf. Silahkan bereksplorasi dengan graf menggunakan driver tersebut. Compile driver dapat dilakukan dengan command yang sama, dengan mengganti `bin/maindish` menjadi `bin/driver` dan `src/Food.cpp` menjadi `src/Plate.cpp`

## Cara Penggunaan
- Siapkan file input, masukkan ke folder `test` (beberapa file yang siap pakai sudah disediakan pada folder tersebut). File yang di-input haruslah berisi daftar mata kuliah yang menjamin DAG jika direpresentasikan ke dalam graf
- Masuk ke direktori `bin`, kemudian jalankan program dengan command berikut  :
```
./maindish
```
- Setelah program dijalankan, masukkan nama file input (file harus berada pada direktori `test`)

## Author

[Faris Hasim Syauqi - 13519050](https://github.com/farishasim)

📌 Bandung, Indonesia