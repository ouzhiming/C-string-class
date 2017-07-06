#ifndef _CMYSTRING_H
#define _CMYSTRING_H
#include <cstring>
#include <ostream>
#include <iostream>

class CMyString
{
        friend std::ostream& operator<<( std::ostream& os, const CMyString& str);
        private:
                char* m_pData; //  私有变量保存字符串
				int m_len;     //字符串的长度
        public:
                /*
                 * 构造函数
                 */
				CMyString(); //默认构造函数

				CMyString( const char* str ); // C字符串构造函数
				CMyString( const int &num, const char &c); //num个字符c
				CMyString( const char* str, const int &len);  //将C字符串前len个字符作为字符串s的初值。


                CMyString( const CMyString& str ); // 拷贝构造函数
				CMyString( const CMyString& str, const int &index); //从索引index的拷贝构造函数
				CMyString( const CMyString& str, const int &index, const int &len);//从索引index的、长度为len的拷贝构造函数
			

                ~CMyString( void ); // 析构函数
                

               /*
                *字符串操作函数
                */

                CMyString& operator=( const CMyString& str ); // 赋值运算符
                CMyString operator+( const CMyString& str ); // 字符串连接 
                bool operator==( const CMyString& str ); // 判断相等
                char operator[](const int idx ); // 数组索引
                int getLength(); // 返回长度

				char * getString();//返回C类型字符串

                void swap(CMyString &str1, CMyString &str2); //交换2个字符串的值
                CMyString & insert(CMyString str, const int &index); //在索引index处插入字符
                
				//std::ostream& operator<<(std::ostream& os, const CMyString& str);
				//std::ostream & operator<<(std::ostream & os);
};

#endif
