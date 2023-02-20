#include "labirin.h"

int main() {
    Stack S;
    createStack(S);

    // Baca input labirin
    int m, n;
    cout << "Masukan Dimensi Labirin: ";
    cin >> m >> n;
    cout << "Masukan Labirin: " << endl;
    // Loop for pertama akan mengeksekusi kode di dalamnya sebanyak m kali
    for (int i = 0; i < m; i++) {
        // loop for kedua akan mengeksekusi kode di dalamnya sebanyak n kali.
        // Jadi, kode tersebut akan mengelola seluruh elemen pada labirin yang berukuran m x n
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x == 1) {
                // Titik labirin, tambahkan ke stack
                push(S, make_pair(i + 1, j + 1));
            }
        }
    }

    // Mulai traversal labirin dari koordinat (10, 10)
    bool jalankeluar = DFS(S, m, n, 10, 10);

    // Selesai membaca data labirin, cek apakah stack tidak kosong
    if (!jalankeluar) {
        cout << "Terdapat jalur ke tujuan" << endl;
        // Cetak informasi jalur ke tujuan
        printInfo(S);
    } else {
        cout << "Tidak ada jalur ke tujuan" << endl;
    }

    return 0;
}
