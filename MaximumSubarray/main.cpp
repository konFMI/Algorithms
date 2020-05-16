
 #include<iostream>
 #include"MaximumSubarray.cpp"
 
 void TestCode()
{
    tuple<int,int,int> data;
    int size = 0;
    do
    {
        std::cout<<"Enter size of the array: ";
        std::cin>>size;
    } while (size < 0 && size > 10000);
    
    int* array = new int[size];
    std::cout<<"Enter "<<size<<" values for the array."<<std::endl;
    for (size_t i = 0; i < size; i++)
    {
        int inputValue = 0;
        
        while (!std::cin>>inputValue)
        {
            std::cout<<"Enter a valid integer."<<std::endl;
        }
        array[i] = inputValue;
        
    }
    //1 2 3 -123 2 3 -23 3 4 1
    int low = 0, high = size - 1;
    int mid = (low+high) / 2;

    data = FindMaxSubarray(array, low, high);
    std::cout<<"The maximum subarray is:"<<std::endl;
    std::cout<<"[ ";
    for (size_t i = get<0>(data); i <= get<1>(data); i++)
    {
        std::cout<<array[i]<<" ";
    }
    std::cout<<"]"<<std::endl;
    std::cout<<"With the maximum sum of "<<get<2>(data)<<std::endl;
    delete array;
}
 void TestCodeBook()
 {
     int array[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
     tuple<int,int,int> data = FindMaxSubarray(array,0,15);
     std::cout<<get<2>(data)<<std::endl;
     for (size_t i = get<0>(data); i <= get<1>(data); i++)
     {
         std::cout<<array[i]<< " ";
     }
     std::cout<<"\nMax sum: "<<get<2>(data)<<"\n";
 }
 int main(){
     TestCodeBook();
 }
