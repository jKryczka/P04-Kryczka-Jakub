#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

using namespace std::chrono;
using namespace std;

void wypisz(string str,int start,int dlugosc) //funkcja pobiera z jakigo stringa ma wypisac podciag, od którego elementu zaczac i ile elementów dlugoœci ma miec ten podciag
{
    fstream wyjscie;
    wyjscie.open("wyjscie.txt",ios::app); //funkcja otwieta plik wyjscia, aby dopisac kolejny podciag

    for(int i=0;i<dlugosc;i++) //petla wykonujaca sie tyle razy, jakiej dlugoœci ma być podciag
    {
        wyjscie<<str[start+i]; //wypisuje cyfre z ciagu zaczynajac od elementu od którego mial zaczac i za kazdym razem o indeksie wiekszym o 1
    }
    wyjscie<<" "; //dodaje spacje po wypisaniu podciagu
}


void program()
{
    fstream wejscie; // otwieram plik z którego beda pobierane dane dla programu
    wejscie.open("nieprzetworzone.txt",ios::in);
    fstream wyjscie; // otwieram plik do ktorego beda wypisywane wyniki
    wyjscie.open("wyjscie.txt",ios::app);
    string inp;

    while(!wejscie.eof()) // petla wykonujaca sie dopuki program nie "dotrze" do konca pliku
    {

        bool x=1; // zmienna pomocnicza
        wejscie>>inp; // ciag zostaje pobrany z pliku

        int a= inp.size()-1; // zostaje okreœlona dlugosc ciagu
        for (int i= 1 ;i<a; i++) // petla wykonujaca sie dla kazdego elementu ciagu
        {
            if (inp[i]=='2') // program sprawdza czy element ciagu jest rowny 2
            {
                x=0; // zmienna zostaje zmieniona poniewaz element spelniajacy zadane kryteria zostala odnaleziona
                for(int j = 1;j<a;j++)
                {
                    if(inp[i-j]==inp[i+j]) // program sprawdza czy elementy po obu stronach polozone w równej odleglosci od danej 2 sa rowne
                    {
                        wypisz(inp, i - j ,(2 * j)+1); // jezli tak wypisuje ten podciag i ponawia sprawdzenie, tym razem dla elementów polo¿onych o jedna pozycje dalej od 2
                    }else
                    {
                        break; // jezeli nie to wychodzi z petli
                    }
                }
            }
        }
    if (x) // jesli zmienna spelniajaca zadane kryteria nie zostala znaleziona
    {
        wyjscie<<"brak elementów spełniających zadane kryteria.";
    }
    wyjscie<<endl; // nowa linijka w pliku wyjsciowym
    }
}

int main()
{
    auto start = std::chrono::high_resolution_clock::now(); // rozpoczyna pomiar czasu
    program(); // glowna czesc programu zostaje wykonana
    auto finish = std::chrono::high_resolution_clock::now(); // konczy pomiar czasu
    std::chrono::duration<double> elapsed = finish - start; // oblicza dlugosc pomiaru
    cout<<"Wykonanie operacji zajelo: "<<elapsed.count()<<" sekund."; // wypisuje dlugosc pomiaru
}
