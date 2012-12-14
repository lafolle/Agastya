/* The formula would be GET N and K
(n-1)!/(k-1)! * ((n-1) - (k-1))!
*/

#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

int main()
{
    int t;
    int arr;
    long long remain = 1;
    unsigned long long ans = 1;
    vector<int> divi,divs;
    cin>>t;
    while(t--)
    {
        int k,n;
        cin>>n>>k;
        n--;k--;
        int dif = n-k;

        if(k>dif)
        {
          //  cout<<"Into 1st if statement"<<endl;
            arr=n-k;
            if(arr == 0) { ans =1;goto A;}
  //          cout<<arr<<"\t"<<endl;

            for(int i=n-arr+1;i<=n;i++)
            {
                divs.push_back(i);
            }

            if(dif == 0 || dif == 1) { divi.push_back(1);}
            else{
            for(int i=2;i<=dif;i++)
            {
                divi.push_back(i);
            }
            }


            for(int i=divi.size();i>=0;i--)
            {
                for(int j=0;j<divs.size();j++)
                {
                    if(divi[i] == 0){j=divs.size();continue;}
                    if(divs[j] % divi[i] == 0){ divs[j] /= divi[i];  divi[i] = 1; j=divs.size();}

                }
            }

            for(int i=0;i<divs.size();i++)
            {
                ans *= divs[i];
            }
        }

        else
        {
            arr=n-dif;
  //          cout<<arr<<"\t"<<endl;
            for(int i=n-arr+1;i<=n;i++)
            {
                divs.push_back(i);
            }
            if(dif == 0 || dif == 1) { divi.push_back(1);}
            else{

            for(int i=2;i<=k;i++)
            {
                divi.push_back(i);
            }
            }

            for(int i=divi.size()-1;i>=0;i--)
            {
                for(int j=0;j<divs.size();j++)
                {
                    if(divi[i] == 0){j=divs.size();continue;}
                    if(divs[j] % divi[i] == 0){  divs[j] /= divi[i];  divi[i] = 1; j=divs.size();}

                }
            }

            for(int i=0;i<divs.size();i++)
            {
                ans *= divs[i];
            }
        }
        A:
        //cout<<remain<<endl;
        cout<<ans/remain<<endl;
        ans =1; remain = 1;
        divi.clear();
        divs.clear();
    }

    return 0;
}

