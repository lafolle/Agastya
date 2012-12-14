
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;



#define all(c) c.begin(),c.end()
#define pl cout<<endl;

typedef vector<vector<double> > vvd;
typedef vector<double> vd;
typedef vector<int> vi;

vd matrix_vector_multiplication(vvd&, vd&);
void show_vector(vd);

void show_dim(const vvd &A)
{
  cout<<"Rows : "<<A.size()<<endl;
  cout<<"Cols : "<<A[0].size()<<endl;
}

 vd matrix_vector_multiplication(vvd &A, vd &b)
 {
   int r_a=A.size(),c_a=A[0].size(), r_b=b.size(), c_b=1;
   int i,j,k;
   double c=0;
   vd X(r_a,0);

   if(c_a!=r_b){
     cout<<"Invalid dimensions\n";
     exit(1);
   }

   for(i=0;i<r_a;i++){
     c=0;
     for(j=0;j<r_b;j++)
       c+=A[i][j]*b[j];
     X[i]=c;
   }
   return X;
 }

void show_vector(vd P, string s)
{
  // display P
  int i,n=P.size();
  cout<<s<<endl;
  for(i=0;i<n;i++)
    cout<<P[i]<<endl;
  pl;
}

bool compare_vectors(const vd &A, const vd &B)
{
  int r_a=A.size(),r_b=B.size(),i,j;
  if(r_a!=r_b) return false;

  for(i=0;i<r_a;i++)
    if(A[i]!=B[i]) return false;

  return true;
}

void show_matrix(const vvd &A)
{
  pl;
   cout.setf(ios_base::fixed, ios_base::floatfield);
   int R=A.size(),C=A[0].size();
   int i,j;
   for(i=0;i<R;i++,cout<<'\n')
     for(j=0;j<C;j++)
       cout<<A[i][j]<<' ';

   pl;
 }

 vi LPU_decomposition(vvd &A)
 {
   // assuming R==C
   int R=A.size(), C=A[0].size();
   int i,j,k=0;
   double p=0, temp,t=0;
   vi P(R); // permutation matrix
   for(i=0;i<R;i++) P[i]=i;

   while(k<R){
     p=-100000;
     for(i=k;i<R;i++)
       if(abs(A[i][k])>p){
	 p=A[i][k];
	 t=i;
       }

     if(!p){
       show_matrix(A);
       cout<<"Singular matrix!\n";
       exit(1);
     }

     swap(P[k], P[t]);
     for(i=0;i<C;i++)
       swap(A[t][i],A[k][i]);

     for(i=k+1;i<R;i++){
       A[i][k]=A[i][k]/A[k][k];
       for(j=k+1;j<C;j++)
	 A[i][j]=A[i][j]-A[i][k]*A[k][j];
     }
     k++;
   }
   return P;
 }



 vd solve(vvd L,vvd U,vi P,vd b)
 {
   int R=b.size(),C=L[0].size();
   int i,s,j;
   vd x(R),y(R);

   // forward substitution
   for(i=0;i<R;i++){
     s=0;
     for(j=0;j<i;j++) s+=L[i][j]*y[j];
     y[i]=b[P[i]]-s;
   }

   // back substitution
   for(i=R-1;i>-1;i--){
     s=0;
     for(j=i+1;j<R;j++) s+=U[i][j]*x[j];
     x[i]=(y[i]-s)/U[i][i];
   }

   return x;
 }

 int main()
 {
   int i,j;
   int n=3;
   double a[3][3]={1,5,4,2,0,3,5,8,2}, B[3]={12,9,5};
   vvd A(n,vd(n)),U(n,vd(n,0)),L(n, vd(n,0));
   vd b(B,B+n),x(n,0);
   vi P(n,0);

   for(i=0;i<n;i++)
     for(j=0;j<n;j++)
       A[i][j]=a[i][j];


   cout<<"A = "<<endl;
   show_matrix(A);

   P=LPU_decomposition(A);

   // create L and U from A
   for(i=0;i<n;i++){
     for(j=0;j<n;j++){
       if(i>j) L[i][j]=A[i][j];
       else if(i==j){
	 L[i][j]=1;
	 U[i][j]=A[i][j];
       }
       else if(i<j) U[i][j]=A[i][j];
     }
   }

   cout<<"L = :\n";
   show_matrix(L);

   cout<<"U = :\n";
   show_matrix(U);
   
   x=solve(L,U,P,b);
   show_vector(x, "X");
   
   vd n_b(n,0);
   n_b=matrix_vector_multiplication(A,x);
   show_vector(n_b, "n_b");
   show_vector(b, "b");
   
   cout<<"Vectors B and b are  "<<(compare_vectors(n_b,b)?" equal\n" : " unequal\n");
   return 0;
 }

 // matrix vector multiplication
