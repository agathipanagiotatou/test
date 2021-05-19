#include <iostream>
#include <fstream>
#include <cstring>
#include "unclassified_array.h"
using namespace std;

int main()
{
  unclassified_array WORD;//δημιουργώ αντικείμενο για τον αταξινομητο πίνακα 
  unclassified_array();
  ifstream ifs;
  ifs.open("small-file.txt");//ανοίγω το αρχείο
  char *str=new char[100],NAME[100];
  int i=0,j=0;
  
  if(ifs.is_open())//αν το αρχείο έχει ανοίξει
  {
    while(ifs>>str)//όσο διαβάζει σθμβολοσειρά
    {
      for(i=0,j=0;j<strlen(str);i++,j++)//όσο το j μικρότερο από το μήκος της συμβολοσειράς της str
      {
        if((str[j]>64 && str[j]<91) || (str[j]>96 && str[j]<123))//αν ο χαρακτήρας είναι γράμμα 
        {
          if(str[j]<91)//αν το γράμμα είναι κεφαλαίο
            NAME[i]=str[j]+32;//τότε θα αποθηκεύεται στην θέση i του πίνακα NAME ως πεζό
        
          else//αλλιώς το γράμμα είναι πεζό
            NAME[i]=str[j];//και αποθηκεύεται ως έχει στην θέση i του πίνακα NAME
          
        }
        else//αν ο χαρακτήρας δεν είναι γράμμα
        {
          if(NAME[0]!=0)//και ο πίνακας NAME δεν είναι κενός
          {//cout<<NAME<<" ";
            WORD.addword(NAME);//τότε στέλνουμε την λέξη στην συνάρτηση addword της κλάσης του αταξινόμητου πίνακα 
            for(int u=0;u<30;u++)//και έπειτα αρχικοποιούμε τον πίνακα NAME
            NAME[u]=0;
          }
          i=-1;//το i=-1 ώστε όταν τελειώσει η for το i=0 ώστε να ξεκινήσει καινούρια λέξη
        }
        
      }
      if(NAME[0]!=0)//αν ο πίνακας NAME δεν είναι κενός
      { //cout<<NAME<<" ";
        WORD.addword(NAME);//τότε στέλνουμε την λέξη στην συνάρτηση addword της κλάσης του αταξινόμητου πίνακα 
        for(int u=0;u<30;u++)//και έπειτα αρχικοποιούμε τον πίνακα NAME
          NAME[u]=0;
      }
    }
  }
  else//αν υπάρχει πρόβλημα στο άνοιγμα του αρχείου
  {
    cout<<"File error";
    ifs.close();
    return 0;
  }
 ifs.close();//κλείσιμο αρχείου
 cout<<"Write a word"<<endl;
 char Word[100];
 cin>>Word;
 int r;
 r=WORD.searchword(Word);//αναζήτηση της λέξης που δώσαμε ως είσοδο
 if(r>=0)
   cout<<WORD.returntimes(r);//επιστρέφει πόσες φορές εμφανίστηκε η λέξη
 
 else//αν το r=-1 τότε δεν βρέθηκε η λέξη
   cout<<"We did not find the word";
 
}



