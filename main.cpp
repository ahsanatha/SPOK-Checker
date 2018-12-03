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
        bool sama = true;
        for(int i = 0; i < kamus[po].size(); i++){
            sama = sama && word[i] && kamus[po][i];
        }
        cek = cek or sama;
        po++;
    }
    return cek;
}
bool P_Check(string word){
    bool cek = false;
    //kamus_subject should only contain lower case words.
    string kamus[5] = {"membeli","mengendarai","meminjam","memperbaiki","menyewa"};
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
    string kamus[5] = {"bekas","deflasi","baru","gajian","taman"};//belum di ganti.
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

void checkEveryWord(vector<string> v){
    for (int i = 0; i < v.size(); i++) 
        cout << WordCheck(v[i]) << " "; 
}

void showAllWords(vector<string> v){
    for (int i = 0; i < v.size(); i++) 
        cout << v[i] << " "; 
}

vector<string> stopwordRemove(vector<string> v){
    /* vector<string> stopword = {'yang', 'untuk', 'pada', 'ke', 'para', 'namun', 'menurut', 'antara', 'dia', 'dua', 'ia', 'seperti', 'jika',
                                'sehingga', 'kembali', 'dan', 'tidak', 'ini', 'karena', 'kepada', 'oleh', 'saat', 'harus', 'sementara', 
                                'setelah', 'belum', 'kami', 'sekitar', 'bagi', 'serta', 'di', 'dari', 'telah', 'sebagai', 'masih', 'hal', 
                                'ketika', 'adalah', 'itu', 'dalam', 'bisa', 'bahwa', 'atau', 'hanya', 'kita', 'dengan', 'akan', 'juga', 'ada', 
                                'mereka', 'sudah', 'saya', 'terhadap', 'secara', 'agar', 'lain', 'anda', 'begitu', 'mengapa', 'kenapa', 'yaitu', 
                                'yakni', 'daripada', 'itulah', 'lagi', 'maka', 'tentang', 'demi', 'dimana', 'kemana', 'pula', 'sambil', 'sebelum', 
                                'sesudah', 'supaya', 'guna', 'kah', 'pun', 'sampai', 'sedangkan', 'selagi', 'sementara', 'tetapi', 'apakah', 
                                'kecuali', 'sebab', 'selain', 'seolah', 'seraya', 'seterusnya', 'tanpa', 'agak', 'boleh', 'dapat', 'dsb', 'dst', 'dll',
                                'dahulu', 'dulunya', 'anu', 'demikian', 'tapi', 'ingin', 'juga', 'nggak', 'mari', 'nanti', 'melainkan', 'oh', 'ok', 
                                'seharusnya', 'sebetulnya', 'setiap', 'setidaknya', 'sesuatu', 'pasti', 'saja', 'toh', 'ya', 'walau', 'tolong', 'tentu', 
                                'amat', 'apalagi', 'bagaimanapun'};*/

    
}

vector<string> tokenizer(string sentence){
    vector<string> words;
    string word = "";
    int lenS = sentence.length();
    int po = 0;
    for(int i=0; i < lenS; i++){
        if(sentence[po] != ' '){
            word += sentence[po];

        }else{
            words.push_back(word);
            word = "";
        }
        po++;
    }
    words.push_back(word);
    return words;
}

int main()
{
    string sentence;
    cout << "silahkan masukkan kalimat tentang kendaraan :" << endl;
    getline(cin,sentence);
    //showAllWords(tokenizer(sentence));
    checkEveryWord(tokenizer(sentence)); 
    return 0;
}
