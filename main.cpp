#include "CMyString.cpp"
#include <iostream>

int main()
{
	CMyString str("sly");
	std::cout << str.getString() << std::endl;
    std::cout << str << std::endl;	
	CMyString str1;
    str1 = str;
    std::cout << str1 << std::endl;
    std::cout << str1[1] << std::endl;
    int len = str1.getLength();
    std::cout << "len = " << len << "   " << str1[len] << std::endl;
    if(str == str1)
       std::cout << "相等" << std::endl;
    str = str + str1;
    std::cout << str << std::endl;
    if(str == str1)
       std::cout << "相等" << std::endl;
    else
         std::cout << "不相等"<< std::endl;
    CMyString str2(10,'w');
    std::cout << str2 << std::endl;
    CMyString str3("asdfg123",5);
    std::cout << "str3 = "<< str3 << std::endl;
    CMyString str4(str3, 1);
    std::cout << "str4 = " <<  str4 << std::endl;
    CMyString str5(str3, 1, 9);
    std::cout << "str5 = " <<  str5 << std::endl;
    return 0;
}
