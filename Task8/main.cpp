//
// Created by lexa2k on 30.11.2022.
//
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//Имеется определенный набор предметов П1, П2,..., Пn (каждый в единственном экземпляре); известны их веса
// q1, q2, ..., qn и стоимости с1, с2, ..., сn. Грузоподъемность машины равна Q. Спрашивается, какие из предметов нужно
// взять в машину, чтобы их суммарная стоимость (при суммарном весе ≤Q) была максимальна?

static long long bruteCnt=0;
static long long crudeCnt=0;

string BruteForce(int q[],int c[],int n,int Q){
    unsigned long long best_combination=0;
    unsigned long long best=0;
    bruteCnt+=pow(2,n);
    for(int i=0;i<(1<<n);i++){
        unsigned long long sum=0;
        unsigned long long weight=0;
        for(int j=0;j<n;j++){
            bruteCnt+=2;
            if(i&(1<<j)){
                sum+=c[j];
                weight+=q[j];
            }
        }
        if(weight<=Q && sum>best){
            bruteCnt++;
            best=sum;
            best_combination=i;
        }
    }
    //convert to binary
    //return binary
    string result;
    for(int i=0;i<n;i++){
        if(best_combination&(1<<i)) result+='1';
        else result+='0';
    }
    return result;

}

string Greedy(int *&q,int *&c,int n,int Q) {
    //sort by q and c by c/q and take first elements until Q is reached
    string result;
    int sum = 0;
    int weight = 0;

    for(int i=0;i<n;i++){
        crudeCnt++;
        for(int j=0;j<n-1;j++){
            crudeCnt+=2;
            if(c[j]/q[j]<c[j+1]/q[j+1]){
                int tempc=c[j];
                int tempq=q[j];
                c[j]=c[j+1];
                q[j]=q[j+1];
                c[j+1]=tempc;
                q[j+1]=tempq;

            }
        }
    }
    //cout q and c
    for(int i=0;i<n;i++){
        cout<<q[i]<<" "<<c[i]<<endl;
    }


    for(int i=0;i<n;i++){
        crudeCnt+=2;
        if(weight+q[i]<=Q){
            weight+=q[i];
            sum+=c[i];
            result+='1';
        } else result+='0';
    }
    return result;

}

int main() {
    system("chcp 65001");
    cout<<"Лабораторная работа №8. Алгоритмические стратегии или методы разработки алгоритмов. Перебор и методы его сокращения. Смольников Алексей. Вариант 2(22)"<<endl;

    cout<<"Имеется определенный набор предметов П1, П2,..., Пn (каждый в единственном экземпляре); известны их веса\n"
          " q1, q2, ..., qn и стоимости с1, с2, ..., сn. Грузоподъемность машины равна Q. Спрашивается, какие из предметов нужно\n"
          "взять в машину, чтобы их суммарная стоимость (при суммарном весе ≤Q) была максимальна?"<<endl;

    cout<<"Введите количество предметов: ";
    int n;
    cin>>n;
    cout<<"Введите грузоподъемность машины: ";
    int Q;
    cin>>Q;
    int* q = new int[n];
    cout<<"Введите веса предметов: ";
    for(int i=0;i<n;i++){
        cin>>q[i];
    }

    int* c = new int[n];
    cout<<"Введите стоимости предметов: ";
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    cout<<"Результат: "<<BruteForce(q,c,n,Q)<<endl;
    cout<<"Где 1 - предмет взят, 0 - оставлен. Читать справа налево, незначащие нули отброшены"<<endl;

    cout<<"Жадный алгоритм"<<endl;
    cout<<"Результат: "<<Greedy(q,c,n,Q)<<endl;

    cout<<"Количество операций перебора: "<<bruteCnt<<endl;
    cout<<"Количество операций жадного алгоритма: "<<crudeCnt<<endl;


    return 0;
}