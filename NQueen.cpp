#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
ll n;
bool arr[100][100];

bool check(ll x,ll y)
{
    for (ll i=0; i<y; i++)
        if (arr[x][i])
            return false;
    for (ll i=x,j=y; i>=0&&j>=0; i--,j--)
        if (arr[i][j])
            return false;
    for (ll i=x,j=y; i<n&&j>=0; i++,j--)
        if (arr[i][j])
            return false;
    return true;
}

bool NQueen(ll j)
{
    if (j>=n)
        return true;
    for (ll i=0; i<n; i++)
    {
        if (check(i,j))
        {
            arr[i][j]=true;
            if (NQueen(j+1))
                return true;
            arr[i][j]=false;
        }
    }
    return false;
}

int main()
{
    system("Color 70");
    cout << "\n\n\tEnter the number of Queens: ";
    cin >> n;
    if (NQueen(0))
    {
        for (ll i=0; i<n; i++)
        {
            cout << "\t\t";
            for (ll j=0; j<n; j++)
            {
                if (arr[i][j])
                    cout << " 1";
                else
                    cout <<  " .";
            }
            cout << "\n";
        }
    }
    else
        cout << "It is impossible to set up\n";
}
