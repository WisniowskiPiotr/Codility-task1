class line{
  private: long long int Sum=0;
  
  public: 
  void Sum(vector<line> a){
    for(i=0;i<a.size();i++)
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

int solution(vector<vector<int>> &A){
  int Index_x=A.size();
  int Index_y=A[0].size();
  // co jeśli któryś wiersz ma mniej elementów?
  line_collection Lines_x(Index_x);
  line_collection Lines_y(Index_y);
  int result=0;

  vector<int> tmp(Index_y);
  for(int j=0;j<Index_y;j++){
    for(int i=0;i<Index_x;i++){
      Lines_x.Lines[i].Sum(A[i]);
      tmp[j]=A[i][j];
    };
    Lines_y.Lines[j].Sum(tmp);
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
};

int main(){
  vector<vector<int>> &A{{1, -1, 1},
                         {1, -1, 0}};
  cout<<solution(A)<<"\n";

};