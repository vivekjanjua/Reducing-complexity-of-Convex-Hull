# include<bits/stdc++.h>
using namespace std;
vector<long long>table[10000];int k1,top1 =-1, top2 =-1, top3 =-1, top4 =-1;
double hull_points_x[100] , hull_points_y[100] ,slope [100],
max_y [10000] ;
double hull_points_x2 [100] ,hull_points_y2 [100] , slope2[100],min_y[10000];
double status [1000] [1000] ,ans_x [ 1000] ,ans_y[1000] ;
double get_slope ( long long x1 , long long y1 , long long x2 , long long y2 ){
return ( ( double ) ( y2-y1 ) / ( double ) ( x2-x1 ) ) ; g
void push hull ( int i , int j ){
top1 ++;
hull_points_x [ top1 ]= i ;
hull_points_y [ top1 ]= j ; }
void pushhull2 ( int i , int j ){
top3 ++;
hull_points_x2 [ top3 ]= i ;
hull_points_y2[ top3 ]= j ; }
void pophull( ) {
top1--;}
double popslope() {
top2--;
double k= slope[ top2 ] ;
return k ; }
void pophull_2 () {
top3--;}
double popslope2 () {
top4--;
double k= slope2[top4] ;
return k ; }
void pushslope ( double m){
top2++;
slope [top2]=m; }
void pushslope2 ( double m){
top4++;
slope2 [ top4 ]=m; }
void make_hull( double point_x [], double point_y [] ,
vector<long long>table [] , long long n , long long mini ,
long long maxi , long long z1 ){
int i , p1 , flag =0; double m, prev ;
for (i =0; i<table [ mini ] . size () ; i++)
push_hull(mini , table [ mini ] [ i ] ) ;
for ( i =mini ; i<=maxi ; i ++){
if ( ( table [ i ] .size ()!=0)&&( flag==0) ){
flag=1; p1= i ; continue ; }
else i{ ( ( table [i] . size () !=0)&&( flag==1) ){
m= get_slope ( p1,max_y [p1] , i, max_y [ i ] ) ;
if( p1==mini ){
if( max_y [i]>point_y [ z1 ] ) {
push_hull (i,max_y[i]) ;
prev = get_slope(p1,max_y [ p1 ] , i , max_y [ i ] ) ;
push_slope (prev) ;
p1= i ; }}
else {
if(m<=prev ){
push_hull(i , max_y [i ]);  
push_slope (m) ;
prev=m; }
else {
while ( (m>prev )&&( top2 >=0)){
pop_hull ( ) ;
prev = pop_slope() ;
m= get_slope(hull_points_x [ top1 ] , hull_points_y [ top1 ] , i , max_y [ i ] ) ; }
push_hull ( i , max_y [ i ] ) ;
push_slope(m) ;
prev =m; }
p1= i ;}}}}
void make_hull2 ( double point_x [] , double point_y [] , vector<long long>table [] ,
long long n , long long mini , long long maxi , long long z1 ){
int i , p1 , flag=0; double m,prev ;
for ( i =0; i<table [ mini ] . size () ; i++)
push_hull2 ( mini , table [ mini ] [ i ] ) ;
for ( i =mini ; i<=maxi ; i++){
if( ( table [ i ] . size() !=0)&&( flag==0) ){
flag=; _= i;continue;
else if( ( table [ i ] . size () !=0)&&( flag==1) ){
m= get_slope (p1, min_y[p1] , i , min_y [ i ] ) ;
if( p1==mini ){
if( min_y [i]<point_y [ z1 ] ) {
push_hull2(i,min_y [ i ] ) ;
prev = get_slope( p1 , min_y [ p1 ] , i , min_y [ i ] ) ;
push_slope2 ( prev ) ;
p1= i ; }}
else{
if(m>=prev ){
push_hull2 ( i , min_y [ i ]);  
push_slope2(m) ;
prev=m; }
else {
while ( (m<prev )&&( top4 >=0)){
pop_hull2() ;
prev = pop_slope2 () ;
m=get_slope(hull_points_x2 [ top3 ] , hull_points_y2 [ top3 ] , i , min_y [ i ] ) ; }
push_hull2 ( i , min_y [ i ] ) ;
push_slope2 (m) ;
prev =m; }
p1= i ;}}}}
int main() {
long long n , i , z1 , z2 , a , j , g , flag=0 , flag2 =0, flag3=0;
cout<<"Enter the Number of points \n ” ;
cin>>n ;
double z , point_x [ n ] , point_y [ n ] , mini =1e9 , maxi=-1e9 ;
cout<<"Enter t h e P o i n t s Co o r d i n a t e s i n <x y> format correct upto two decimal place "
for ( i =0; i<n ; i ++){
cin>>point_x [ i ]>>point_y [ i ] ;
if( point_x [ i ]<mini )
mini= point_x[i];
if( point_x [ i ]>maxi )
maxi= point_x[i];}
z=mini ;
if( mini <0){
for ( i =0; i<n ;i++)
point_x[ i ]= point_x [ i ]-1*mini ; }
flag= flag2=0;
for(i =0; i<n ; i++){
point_x [ i ] = ( long long ) ( 100*point_x [ i ] ) ;
point_y [ i ] = ( long long ) ( 100*point_y [ i ] ) ;
max_y [ ( long long )point_x [ i ]]=-1e7 ;
min_y [ ( long long )point_x [ i ] ]=1e7 ;
if( ( flag== 0 ) || (point_x[ i ]<mini ) ) {
flag=1;z1=i ,z2=i ;mini=point_x [ i ] ; }
else if(point_x [ i ]== mini ){
if( point_y[ i]point_y[ z1 ] )
z1=i;
i(point_y [ i ]>point_y [ z2 ] )
z2= i;}
if((flag2 == 0 )||( point_x [ i ]>maxi ) ) {
flag2 =1; maxi= point_x[ i ] ; }
}
for ( i =0; i<n ; i++){
table [ ( long long ) (point_x [ i ] ) ] . push_back ( point_y [ i ] ) ;
max_y [ ( long long )point_x [ i ] ] =max ( point_y [ i ] , max_y [ ( long long )point_x [ i ] ] ) ;
min_y [ ( long long )point_x [ i ] ] = min ( point_y [ i ] , min_y [ ( long long )point_x [ i ] ] ) ;

if( ( flag3==0 ) ||( point_y [ i ]>g ) ) {
flag3 =1; g=  point_y[i] ; }}
make_hull (point_x , point_y , table , n , mini , maxi , z1 ) ;
make_hull2 (point_x , point_y , table , n , mini , maxi , z2 ) ;
for ( i =0; i<=top1 ; i++){
ans_x [ k1 ] = ( ( hull_points_x [ i ] ) / 100 ) + ( z<0?z : 0 ) ;
ans_y [ k1 ] = ( hull_points_y [ i ] ) / 100 ;
status [ ( long long ) ans_x [ k1 ] ] [ ( long long ) ans_y [ k1 ] ] = 1 ;
k1++;}
for ( i =0; i<=top3 ; i++){
if(status [ ( long long ) ( ( ( hull_points_x2 [ i ] ) / 100 ) + ( z<0?z : 0 ) ) ] [ ( long long ) ( hull_points)
ans_x[ k1 ] = ( ( hull_points_x2[ i ] ) / 100 ) + ( z<0?z : 0 ) ;
ans_y[ k1] =  ((hull_points_y2[ i ] ) / 100 ;
k1++;}}
for ( i =0; i<k1 ; i++)
cout<<ans_x[ i ]<<""<<ans_y [ i ]<<endl ;
return 0 ; }