#include<chrono>
#include<iostream>
#include<unistd.h>
#include<numeric>
#include<vector>
#include<algorithm>
#include<SortingAlgorithm.hpp>
using namespace std;

int main(int argc, char *argv[]){
    for (int i=1; i<argc;i++){
        unsigned int dim_vect=stoi(argv[i]); // converto in intero il numero preso dalla command line
        int contatore=100;
        double timeElapsed_sum=0;
//*******************************************************************************************************************
        //Considero un vettore di elementi casuali
        vector<int> vect_1(dim_vect);
        for(unsigned int i=0;i<dim_vect;i++)
            vect_1[i]=rand() % 100;
        cout<<"Il vettore di partenza e' di dimensione "<<argv[i]<<" e non e' ordinato ";
        /*for(unsigned int i=0;i<dim_vect;i++)
            cout<<vect_1[i]<<" ";*/
        cout<<endl;
        vector<int> vect_1_copia=vect_1;
        for(int i=0;i<contatore;i++)
        {
            chrono::steady_clock::time_point t_begin = chrono::steady_clock::now();
            SortLibrary::BubbleSort(vect_1);
            chrono::steady_clock::time_point t_end = chrono::steady_clock::now();
            double timeElapsed=chrono::duration_cast<chrono::nanoseconds> (t_end-t_begin).count();
            timeElapsed_sum=timeElapsed_sum+timeElapsed;
            vect_1=vect_1_copia;
        }
        cout<<"Il tempo di riordinamento utilizzando il Bubble Sort e' di "<<(timeElapsed_sum)/contatore<<" nanosecondi"<<endl;
        timeElapsed_sum=0;
        for(int i=0;i<contatore;i++)
        {
            chrono::steady_clock::time_point t_begin = chrono::steady_clock::now();
            SortLibrary::MergeSort(vect_1);
            chrono::steady_clock::time_point t_end = chrono::steady_clock::now();
            double timeElapsed=chrono::duration_cast<chrono::nanoseconds> (t_end-t_begin).count();
            timeElapsed_sum=timeElapsed_sum+timeElapsed;
            vect_1=vect_1_copia;
        }
        cout<<"Il tempo di riordinamento utilizzando il Merge Sort e' di "<<(timeElapsed_sum)/contatore<<" nanosecondi"<<endl;

//**********************************************************************************************************************
        //Considero lo stesso vettore di elementi ordinati
        timeElapsed_sum=0;
        SortLibrary::MergeSort(vect_1);
        cout<<"Il vettore di partenza e' di dimensione "<<argv[i]<<" ed e' ordinato ";
        /*for(unsigned int i=0;i<dim_vect;i++)
            cout<<vect_1[i]<<" ";*/
        cout<<endl;
        vect_1_copia=vect_1;
        for(int i=0;i<contatore;i++)
        {
            chrono::steady_clock::time_point t_begin = chrono::steady_clock::now();
            SortLibrary::BubbleSort(vect_1);
            chrono::steady_clock::time_point t_end = chrono::steady_clock::now();
            double timeElapsed=chrono::duration_cast<chrono::nanoseconds> (t_end-t_begin).count();
            timeElapsed_sum=timeElapsed_sum+timeElapsed;
            vect_1=vect_1_copia;
        }
        cout<<"Il tempo di riordinamento utilizzando il Bubble Sort e' di "<<(timeElapsed_sum)/contatore<<" nanosecondi"<<endl;
        timeElapsed_sum=0;
        for(int i=0;i<contatore;i++)
        {
            chrono::steady_clock::time_point t_begin = chrono::steady_clock::now();
            SortLibrary::MergeSort(vect_1);
            chrono::steady_clock::time_point t_end = chrono::steady_clock::now();
            double timeElapsed=chrono::duration_cast<chrono::nanoseconds> (t_end-t_begin).count();
            timeElapsed_sum=timeElapsed_sum+timeElapsed;
            vect_1=vect_1_copia;
        }
        cout<<"Il tempo di riordinamento utilizzando il Merge Sort e' di "<<(timeElapsed_sum)/contatore<<" nanosecondi"<<endl<<endl;
    }
//*********************************************************************************************************************
    cout<<"IN CONCLUSIONE:"<<endl<<"Coerentemente con quanto visto a lezione si osserva che l'algoritmo Bubble Sort "
            "avendo costo computazionale n*n e' adatto per vettori di piccole dimensioni,viceversa "
            "l'algoritmo Merge Sort avendo costo computazionale n*log(n) e' adatto per vettori aventi dimensioni piu' "
            "elevate. Se il vettore e'a di suo gia' ordinato il Bubble Sort impiega meno tempo "<<endl;
    return 0;
}
