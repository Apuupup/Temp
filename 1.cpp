#include<bits/stdc++.h>
using namespace std;

 
int times=20;
int num1=0;
int num2=0;
int num3=0;
int num4=0;
 
//记录每个学生的编号，历史缺席次数，本次课是否缺席
struct Student{
    
    int index;
    int flag[20]={};
    
}; 
 
//随机生成0~R-1的自然数
int rd(int R){
    return rand()%R;
}
 

 
//存放学生数据
vector<Student>vec;
void calculate(vector<Student>vec);
//记录是否为那5~8名同学
bool vis[1000];
int ta[]={};
int ka[]={};
int pa[]={};
int ma[]={};

 
int main(){
    //设置课堂人数，以及历史缺勤次数总和上限
    srand(time(0));
    int n=90,top=times*20;
    Student st;
    st.index=0;
    //读入学生数据
    for(int i=1;i<=n;i++){
        st.index = i;
        vec.push_back(st);
    }
    
    //随机缺席80%课程的人数
    int absence_num=5+rd(4);
    set<int>s;
    //随机具体的编号
    while(s.size()<absence_num)
        s.insert(rd(n)+1);
        while(!s.empty()){
        int idx=(*s.begin())-1;
        s.erase(s.begin());
        for(int i=0;i<20;i++){
              int t=rd(100);
              if(t<80){
                vec[idx].flag[i]=1;
              }
        }
        //标记该学生
        vis[idx+1] = true;
    }
     //将正常学生分离出来
    vector<int>veci;
    for(int i=1;i<=n;i++)
        if(vis[i]==0)veci.push_back(i);
       
    for(int i=0;i<20;i++){
        //随机生成本次课缺席人数0~3
        int now_absence=rd(4);
   
        //随机打乱正常学生学生的排列
    random_shuffle(veci.begin(), veci.end());
    //设置本次课是否缺席
    for(int j=0;j<now_absence;j++)
        vec[veci[i]-1].flag[i] = 1;
       }
    
   
    
    //输出学生名单
    for(int i=0;i<vec.size();i++){
              printf("%d ",vec[i].index);
              for(int j=0;j<19;j++)
              printf("%d ",vec[i].flag[j]);
              printf("%d\n",vec[i].flag[19]);
    }
       calculate(vec);
    return 0;
    
}
void calculate(vector<Student>vec){
     double sum=0,e=0;
   
     for(int i=0;i<90;i++){
        if(num1==9) 
        break;
        if(vec[i].flag[0]==1){
        ta[num1++]=vec[i].index;
        e++;
        }
        sum++;
     }
    for(int i=0;i<num1;i++)
    {
        for(int j=1;j<20;j++){
         if(vec[ta[i]-1].flag[j]==1)
         e++;
         sum++;
        }
    }

      
     printf("%lf",e/sum);
     
}