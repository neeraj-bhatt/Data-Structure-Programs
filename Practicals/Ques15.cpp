
//Write a program to convert the Sparse Matrix into non-zero form and vice-versa.

#include<iostream>
using namespace std;

void StoN()
{
    
    int val, arrM[20][20], S[20][3], r=0, c=0, j;

    cout<<"\n Enter the no of non-zero elements: ";
    cin>>val;
    cout<<"\n Enter S. Mat.\n (Row\tCols\tValue):\n";
    for(int i=0; i<val; i++)
      for(j=0; j<3; j++)
        cin>>S[i][j];

    // finding rows and cols in main mat.
        for(int i=0; i<val; i++)
          {
            r = (S[i][0] > r) ? S[i][0] : r;
            c = (S[i][1] > c) ? S[i][1] : c;
          }

    for(int i=0; i<=r; i++)
        for(j=0; j<=c; j++)
            arrM[i][j] = 0;

    for(int i=0; i<val; i++)
        arrM[S[i][0]][S[i][1]] = S[i][2];


    cout<<"\nYour mat.: \n";
    for(int i=0; i<=r; i++)
    {
        for(j=0; j<=c; j++)
            cout<<arrM[i][j]<<"\t";

        cout<<endl;
    }
}

void NtoS()
{
    
    int r, c, arrM[20][20], rS=0, S[20][3], C=0;

    cout<<"\n Enter the no. of rows and cols: ";
    cin>>r>>c;
    cout<<"\n Enter Mat.:\n";
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
        {
            cin>>arrM[i][j];
            if(arrM[i][j] != 0)
              rS++;
        }

    //making S. Mat
    for(int i=0; i<r && C != rS; i++)
        for(int j=0; j<c && C != rS; j++)
        {
          if(arrM[i][j] != 0)
          {
            S[C][0] = i;
            S[C][1] = j;
            S[C][2] = arrM[i][j];
            C++;
          }
        }

    cout<<"\n\nSparse Mat: \n\n (Row\tCols\tValue):\n";
    for(int i=0; i<rS; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<S[i][j]<<"\t";
        }
        cout<<"\n";
    }

}


int main()
{
    
        int choice;
        char ch;

    menu:
        cout<<"\n\nMENU\n"
            <<"\n1) Normal matrix to Sparse Mat."
            <<"\n2) Sparse Mat to Normal Matrix."
            <<"\n\n* Your choice: ";
        cin>>choice;

    switch(choice)
    {
        case 1: NtoS();
                break;

        case 2: StoN();
                break;

        default: cout<<"\n Invalid input!";
    }


    cout<<"\n Wanna try again? (Y/N): ";
    cin>>ch;
    if(ch == 'y' || ch == 'Y')
        goto menu;
}