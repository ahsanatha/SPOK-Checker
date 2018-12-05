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
        int count;
        for(int i = 0; i < kamus[po].size(); i++){
            sama = sama && (word[i] == kamus[po][i]);
            if(word[i] != kamus[po][i])
                break;
        }
        cek = cek or sama;
        po++;
    }
    return cek;
}

char tokenRecognizer(string word){
  if (Check(word,'s')){
    return 'S';
  }else if(Check(word,'p')){
    return 'P';
  }else if(Check(word,'o')){
    return 'O';
  }else if(Check(word,'k')){
    return 'K';
  }else{
    return 'e';
  }
}

vector<char> convert(vector<string> v){
    vector<char> c;
    for(int i = 0; i < v.size(); i++){
        c.push_back(tokenRecognizer(v[i]));
    }
    return c;
}

void showAllWords(vector<string> v){
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}

void showAllChar(vector<char> c){
    for(int i = 0; i < c.size(); i++){
        cout << c[i] << " ";
    }
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

char state;
stack<char> sc;
bool pushDownA(vector<char> vc){
    state = 'i';
    sc.push('#'); 
    state = 'p';
    sc.push('S');
    state = 'q';
    for (int i=0; i < vc.size(); i++){
        //cout << endl;
        //cout << vc[i] << " ";
        if ((vc[i] == 'S')&&('S' == sc.top())){
            sc.pop();
            //cout << " S popped ";
            sc.push('P'); 
            //cout << " P pushed ";
        }else if ((vc[i] == 'P')&&('P' == sc.top())){
            sc.pop();
            //cout << " P popped ";
            if(i < (vc.size()-1)){
                if (vc[i+1] == 'O'){
                    sc.push('O');
                    //cout << " O pushed ";
                }else if (vc[i+1] == 'K'){
                    sc.push('K');
                    //cout << " K pushed ";
                }
            }
        }else if ((vc[i] == 'O') && ('O'== sc.top())){
            sc.pop();
            //cout << " O popped ";
            if(i < (vc.size()-1)){
                if(vc[i+1] == 'K'){
                    sc.push('K');
                    //cout << " K pushed ";
                }
            }
        }else if ((vc[i] == 'K')&&('K' == sc.top())){
            sc.pop();
            //cout << " K popped ";
        }else{
            sc.push(vc[i]);
        }
    }
    if(sc.top() == '#'){
        state = 'f';
        return true;
    }else{
        return false;
    }
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
    vector<string> tokenized = tokenizer(sentence);
    vector<char> spoked = convert(tokenized);
    showAllChar(spoked);
    if(pushDownA(spoked)){
        cout << endl << " KALIMAT DI TERIMA";
    }else{
        cout << endl << " KALIMAT DI TOLAK";
    }
    return 0;
}
