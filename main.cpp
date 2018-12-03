#include <bits/stdc++.h>

using namespace std;

//a subject checker that will return true or false.
bool Check(string word, char x){
   // cout << " : "  << word;
    bool cek = false;
    //kamus_subject should only contain lower case words.
    string kamus[5];
    if(x == 's')
        string kamus[5] = {"saya","kita","kamu","malih","aridi"};
    else if (x == 'p')
        string kamus[5] = {"membeli","mengendarai","meminjam","memperbaiki","menyewa"};
    else if (x == 'o')
        string kamus[5] = {"perahu","mobil","motor","pesawat","kereta"};
    else if (x == 'k')
        string kamus[5] = {"bekas","deflasi","baru","gajian","taman"};
    //membuat "po" sebagai pointer.
    int po = 0;
    //cek apakah word ada di kamus.
    while(!cek && (po < 5)){
        bool sama = true;
        for(int i = 0; i < kamus[po].size(); i++){
            sama = sama && (word[i] == kamus[po][i]);
        }
        cek = cek or sama;
        po++;
    }
    return cek;
}

char WordCheck(string word){
    bool sWord = Check(word,'s');
    bool pWord = Check(word,'p');
    bool oWord = Check(word,'o');
    bool kWord = Check(word,'k');
  if (sWord){
    return 's';
  }else if(pWord){
    return 'p';
  }else if(oWord){
    return 'o';
  }else if(kWord){
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
    /*cout << "option of Subject" << endl;
    cout << "saya - kita - kamu - malih - aridi" << endl;
    cout<< " " <<endl;
    cout << "option of Predicate" <<endl;
    cout << "membeli - belanja - makan - berlari - pergi" << endl;
    cout << " " << endl;
    cout << "option of Object" << endl;
    cout << "perahu - mobil - motor - pesawat - kereta" << endl;
    cout << " " << endl;
    cout << "option of keterangan" << endl;
    cout << "sejam - setiap hari - pada pagi hari - larut malam - di taman" << endl;
    cout << " " << endl;*/

    cout << "Please input your sentence about vehicle below!!" << endl;
    getline(cin,sentence);
    checkEveryWord(tokenizer(sentence)); // hahahaha
    return 0;
}
