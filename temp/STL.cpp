#include<iostream>
#include<array>       //array , at()
#include<tuple>       //get()
#include<vector>
#include<set>
#include<functional>
#include<utility>
#include<map>
#include<unordered_set>
void CppArray()
{
    	std::array<int , 6> arr;
    	arr.fill(12);                   // fill all position with 12
		for(auto &arrs : arr)
			std::cout<<arrs<<" ";
		std::cout<<"\n";
		arr = {1,2,3,4,5,6};            //initialized array
		for(auto &arrs : arr)
			std::cout<<arrs<<" ";
		std::cout<<"Accessing element using subscript notation :\n"<<arr[0]<<"\n";
		std::cout<<"Accessing element using .at() method :\n"<<arr.at(0)<<"\n";
		//std::cout<<"Accessing element using get() method :\n"<<get<0>(arr)<<"\n";
		std::cout<<"Accessing first element using front() method :\n"<<arr.front()<<"\n";
		std::cout<<"Accessing last element using back() method :\n"<<arr.back()<<"\n";
		int* ptr = arr.data();
		std::cout<<"Address of array using data() method :\n"<<ptr<<"\nElement pointer pointing to :\n"<<*ptr<<"\n";
        std::cout<<"Size of the array using size() method :\n"<<arr.size()<<"\n";
        std::cout<<"Size of the array using size_max() method : \n"<<arr.max_size()<<"\n";
        std::array<int , 6> arr2;
        arr2.fill(6);
        arr.swap(arr2);
        std::cout<<"Array element after swaping two array are :\n";
        for(auto &arrs : arr)
        	std::cout<<arrs<<" ";
        std::cout<<"\nChecking if array is empty using method empty() :\n";
        std::cout<<arr.empty();
}

void CppVector()
{
	std::cout<<"\n=====================vector=======================\n";
    std::vector<int> vec1;     //also called as array list or dynamic array
    vec1.reserve(3);  //already reserve the size so it don,t need to double but it double when reserved size is exhausted
    vec1.push_back(61);
    vec1.push_back(62);
    vec1.push_back(63);
    std::cout<<vec1.size()<<"\n";          //give total element of the vector
    std::cout<<vec1.capacity()<<"\n";
    vec1.resize(5);      //it resize the vector to 5 and initialize other element to 0 so when it push back it append at end
    vec1.push_back(64);
    vec1.push_back(65);
    std::vector<int> vec2(5,56); //initialize all 5 element to 56
    std::cout<<"we call use at() , [] ,swap() , front() , back() , data() ,empty() , size() return size and max_size() return capacity \n";
    std::cout<<vec1.size()<<"\n";          //give total element of the vector
    std::cout<<vec1.capacity()<<"\n";      //gives capacity of the vector
    std::cout<<"====================Vector Iterator===================\n";
    for(std::vector<int>::iterator i{vec1.begin()};i != vec1.end();i++)  //iterate forward
    	std::cout<<*i<<" ";
    std::cout<<"\n";
    for(std::vector<int>::reverse_iterator i{vec1.rbegin()};i != vec1.rend();i++)                      //iterate reverse
    	std::cout<<*i<<" ";
    std::cout<<"\n"<<vec1.capacity()<<"\n";
    vec1.shrink_to_fit();                //reduce capacity of the vector do not reduce size
    std::cout<<vec1.capacity()<<"\n";
    vec1.assign(7,12);                //assign 12 to all element
    vec1.pop_back();                  //removes the last element  size decreases but capacity remain same
    std::vector<int>::iterator ptr1 = vec1.begin();
    vec1.insert(ptr1,56);              //you need iterator address of that position
    vec1.erase(ptr1);                  //erase one element form the vector
    vec1.emplace(vec1.begin());        //insert element at the beginning
    vec1.emplace_back(44);             //insert at end double capacity
    std::cout<<vec1.capacity();

}

class student
{
public:
  std::string name;
  int age;
  bool operator<(const student &rhs)const
  {
	  return age<rhs.age;
  }
  bool operator>(const student &rhs)const
  {
	  return age>rhs.age;
  }
};

void CppSet()
{
	std::cout<<"\n=====================SET==========================\n";
   std::set<int , std::greater<>> S;   //no duplicate
   S.insert(6);
   S.insert(7);
   S.insert(56);
   S.insert(1);
   S.insert(2);
   S.insert(4);
   for(auto &se : S)
	   std::cout<<se<<" ";
   std::cout<<"\n";
  std::set<student , std::less<>> Set{{"Shubham",21},{"saurabh",24},{"jeevan",27}};
  for(auto &se : Set)
	  std::cout<<se.name<<" "<<se.age<<"\n";
  std::set<std::string , std::less<>> str;
  str.insert("bac");       //same character less<>  string length small first
  str.insert("cbc");       //less  a first z last
  str.insert("abc");       //less capital first
  str.insert("Abc");
  str.insert("sa");
  str.insert("saa");
  for(auto &s : str)
	  std::cout<<s<<" ";


}

void  CppMap()
{
	std::cout<<"\n==============Map===================\n";
  std::map<int,std::set<char>> M;
  M[1] = {'a','d','c','a'};
  M[2] = {'b','d','a','c','f'};
  int i{1};


  while(i<=2)
  {
	  for(auto &s : M[i])
	  {std::cout<<s<<" ";}
	  std::cout<<"\n";
	  i++;
  }
  std::string str{"dvdf"};
  //std::cin>>str;
  int j{0},max{0},h{0};
     std::unordered_set<char> US;
     while(j<str.length())
     {
  	   if(US.find(str[j]) == US.end())
  	   {
  		   US.insert(str[j]);
  		   j++;
             if(max<US.size())
                max =US.size();
  	   }
  	   else
  	   {
  		   US.erase(str[h]);
             h++;
  	   }
     }
   std::cout<<max;
}

int main()
{
   std::cout<<std::boolalpha;
   CppArray();
   CppVector();
   CppSet();
   CppMap();

	return 0;
}

