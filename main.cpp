#include <bits/stdc++.h>

using namespace std;

//a subject checker that will return true or false.
bool S_Check(string word){
    bool cek = false;
    //kamus_subject should only contain lower case words.
    string kamus[5] = {"saya","kita","kamu","malih","aridi"};
    //membuat "po" sebagai pointer.
    int po = 0;
    //cek apakah word ada di kamus.
    while(!cek && (po <= 5)){
        cek = kamus[po] == word;
        po++;
    }
    return cek;
}
bool P_Check(string word){
    bool cek = false;
    //kamus_subject should only contain lower case words.
    string kamus[5] = {"membeli","belanja","makan","berlari","pergi"};
    //membuat "po" sebagai pointer.
    int po = 0;
    //cek apakah word ada di kamus.
    while(!cek && (po <= 5)){
        cek = kamus[po] == word;
        po++;
    }
    return cek;
}
bool O_Check(string word){
    bool cek = false;
    //kamus_subject should only contain lower case words.
    string kamus[5] = {"perahu","mobil","motor","pesawat","kereta"};
    //membuat "po" sebagai pointer.
    int po = 0;
    //cek apakah word ada di kamus.
    while(!cek && (po <= 5)){
        cek = kamus[po] == word;
        po++;
    }
    return cek;
}
bool K_Check(string word){
    bool cek = false;
    //kamus_subject should only contain lower case words.
    string kamus[5] = {"membeli","belanja","makan","berlari","pergi"};//belum di ganti.
    //membuat "po" sebagai pointer.
    int po = 0;
    //cek apakah word ada di kamus.
    while(!cek && (po <= 5)){
        cek = kamus[po] == word;
        po++;
    }
    return cek;
}

char WordCheck(string word){
    bool sWord = S_Check(word);
    bool pWord = P_Check(word);
    bool oWord = O_Check(word);
    bool kWord = K_Check(word);
  if ((sWord == true)&&(pWord == false) && (oWord == false) && (kWord == false)){
    return 's';
  }else if((sWord == false)&&(pWord == true) && (oWord == false) && (kWord == false)){
    return 'p';
  }else if((sWord == false)&&(pWord == false) && (oWord == true) && (kWord == false)){
    return 'o';
  }else if((sWord == false)&&(pWord == false) && (oWord == false) && (kWord == true)){
    return 'k';
  }else{
    return 'e';
  }
}


int main()
{
    string sentence;
    cout << "Hello world!" << endl;
    string word;
    do{
        cin >> word;
        if(S_Check(word))
            cout << "terima" << endl;
        else
            cout << "tolak" << endl;
    }while(word != "exit");
    return 0;
}
