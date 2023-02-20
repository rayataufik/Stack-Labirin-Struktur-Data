#include "labirin.h"

// Fungsi untuk membuat stack kosong
void createStack(Stack &S) {
    (S).Top = Nil;
}
// Fungsi untuk mengecek apakah stack kosong atau tidak
bool isEmpty(Stack S) {
    return ((S).Top == Nil);
}
// Fungsi untuk mengecek apakah stack sudah penuh atau belum
// Dalam implementasi ini, asumsi stack tidak pernah penuh
bool isFull(Stack S) {
    return false;
}
// Fungsi untuk menambahkan elemen baru ke stack
void push(Stack &S, pair<int, int> x) {
    address P = new elmStack;
    info(P) = x;
    next(P) = (S).Top;
    (S).Top = P;
}
// Fungsi untuk menghapus elemen teratas dari stack
pair<int, int> pop(Stack &S) {
    if (isEmpty(S)) {
        // Stack kosong, kembalikan pasangan nilai (-1, -1)
        return make_pair(-1, -1);
    } else {
        // Stack tidak kosong, hapus elemen teratas
        address P = (S).Top;
        pair<int, int> x = info(P);
        (S).Top = next(P);
        delete P;
        return x;
    }
}
// Fungsi untuk mencetak informasi stack
void printInfo(Stack S) {
    address P = (S).Top;
    cout << "Koordinat jalur keluar: ";
    while (P != Nil) {
        cout << "(" << info(P).first << ", " << info(P).second << ") ";
        P = next(P);
    }
    cout << endl;
}

bool DFS(Stack &S, int m, int n, int x, int y) {
    // Algoritma Depth First Search (DFS)
    // S: stack yang akan digunakan untuk traversal
    // m, n: ukuran labirin
    // x, y: koordinat titik awal traversal

    // jika koordinat sudah sampai ke tujuan (x = m dan y = n), maka proses selesai.
    if (x == m && y == n) {
        // Selesai
        return true;
    }

    // Cari kemungkinan langkah selanjutnya
    // Array dx berisi 4 elemen yang mewakili kemungkinan pergeseran koordinat x saat melakukan traversal, yaitu +1, -1, 0, dan 0
    int dx[] = {1, -1, 0, 0};
    //Array dy berisi 4 elemen yang mewakili kemungkinan pergeseran koordinat y saat melakukan traversal, yaitu 0, 0, +1, dan -1
    int dy[] = {0, 0, 1, -1};
    // Baris berikutnya merupakan loop for yang akan mengeksekusi kode di dalamnya sebanyak 4 kali, yaitu sebanyak jumlah elemen pada array dx dan dy.
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        // selanjutnya fungsi DFS akan mengecek apakah koordinat yang akan dituju melebihi batas labirin atau tidak (nx > 0 && nx <= m && ny > 0 && ny <= n)
        if (nx > 0 && nx <= m && ny > 0 && ny <= n) {
            // Jika koordinat yang akan dituju valid, maka akan di push ke stack dan dijalankan rekursif dengan parameter koordinat baru.
            push(S, make_pair(nx, ny));
            if(DFS(S, m, n, nx, ny)){
                // Jika rekursif tersebut mengembalikan nilai true, maka akan di return true.
                return true;
            }else{
                //Namun jika mengembalikan nilai false, maka akan di pop
                pop(S);
            }
        }
    }
    // Jika setelah looping selesai, maka akan di return false.
    return false;
}


