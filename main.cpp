#include <iostream>
#include <list>
#include <iterator>


using namespace std;

list<string> listResult;


void chuoidoixung(string chuoi, int index, int n){
    // for even n
    if (n%2 == 0){
        for (int i=0; i<=1; i++ ){
            if (index == (n/2)){
                listResult.push_back(chuoi);
                return;
            }else{
                string chuoi1 = chuoi+" " + to_string(i);
                chuoidoixung(chuoi1, index+1, n);
            }
        }
    }
    // n is odd
    if (n%2 != 0){
        for (int i=0; i<=1; i++ ) {
            if (index == (n / 2) + 1) {
                listResult.push_back(chuoi);
                return;
            } else {
                string chuoi1 = chuoi + " " + to_string(i);
                chuoidoixung(chuoi1, index + 1, n);
            }
        }
    }


}

string reverseStr(string str)
{
    int n = str.length();
    string str_re = str;

    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str_re[i], str_re[n - i - 1]);

    return str_re;
}

int main() {
    int n;
    cout << "N:";
    cin >> n;

    string chuoi = "";
    string lala = "";
    string lare = "";

    chuoidoixung(chuoi, 0, n);

    cout << "K: " << listResult.size() << endl;

    while (!listResult.empty()){
        lala = listResult.back();
        listResult.pop_back();
        lare = reverseStr(lala);
        // n is odd
        if (n %2 == 0){
            lala = lala + " " + lare;
        }
        // n is even
        if (n%2 != 0){
            lala = lala + lare.erase(0,1);
        }

        cout << lala << endl;
    }

    return 0;
}
