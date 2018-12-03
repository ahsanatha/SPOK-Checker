#include <bits/stdc++.h>

using namespace std;

//a subject checker that will return true or false.
bool Check(string word, char x){
   // cout << " : "  << word;
    bool cek = false;
    //kamus_subject should only contain lower case words.
    string kamus[5];
    if(x == 's'){
        kamus[0]="saya"; kamus[1]="kita"; kamus[2]="kamu"; kamus[3]="malih"; kamus[4]="aridi";
    }
    else if (x == 'p'){
        kamus[0]="membeli"; kamus[1]="mengendarai"; kamus[2]="meminjam"; kamus[3]="memperbaiki"; kamus[4]="menyewa";
    }
    else if (x == 'o'){
        kamus[0]="perahu"; kamus[1]="mobil"; kamus[2]="motor"; kamus[3]="pesawat"; kamus[4]="kereta";
    }
    else if (x == 'k'){
        kamus[0]="bekas"; kamus[1]="deflasi"; kamus[2]="baru"; kamus[3]="gajian"; kamus[4]="taman";
    }
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

void tokenRecognition(vector<string> v){
    for (int i = 0; i < v.size(); i++){
        cout << WordCheck(v[i]) << endl;
      }
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
    cout << "option of Subject" << endl;
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
    cout << " " << endl;
    string sentence;
    cout << "Please input your sentence about vehicle below!!" << endl;
    getline(cin,sentence);
    vector<string> vtoken = tokenizer(sentence);
    tokenRecognition(vtoken); // hahahaha
    // if(vtoken[0] == "s"){
    //     cout << "tolak";
    // }

    return 0;
}
