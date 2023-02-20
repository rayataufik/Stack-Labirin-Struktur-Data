#ifndef LABIRIN_H_INCLUDED
#define LABIRIN_H_INCLUDED

#include <iostream>
//pair<int, int> adalah sebuah tipe data yang digunakan untuk menyimpan pasangan dari dua nilai yang berbeda.
//Tipe data ini terdapat dalam C++ dan merupakan bagian dari library <utility>.
#include <utility>
using namespace std;

#define Nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define Top(S) ((S).Top)

typedef struct elmStack *address;

struct elmStack {
    //pair<int, int> info digunakan untuk menyimpan pasangan dari dua integer yang digunakan sebagai koordinat dalam proses DFS.
    pair<int, int> info;
    address next;
};

struct Stack {
  address Top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
//Fungsi void push(Stack &S, pair<int, int> x) digunakan untuk menambahkan data berupa pasangan dua integer ke dalam stack
void push(Stack &S, pair<int, int> x);
//fungsi pair<int, int> pop(Stack &S) digunakan untuk mengeluarkan data berupa pasangan dua integer dari stack
pair<int, int> pop(Stack &S);
void printInfo(Stack S);
bool DFS(Stack &S, int m, int n, int x, int y);
#endif // LABIRIN_H_INCLUDED
