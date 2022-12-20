
//Write a program to implement Diagonal Matrix using one-dimensional array.

#include <iostream>
using namespace std;
int main()
{
  //Take a Diagonal Matrix
  int diagonal_Matrix[3][3] = {{5,0,0},{0,6,0},{0,0,2}};
  int i, j, compact_Form[3];
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        if(i == j){
            compact_Form[i] = diagonal_Matrix[i][j]; //copy diagonal elements...
        }
    }
  }
  cout << endl << "In Diagonal Form " << endl;
  for(i=0;i<3;i++){
    cout << compact_Form[i] << " ";
  }
  //To Display Results Back ...
  cout << endl << "Displaying the Original Matrix" << endl;
  for(i=0;i<3;i++){
    cout << endl;
    for(j=0;j<3;j++){
        if(i == j){ // If the index is same like 00 11 22 ...
            cout << compact_Form[i] << " ";
        }else{
            cout << "0 ";
        }
    }
  }
}