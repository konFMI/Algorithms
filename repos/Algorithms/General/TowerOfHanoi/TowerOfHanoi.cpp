// Example program
#include <iostream>
#include <string>
const int NumberOfDisks = 5;
const int Width = (NumberOfDisks*2) - 1;
struct Peg
{
    int height = 0;
    char grid[NumberOfDisks+1][Width];
    char name = ' ';
};
Peg pegs[3];
Peg A,B,C;
 char grid[NumberOfDisks+1][Width*3+1];
 void Print()
 {
     for(int i = 0; i<= NumberOfDisks; i++)
     {
         for(int j =0; j< Width ; j++)
         {
             grid[i][j] = A.grid[i][j];
             grid[i][Width + j] = B.grid[i][j];
             grid[i][Width * 2 + j] = C.grid[i][j];
         }
         for(int j =0; j< 3*Width ; j++)
         {
             std::cout<<grid[i][j];
         }
         std::cout<<std::endl;
     }
 }
void LoadPegs()
{
    A.height = NumberOfDisks;
    for(int i = 0; i<=NumberOfDisks;i++)
    {
       for(int j = 0; j<Width;j++)
        {
            if(i == NumberOfDisks)
           {
               A.grid[i][j]  = '#'; 
               B.grid[i][j] = '#';
               C.grid[i][j] = '#';
           }
             else{  
                 A.grid[i][j]  = ' '; 
                 B.grid[i][j] = ' ';
                 C.grid[i][j] = ' ';
             }
        }
    }
    for(int i = 0; i<NumberOfDisks;i++)
    {
       for(int j = Width/2 - i; j<=Width/2 + i;j++)
        {
            A.grid[i][j]  = '1'; 
            
        }
    }
}
void PrintPegs()
{
    std::cout<<"***********************************************"<<std::endl;
    for(int i = 0; i<=NumberOfDisks;i++)
    {
       for(int j = 0; j<Width;j++)
        {
            std::cout<<A.grid[i][j]; 
        }
        std::cout<<std::endl;
    
    }
            std::cout<<std::endl;

     for(int i = 0; i<=NumberOfDisks;i++)
    {
       for(int j = 0; j<Width;j++)
        {
            std::cout<<B.grid[i][j]; 
        }
        std::cout<<std::endl;
    
    }
            std::cout<<std::endl;

     for(int i = 0; i<=NumberOfDisks;i++)
    {
       for(int j = 0; j<Width;j++)
        {
            std::cout<<C.grid[i][j]; 
        }
        std::cout<<std::endl;
    
    }
    std::cout<<"***********************************************"<<std::endl;
}
void MovePeg(Peg* fromPeg, Peg* toPeg)
{
    int i = NumberOfDisks - fromPeg->height;
    for(int j = Width/2 - i; j<=Width/2 + i;j++)
        {
             toPeg->grid[NumberOfDisks - toPeg->height-1][j] = fromPeg->grid[i][j] ;
            fromPeg->grid[i][j]  = ' ';
        }
        toPeg->height++;
        fromPeg->height--;
}
void TowerOfHanoi(int n, Peg* fromPeg, Peg* toPeg , Peg* aux)
{
    if(n == 1) 
    {
        MovePeg(fromPeg,toPeg);
        Print();
        return;
    }
    // Move the n-1 disks from A to B using C as aux
    TowerOfHanoi(n-1,fromPeg, aux, toPeg);
    
    MovePeg(fromPeg,toPeg);
    Print();
    TowerOfHanoi(n-1,aux,toPeg,fromPeg);
}

int main()
{
    std::cout<<"Tower of Hanoi with "<<NumberOfDisks<<" disk.\n";
    LoadPegs();
    Print();
    TowerOfHanoi(NumberOfDisks,&A,&C,&B);
    std::cout<<"The end!\n";
    
  //TowerOfHanoi(3,'A','C','B');
}
