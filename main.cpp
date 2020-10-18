#include "creating.h"

int main()
{
  FILE *read;
  if( (read=fopen("kursiokai.txt","r"))!=NULL)
  {std :: ifstream read("kursiokai.txt");
  int eilutes;
  eilutes = eilute("kursiokai.txt")-1;
    srand(time(NULL));
    vector<duomuo> Eil_vect;
    string vardas, pavarde;
    int integer;
    int pazym;
    read>>vardas>>pavarde;
    int kiek=0;
    while(vardas!="EGZ")
    {
      read>>vardas;
      kiek++;
    }
    kiek-=1;
    for(int i=0;i<eilutes;i++)
    {
        Eil_vect.push_back(duomuo());
        read>>vardas;
        read>>pavarde;
        Eil_vect[i].Vard = vardas;
        Eil_vect[i].Pav = pavarde;
        for(int j=0;j<(kiek);j++)
        {
          read>>pazym;
          if (pazym >=1 && pazym <=10){
          Eil_vect[i].paz.push_back(pazym);
          Eil_vect[i].GP+=Eil_vect[i].paz[j];
          Eil_vect[i].mediana.push_back(pazym);
          }
          else {
            printf("Faile yra netinkamo formato pazymys");
            return 0;}
        }
          read>>integer;
          if (integer >=1 && integer <=10){
          Eil_vect[i].egz=integer;
          Eil_vect[i].mediana.push_back(integer);
          }
          else {
            printf("Faile yra netinkamo formato pazymys");
            return 0;}

      if (Eil_vect[i].GP != 0){
        Eil_vect[i].GP = Eil_vect[i].GP / (kiek)/1.0;}
        Eil_vect[i].GP = Eil_vect[i].GP * 0.4 + 0.6 * Eil_vect[i].egz;
        //medianai skaiciuot
        std::sort(Eil_vect[i].mediana.begin(), Eil_vect[i].mediana.end());
        if ((kiek+1) % 2 != 0)
        Eil_vect[i].medianai = Eil_vect[i].mediana[(kiek) / 2];
        else Eil_vect[i].medianai = (Eil_vect[i].mediana[(kiek+1) / 2] + Eil_vect[i].mediana[ (kiek+1) / 2 - 1]) / 2.0;
    }
    std::sort(Eil_vect.begin(), Eil_vect.end(), palyginimas);
    cout << std::left << std::setw(15)<< "Vardas" <<std::left <<std::setw(15)<< "Pavarde ";
    cout<<std::left<< std::setw(15)<<"Galutinis paz"<<"Mediana"<<std::endl;
    cout<<"__________________________________________________"<<std::endl;
    for(int i=0;i<eilutes;i++)
    {
      cout << std::left << std::setw(15)<< Eil_vect[i].Vard <<std::left <<std::setw(15)<< Eil_vect[i].Pav;
      cout<< std::left<< std::setw(15)<< std::setprecision(3)<<Eil_vect[i].GP << std::setprecision(3) << Eil_vect[i].medianai <<std::endl;
    }
    read.close();
  }
  else {printf("Negalima atidaryti failo"); exit(0);}
  system("pause");
}
