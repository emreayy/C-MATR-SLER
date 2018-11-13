#include <stdio.h>

#include <stdlib.h>

#include <math.h>

double *ozDeger;

int n;

int lcm(int x,int y);

int main(){

int i,u_sayi;

git:

printf("Kac tane sayi uretilecek : ");

scanf("%d",&u_sayi);

if (u_sayi<=0){goto git;}

cark(u_sayi);

return 0;

}

void cark (int u_sayi){

int i,dizi[u_sayi];

srand(time(NULL));

for (i=1; i<=u_sayi; i++){

dizi[i] = rand() % 241;

printf("\ %d.Sayi: %d\n",i,dizi[i]); }

if (dizi[u_sayi]%4==1){

int j,k;

printf("----OzDeger----\n");

printf("Kare matrisin boyutunu giriniz : ");

scanf("%d",&n);

ozDeger = malloc(sizeof(double)*n);

int k_matris[n][n];

for (k=0; k<n; k++){

for(j=0; j<n; j++){

printf("%d. Satir %d. Sutun Elemanini Giriniz : ", k+1, j+1);

scanf("%d", &k_matris[k][j]);

} printf("\n");

}

ozdegerbul(k_matris);

}

else if (dizi[u_sayi]%4==2){

int j,k;

printf("----Schur----\n");

printf("Kare matrisin boyutunu giriniz : ");

scanf("%d",&n);

ozDeger = malloc(sizeof(double)*n);

int k_matris[n][n];

for (k=0; k<n; k++){

for(j=0; j<n; j++){

printf("%d. Satir %d. Sutun Elemanini Giriniz : ", k+1, j+1);

scanf("%d", &k_matris[k][j]);

} printf("\n");

}

schur(k_matris,ozdegerbul(k_matris));

}

else if (dizi[u_sayi]%4==3){

int j,k=0;

printf("----OzVektor----\n");

printf("Kare matrisin boyutunu giriniz : ");

scanf("%d",&n);

ozDeger = malloc(sizeof(double)*n);

int k_matris[n][n];

for (k=0; k<n; k++){

for(j=0; j<n; j++){

printf("%d. Satir %d. Sutun Elemanini Giriniz : ", k+1, j+1);

scanf("%d", &k_matris[k][j]);

} printf("\n");

}

ozvektorbul(k_matris,ozdegerbul(k_matris));

}

else{

int j,k;

printf("----NilPotent----\n");

printf("Kare matrisin boyutunu giriniz : ");

scanf("%d",&n);

ozDeger = malloc(sizeof(double)*n);

int k_matris[n][n];

for (k=0; k<n; k++){

for(j=0; j<n; j++){

//printf("%d. Satir %d. Sutun Elemanini Giriniz : ", k+1, j+1);

srand(time(NULL));

k_matris[k][j] = rand() % 30 + (-15);

} printf("\n");

}

nilpotent(k_matris);

}

}

void ozdegerbul(int k_matris[n][n]){

if (n<=0) main();

// Dosya açyp olu?turma....

FILE *dosya_yaz;

dosya_yaz = fopen("ozdeger.txt","w");

fputs("ozDegerBul Dosyasydyr",dosya_yaz);

fprintf(dosya_yaz,"\n");

// De?i?ken Tanymy ve N nin Girilmesi

int i,j;

//ozDeger = malloc(sizeof(double)*n);

////////////////// N 1*1 LYK //////////////////////////

if (n==1){

printf("Ozdeger = %d \n",k_matris[0][0]);

fprintf(dosya_yaz,"Ozdeger = %d \n",k_matris[0][0]);}

//////////////////// 2*2 LIK MATRYS /////////////////////

else if (n==2){

printf("\n Olusturulan Matris:\n\n");

for(i=0; i<n; i++){

for(j=0; j<n; j++){

printf("%3d ", k_matris[i][j]);}printf("\n");}printf("\n");

fprintf(dosya_yaz,"\n Olusturulan Matris:\n\n");

for(i=0; i<n; i++){

for(j=0; j<n; j++){

fprintf(dosya_yaz,"%3d ", k_matris[i][j]);}

fprintf(dosya_yaz,"\n");}

int lamda;

fprintf(dosya_yaz,"\n");

fprintf(dosya_yaz,"det(Matris-lamda*I)\n\n");

for(i=0; i<n; i++){

for(j=0; j<n; j++){

if (j==i){

fprintf(dosya_yaz,"%3d-lamda", k_matris[i][j]);}

else {

fprintf(dosya_yaz,"%3d ", k_matris[i][j]);}

}

fprintf(dosya_yaz,"\n");}

int lam=-1;

int a,b,c,d;

d=(k_matris[1][0]*k_matris[0][1]);

c=(k_matris[0][0]*k_matris[1][1]-d);

b=(k_matris[0][0]*lam )+ (k_matris[1][1]*lam);

a=1;

fprintf(dosya_yaz,"\nKat Sayilar \n\n");

fprintf(dosya_yaz," x^2 = %d\n",a);

fprintf(dosya_yaz," x = %d\n",b);

fprintf(dosya_yaz," c = %d\n",c);

fprintf(dosya_yaz,"\n");

double delta;

delta = (b*b -4*a*c);

int sonuc;

if (delta > 0){

ozDeger[n-1] = (- b + sqrt(delta)) / (2.0 * a);

ozDeger[n] = (-b - sqrt(delta)) /(2.0*a);

sonuc=printf("Ozdeger1 == %.2lf ve Ozdeger2 == %.2lf \n\n", ozDeger[n-1],ozDeger[n]);

fprintf(dosya_yaz,"Ozdeger1 == %.2lf ve Ozdeger2 == %.2lf \n\n", ozDeger[n-1],ozDeger[n]);}

else if(delta < 0)

{

sonuc = printf("Reel kok bulunmamaktadir.\n\n");}

else{

ozDeger[n-1] = (- b + sqrt(delta)) / (2.0 * a);

sonuc=printf("Iki kok birbirine esittir. %.2lf \n\n", ozDeger[n-1]);}

fclose(dosya_yaz);}

////////////////////// 3*3 LÜK MATRYS ////////////////////////////////

else if (n==3){

printf("\n Olusturulan Matris:\n\n");

for(i=0; i<n; i++){

for(j=0; j<n; j++){

printf("%3d ", k_matris[i][j]); }printf("\n");}printf("\n");

fprintf(dosya_yaz,"\n Olusturulan Matris:\n\n");

for(i=0; i<n; i++){

for(j=0; j<n; j++){

fprintf(dosya_yaz,"%3d ", k_matris[i][j]);}

fprintf(dosya_yaz,"\n");}

fprintf(dosya_yaz,"\n");

fprintf(dosya_yaz,"det(Matris-lamda*I)\n\n");

for(i=0; i<n; i++){

for(j=0; j<n; j++){

if (j==i){fprintf(dosya_yaz,"%3d-lamda", k_matris[i][j]);}

else {

fprintf(dosya_yaz,"%3d ", k_matris[i][j]);}}

fprintf(dosya_yaz,"\n");}

int d=-1;

int a,a1,a2,a3,aT,b,b1,b2,b3,b4,bT,c,cT;

a=d*d;

b=k_matris[0][0]*d;

b1=k_matris[1][1]*d;

c=k_matris[0][0]*k_matris[1][1];

b2=b+b1;

cT=k_matris[2][2]*c;

b3=c*d;

b4=b2*k_matris[2][2];

a2=b2*d;

a3=a*k_matris[2][2];

bT=b3+b4;

aT=a2+a3;

fprintf(dosya_yaz,"\nKat Sayilar \n\n");

fprintf(dosya_yaz,"x3 = %d \n",d);

fprintf(dosya_yaz,"x2 = %d \n",aT);

fprintf(dosya_yaz,"x = %d \n",bT);

fprintf(dosya_yaz,"c = %d \n",cT);

printf("\n");

float r,s,t,delta,q;

float q1,r1,s1,t1;

q1 = (-3*bT-aT*aT);

q=q1/9;

//printf("q == %f \n",q);

r1=((9*aT*bT)-(27*cT))-(2*aT*aT*aT);

r=r1/-9;

//printf("r == %f \n",r);

s1=(r+pow((q*q*q)+(r*r),0.5));

s=pow(s1,0.33);

//printf("s == %f \n",s);

t1=(r-pow((q*q*q)+(r*r),0.5));

t=pow(t1,0.33);

//printf("t == %f \n",t);

ozDeger[n-2]=(s+t)-(aT/-3);

ozDeger[n-1]=((-(s+t)/2)-(aT/-3))+(((pow(-1,1/2)*pow(3,1/2))*(s-t))/2);

ozDeger[n]=((-(s+t)/2)-(aT/-3))-(((pow(-1,1/2)*pow(3,1/2))*(s-t))/2);

delta=(q*q*q)+(r*r);

printf("ozdeger1 == %.2lf\t",ozDeger[n-2]);

printf("ozdeger2 == %.2lf\t",ozDeger[n-1]);

printf("ozdeger3 == %.2lf\n",ozDeger[n]);

fprintf(dosya_yaz,"\n");

fprintf(dosya_yaz,"ozdeger1 == %.2lf\t",ozDeger[n-2]);

fprintf(dosya_yaz,"ozdeger2 == %.2lf\t",ozDeger[n-1]);

fprintf(dosya_yaz,"ozdeger3 == %.2lf\n",ozDeger[n]);

if(delta<0){

printf("delta sifirdan kucuk oldugundan kok yoktur");

}

}

//////// N 4*4 lük /////////////////

else {

printf("\n Olusturulan Matris:\n\n");

for(i=0; i<n; i++){

for(j=0; j<n; j++){

printf("%3d ", k_matris[i][j]);

}

printf("\n");

}

}

return ozDeger;

}

void schur(int k_matris[n][n]){

int i,j;//Gelen oz deger sayisi

int toplam=0;

int lim=0,limson=0;

int Kareler[n];

FILE *dosya_yaz;

dosya_yaz = fopen("schur.txt","w");

fputs("Schur Dosyasydyr",dosya_yaz);

fprintf(dosya_yaz,"\n");

for (i=0; i<n; i++){

for (j=0;j<n; j++){

lim = (k_matris[i][j]) * (k_matris[i][j]);

limson +=lim;

fprintf(dosya_yaz,"Limit = %d \n",limson);

fprintf(dosya_yaz,"\n");

}

}

for(i=0;i<n;i++){

Kareler[i]=ozDeger[i]*ozDeger[i];

toplam+=Kareler[i];

fprintf(dosya_yaz,"Toplam = %d \n",toplam);

fprintf(dosya_yaz,"\n");

}

if (toplam <= limson){

fprintf(dosya_yaz,"\n");

fprintf(dosya_yaz,"toplam <= limson \n");

fprintf(dosya_yaz,"\n");

printf("Schur Teoremine Uygundur. \n");

fprintf(dosya_yaz,"Schur Teoremine Uygundur. \n");

}

else {printf("\n");

fprintf(dosya_yaz,"\n");

fprintf(dosya_yaz,"toplam > limson \n");

fprintf(dosya_yaz,"\n");

printf("Schur Teoremine Uygun Degildir. \n");

fprintf(dosya_yaz,"Schur Teoremine Uygun Degildir. \n");

}

}

int ozvektorbul(int k_matris[n][n]){

int i,j,k,a[n][n];

int det=1,l,d1,d2,b;

float c,x[10],toplam=0.0;

FILE *dosya_yaz;

dosya_yaz = fopen("ozvektor.txt","w");

fputs("OzVektor Dosyasidir",dosya_yaz);

fprintf(dosya_yaz,"\n");

fprintf(dosya_yaz,"\n Olusturulan Matris:\n\n");

for(i=0; i<n; i++){

for(j=0; j<n; j++){

fprintf(dosya_yaz,"%10d ", k_matris[i][j]);}

fprintf(dosya_yaz,"\n");}

for(i=0;i<n;i++)

{

for(j=0;j<n;j++)

{

a[i][j]=k_matris[i][j];

}

}

for(i=0;i<n-1;i++)

{

for(j=i+1;j<n;j++)

{

l=lcm(a[i][i],a[j][i]);

if(l!=0&&(a[i][i]!=0&&a[j][i]!=0))

{

l=(a[i][i]*a[j][i])/l;

d1=l/a[i][i];

d2=l/a[j][i];

a[j][i]=0;

for(k=i+1;k<n;k++)

{

a[j][k]=(d2*a[j][k])-(d1*a[i][k]);

}

}

}

}

printf("\nGauss yonteminden sonra matris : \n");

fprintf(dosya_yaz,"\n");

fprintf(dosya_yaz,"\nGauss yonteminden sonra matris : \n");

fprintf(dosya_yaz,"\n");

for(i=0;i<n;i++)

{

for(j=0;j<n;j++)

{

printf("%d\t",a[i][j]);

fprintf(dosya_yaz,"%d\t",a[i][j]);

}

fprintf(dosya_yaz,"\n");

printf("\n");

}

for (k=0; k<n; k++){

for(j=n; j<n+1; j++){

a[k][j]=ceil(ozDeger[k+1]);

} printf("\n"); fprintf(dosya_yaz,"\n");

}

for(j=1; j<=n; j++) //üçgen matris olusturmak için döngü

{

for(i=1; i<=n; i++)

{

if(i>j)

{

c=a[i][j]/a[j][j];

for(k=1; k<=n+1; k++)

{

a[i][k]=a[i][k]-c*a[j][k];

}

}

}

}

x[n]=a[n][n+1]/a[n][n];

// geri yerine ekleme

for(i=n-1; i>=1; i--)

{

toplam=0;

for(j=i+1; j<=n; j++)

{

toplam=toplam+a[i][j]*x[j];

}

x[i]=(a[i][n+1]-toplam)/a[i][i];

}

printf("\nCOZUM : \n");

fprintf(dosya_yaz,"\nCOZUM : \n ");

for(i=1; i<=n; i++)

{

printf("\n OzVektor %d = %.2f \t",i,x[i]); // x,y ve z de?erleri

fprintf(dosya_yaz,"\n OzVektor %d= %.2f\ t",i,x[i]); //33 x,y ve z de?erleri

}

return 0;

}

void nilpotent(int k_matris[n][n]){

int M[n][n],T[n][n];

int i,j,t=0,k,toplam=0;

printf("\n Olusturulan Matris:\n\n");

for(i=0; i<n; i++){

for(j=0; j<n; j++){

printf("%10d ", k_matris[i][j]);}printf("\n");}printf("\n");

FILE *dosya_yaz;

dosya_yaz = fopen("nilpotent.txt","w");

fputs("NilPotent Dosyasydyr",dosya_yaz);

fprintf(dosya_yaz,"\n");

fprintf(dosya_yaz,"\n Olusturulan Matris:\n\n");

for(i=0; i<n; i++){

for(j=0; j<n; j++){

fprintf(dosya_yaz,"%10d ", k_matris[i][j]);}

fprintf(dosya_yaz,"\n");}

for(i=0; i<n; i++){

for(j=0; j<n; j++){

for(k=0; k<n; k++){

toplam += k_matris[i][k] * k_matris[k][j]; }

M[i][j] = toplam;

toplam = 0; } printf("\n"); }

for(i=0; i<n; i++){

for(j=0; j<n; j++){

printf("%10d",M[i][j]);} printf("\n"); fprintf(dosya_yaz,"\n"); }

for(i=0; i<n; i++){

for(j=0; j<n; j++){

fprintf(dosya_yaz,"%10d",M[i][j]);} printf("\n"); fprintf(dosya_yaz,"\n");} fprintf(dosya_yaz,"\n");

/////////////////////////////*Esit mi*////////////////////////////

while(t<3){

for(i=0; i<n; i++){

for(j=0; j<n; j++){

for(k=0; k<n; k++){

toplam += M[i][k] * k_matris[k][j]; }

T[i][j] = toplam;

toplam = 0;} printf("\n");}

for(i=0; i<n; i++){

for(j=0; j<n; j++){

printf("%10d",T[i][j]);} printf("\n");}

for(i=0; i<n; i++){

for(j=0; j<n; j++){

fprintf(dosya_yaz,"%10d",T[i][j]);} printf("\n");

fprintf(dosya_yaz,"\n");} fprintf(dosya_yaz,"\n");

for(i=0; i<n; i++){

for(j=0; j<n; j++){

for(k=0; k<n; k++){

toplam += T[i][k] * k_matris[k][j];}

M[i][j] = toplam;

toplam = 0;} printf("\n"); }

for(i=0; i<n; i++){

for(j=0; j<n; j++){

printf("%10d",M[i][j]); } printf("\n"); }

for(i=0; i<n; i++){

for(j=0; j<n; j++){

fprintf(dosya_yaz,"%10d",M[i][j]); } printf("\n"); fprintf(dosya_yaz,"\n"); } fprintf(dosya_yaz,"\n");

t++;}

int say=0;

for(i=0; i<n; i++){

for(j=0; j<n; j++){

if (M[i][j] !=0){ say++;}

} }

if (say >= 1){

printf("Nilpotent Matris Degildir.");

fprintf(dosya_yaz,"Nilpotent Matris Degildir.");

fprintf(dosya_yaz,"\n");

printf("\n");

}

}

int lcm(int x,int y){

int t;

while (y != 0)

{

t=y;

y=x%y;

x=t;

}

return x;

}
