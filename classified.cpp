#include <iostream>
#include <fstream>

using namespace std;

class encDec
{
private:
    int key;
    char c;
public:
    void encrypt(string filename);
    void decrypt(string filename);
};

void encDec::encrypt(string filename)
{
    cout<<"Give a key(number):";
    cin>>key;

    ifstream fin;
    ofstream fout;
    fin.open(filename.c_str(), ios::binary);
    filename = "encrypted";
    fout.open(filename.c_str(), ios::binary);
    while (!fin.eof())
    {
        fin>>noskipws>>c;
        int tmp = c+key;
        fout<<(char)tmp;
    }
    fin.close();
    fout.close();
    
}

void encDec::decrypt(string filename)
{
    cout << "Give the key:";
    cin>>key;

    ifstream fin;
    ofstream fout;

    fin.open(filename.c_str(), ios::binary);
    filename = "decrypted";
    fout.open(filename.c_str(), ios::binary);

    while (!fin.eof())
    {
        fin>>noskipws>>c;
        int tmp = c-key;
        fout<<(char)tmp;


    }
    fin.close();
    fout.close();

}

int main()
{
    encDec enc;
    string filename;
    char choice;
    cout << "Press 'E' for encrypting the file. 'D' for decrypting the file. 'Q' for quiting this program.\n";
    cin >> choice;
    if (choice == 'E')
    {
        enc.encrypt(filename);
    }
    if (choice == 'D')
    {
        enc.decrypt(filename);
    }

    return 0; 
}