#include<bits/stdc++.h>
using namespace std;

class Point{
   public:
      int x,y;
   
      Point(int x,int y){
         this->x = x;
         this->y = y;
      }
};

bool myComparisionFuntion2(Point p1,Point p2){
   //sorting decending order, ">" means decending 
   return p1.x > p2.x;
}

bool myComparisionFuntion1(Point p1,Point p2){
   //sorintg ascending order, "<" means ascending 
   return p1.x < p2.x;
}

int main(){
   
   vector<Point> coordinates = {{2,4} ,{90,59}, {30,40}};
   auto it = max_element(coordinates.begin(),coordinates.end(),myComparisionFuntion1);
   cout<<(*it).x<<" "<<(*it).y<<" ";
   
   return 0;
}