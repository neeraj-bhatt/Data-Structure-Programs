#include <iostream>
using namespace std;

class Diag
{
    private:
        int r = 0, c = 0;
        int marr[10][10];
        int arr[10];
    public:
        int get(int i, int j);
        void set();
};
void Diag :: set()
{
    cout << "Enter the rows of matrix (max 10) : ";
    cin >> r;
    cout << "Enter the columns of matrix (max 10): ";
    cin >> c;
    cout << "Enter the elements of matrix" << endl;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cout << "a[" << i << "][" << j << "] : ";
            cin >> marr[i][j]; 
        }
    }
    //stores non zero diagonal elements in an array
    cout << "Non zero Elements : ";
    for(int i=0; i<r ; i++)
    {   for(int j=0; j<c; j++)
            if(i == j)
            {
                arr[i] = marr[i][j];
                cout << arr[i] << " ";
            }
            else
                continue;

    }
}
int Diag :: get(int i, int j)
{
    if(i>=0 && j>=0)
    {
        if(i != j && i<r && j<c)
            return 0;
        else if(i == j && i<r && j<c)
            return arr[i];
        else
            return -1;
    }
    else
        return -1;    

}
int main()
{
    int a, b, out;
    char ch;
    Diag obj;
    obj.set(); 
    while(1)
    {
        cout << endl << "Enter the indices for the respective value from matrix" << endl;
        cout << "Row : ";
        cin >> a;
        cout << "Column : ";
        cin >> b;
        out = obj.get(a, b);
        if(out != (-1))
        {
            cout << "a[" << a << "] : " << out << endl;
            again:
            cout << "Do you want to continue [Y/n] : ";
            cin >> ch;
            if(ch == 'Y' || ch == 'y')
                continue;
            else if(ch == 'N' || ch == 'n')
            {
                cout << "Ok Bye :)" << endl;
                break;
            }
            else
            {
                cout << "Please enter a correct character :(" << endl;
                goto again;
            }
        }
        else{
            cout << "Index out of Bound." << endl << "Please enter correct value for index :(" << endl;
            exit(0);
        }
    }

    return 0;
}