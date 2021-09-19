/*
Nama      : Milyanda Vania
NPM       : 140810190034
Kelas     : A
Deskripsi : Program Shift Cipher Enkripsi dan Dekripsi
*/

#include <bits/stdc++.h>
using namespace std;

// Merubah plainteks ke chiperteks
string enkripsi(string plainText, int kunci)
{
  string cipherText = "";
  for (int i = 0; i < plainText.size(); i++){
    if (isupper(plainText[i])){
      cipherText += char(int(plainText[i] + kunci - 65) % 26 + 65);
    }
    else{
      cipherText += char((int(plainText[i] + kunci - 97) % 26) + 97);
    }
  }
  return cipherText;
}

// Merubah chiperteks ke plainteks
string dekripsi(string cipherText, int kunci)
{
  string plainText = "";
  for (int i = 0; i < cipherText.size(); i++){
    if (isupper(cipherText[i])){
      plainText += char((int(cipherText[i] - kunci - 65) % 26 + 26) % 26 + 65);
    }
    else{
      plainText += char((int(cipherText[i] - kunci - 97) % 26) + 97);
    }
  }
  return plainText;
}

int main()
{
  bool isLoop = true;
  char x;
  while (isLoop == true)
  {
    string plainText;
    cout << "\n==================================\n";
    cout << "====== PROGRAM SHIFT CIPHER ======\n";
    cout << "==================================\n";
    cout << "Masukkan Plainteks: ";

    getline(cin, plainText);
    int kunci;
    cout << "Masukkan Kunci: ";
    cin >> kunci;
    cout << "----------------------------------\n";

    string cipherText = enkripsi(plainText, kunci);
    string plain_Text = dekripsi(cipherText, kunci);

    cout << "\n==================================\n";
    cout << "Hasil Enkripsi: " << cipherText;
    cout << "\nHasil Dekripsi: " << plain_Text;
    cout << "\n==================================\n";
    do
    {
      cout << "\nApakah ingin diulang (y/n)? ";
      cin >> x;
      cin.ignore();
      if (x == 'y' || x == 'Y')
      {
        isLoop = true;
      }
      else if (x == 'n' || x == 'N')
      {
        isLoop = false;
      }
    } while (x != 'y' && x != 'Y' && x != 'n' && x != 'N');
  }
}