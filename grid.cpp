#include <iostream>
using namespace std;
#include <iostream>

void printGrid(int &userRows, int &userColumns){
  cout<<endl;
  cout<<" ";
  int i=1,j;
  int k=0;
  int l=0;
  for(j = 0,i = 0; j <= 12*userColumns; j++){
    if(j%12==0)
        k=0;
    if(j%12==5){
        cout<<"   "<<i++<<" ";
    }
    else{
        if(j>120)
            if(k<10){
                cout << " ";
                k++;
            }
        if(j<120)
            cout<<" ";
    }
  }
  cout<<endl;
  for(i = 0; i <= 4*userRows; i++){
    if(i%4!=0){
      if((i%4)==2){
          //cout<<(char)(i/4 +'A');
          if(i/4<10)
              cout << i/4<<" ";
          else
              cout << i/4;
      }
      else
          cout<<"  ";
    }
    //cout << "\033[31mbold red text\033[0m\n";
    for(j = 0; j <= 6*userColumns; j++){
      if(i%4==0)
      {
        if(j==0)
            cout<<"  ";
        if(j%6==0)
            cout<<" ";
        else cout<<"---";
      }
      else{
        if(j%6==0)
            cout<<"|";
        else {
            //cout<<"   ";
            if((i%4)==1){
                if(j%6==1)
                    //cout<<1<<"    ";
                    if(rand() % 2)
                        //cout<<"Heroes in block";
                        cout << "\033[1;32mHeroes in block\033[0m";
                    else
                        cout<<"               ";

                //cout<<"  ";
            }

            if((i%4)==2){
                if(j%6==1)
                    //cout<<i/4<<"    ";
                    if(rand() % 2)
                        //cout<<"Accessible     ";
                        cout << "\033[1;32mAccessible     \033[0m";
                    else
                        //cout<<"non Accessible!";
                        cout << "\033[31mnon Accessible!\033[0m";
                //cout<<"  ";
            }

            if((i%4)==3){
                if(j%6==1)
                    //cout<<3<<"    ";
                    if(rand() % 2)
                        //cout<<"Has Market     ";
                        cout << "\033[1;32mHas Market     \033[0m";
                    else
                        //cout<<"No Market!     ";
                        cout << "\033[31mNo Market!     \033[0m";


                //cout<<"  ";
            }
            //if((i%4)!=2)
              //  cout<<" ";
        }
      }
    }
    if(i%4!=0){
      if((i%4)==2)
          //cout<<(char)(i/4 +'A');
          cout << i/4;
      else
          cout<<" ";
    }
    cout<<endl;
  }
  cout<<" ";
  for(j = 0,i = 0; j <= 12*userColumns; j++){
    if(j%12==0)
        k=0;
    if(j%12==5){
        cout<<"   "<<i++<<" ";
    }
    else{
        if(j>120)
            if(k<10){
                cout << " ";
                k++;
            }
        if(j<120)
            cout<<" ";

    }
  }
  cout<<endl;
}

int main() {
  int userRows, userColumns;
  cout << "Enter the number of rows -> ";
  cin >> userRows;
  while(userRows>14){
      cout << "Cant display more than 14 rows\nEnter the number of rows -> ";
      cin >> userRows;
  }
  cout << "Enter the number of columns -> ";
  cin >> userColumns;
  while(userColumns>14){
      cout << "Cant display more than 14 rows\nEnter the number of columns -> ";
      cin >> userColumns;
  }
  printGrid(userRows, userColumns);
  return 0;
}
/*#include <iostream>
using namespace std;
#include <algorithm>

void printGrid(int &userRows, int &userColumns, int *array){
  int indexi;
  int indexj;
  cout<<endl;
  cout<<" ";
  int i=1,j;
  for(j = 0; j <= 4*userColumns; j++){
    if(j%4==2)
        cout<<i++;
    else cout<<" ";
  }
  cout<<endl;
  for(i = 0; i <= 2*userRows; i++){
    if(i%2!=0)
      cout<<(char)(i/2 +'A');
    for(j = 0; j <= 2*userColumns; j++){
      if(i%2==0)
      {
        if(j==0)
            cout<<" ";
        if(j%2==0)
            cout<<" ";
        else cout<<"---";
      }
      else{
        if(j%2==0)
            cout<<"|";
        else{
           //indexi = std::distance(array, std::find(array, array + userRows, i));
           //indexj = std::distance(array, std::find(array, array + userColumns, j));
           //cout << indexi << " " << indexj;
           cout << "   ";
        }
      }
    }
    if(i%2!=0)
      cout<<(char)(i/2 +'A');
    cout<<endl;
  }
  cout<<" ";
  for(j = 0, i = 1; j <= 4*userColumns; j++){
    if(j%4==2)
        cout<<i++;
    else cout<<" ";
  }
  cout<<endl;
}

int main() {
  int userRows, userColumns;
  cout << "Enter the number of rows -> ";
  cin >> userRows;
  cout << "Enter the number of columns -> ";
  cin >> userColumns;
  int maxn=std::max(userRows, userColumns);
  int odds[maxn];
  int j=0;
  for(int i=0;i<maxn;i++)
  {
      j++;
      odds[i]=j;
      j++;
  }
  for(int i=0;i<maxn;i++)
  {
      cout << i << ": " << odds[i] << endl;
  }
  printGrid(userRows, userColumns, odds);
  return 0;
}*/
