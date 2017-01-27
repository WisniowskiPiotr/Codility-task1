#include <vector>
#include <iostream>
using namespace std;

class line{
  private: 
  long long int Sum;
  
  public: 
  void SetSum(vector<int> a){
    Sum=0;
    for(int i=0;i<a.size();i++)
      Sum+=a[i];
  };

  long long int GetSum(){
    return Sum;
  };
};

class line_collection{
  public: vector<line> Lines;
  
  public:
  line_collection(int count){
    Lines.resize(count);
  };

  vector<int> SumLines(int poz){
    int Index=Lines.size();
    int out=0;
    vector<int> result {0, 0};
    for(int i=0;i<Index; i++){
      if(i==poz)
        out++;
      result[out]+=Lines[i].GetSum();
    };
    return result;
  };
};

int solution(vector< vector<int> > &A){
  int Index_x=A.size();
  int Index_y=A[0].size();
  // co jeśli któryś wiersz ma mniej elementów?
  line_collection Lines_x(Index_x);
  line_collection Lines_y(Index_y);
  int result=0;

  vector<int> tmp(Index_y, 0);
  for(int j=0;j<Index_y;j++){
    for(int i=0;i<Index_x;i++){
      Lines_x.Lines[i].SetSum(A[i]);
      tmp[j]=A[i][j];
    };
    Lines_y.Lines[j].SetSum(tmp);
  };

  for(int i=1;i<Index_x;i++){
    if(Lines_x.SumLines(i)[0]==Lines_x.SumLines(i)[1]){
      for(int j=1;j<Index_y;j++){
        if(Lines_y.SumLines(j)[0]==Lines_y.SumLines(j)[1]){
          result++;
        };
      };
    };
  };
  return result;
};

int main(int argc,char *argv[]){
  vector< vector<int> > A;
  A={{1, -1, 1}, {1, -1, 0}};
  cout<<solution(A)<<"\n";

  A={{-1, 0,  1}, 
     { 1, 0,  1},
     { 1, 0, -1}};
  cout<<solution(A)<<"\n";

  A={{0, 2, 0}, {1, -1, 0}};
  cout<<solution(A)<<"\n";

  A={{}};
  cout<<solution(A)<<"\n";
 

};