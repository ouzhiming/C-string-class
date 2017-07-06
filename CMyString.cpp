
#include "CMyString.h" 

using namespace std;
CMyString::CMyString()//默认构造函数
{
	this->m_len = 0;
	this->m_pData = new char(this->m_len + 1);
	this->m_pData[0] = '\0';
}

// C字符串构造函数
CMyString::CMyString(const char* str)
{
	if (!str){
		this->m_len = 0;
		this->m_pData = new char(this->m_len + 1);
		this->m_pData[0] = '\0';
	}
	else{
		this->m_len = strlen(str);
		this->m_pData = new char[this->m_len + 1];
		strcpy(this->m_pData, str);

		//另一种实现方式，strcpy_s保证缓冲区尺寸，避免发生不可预料的事，故这里使用strcpy_s
	//	strcpy_s(this->m_pData, this->m_len + 1, str);
	}

}

//num个字符c
CMyString::CMyString(const int &num, const char &c)
{
	if (num <= 0) {
		this->m_len = 0;
		this->m_pData = new char(this->m_len + 1);
		this->m_pData[0] = '\0';
	}
	else {
		this->m_len = num;
		this->m_pData = new char(this->m_len + 1);
		for (int i = 0; i < this->m_len; i++) {
			this->m_pData[i] = c;
		}
	}

}

//将C字符串前len个字符作为字符串s的初值。
CMyString::CMyString(const char* str, const int &len)
{
	if (len <= 0) {
		this->m_len = 0;
		this->m_pData = new char(this->m_len + 1);
		this->m_pData[0] = '\0';
	}
	else {
		int len_temp = strlen(str);
		if (len_temp >= len) {
			this->m_len = len;
			this->m_pData = new char(this->m_len + 1);
		    
            	strncpy(this->m_pData,str, this->m_len);
			this->m_pData[this->m_len + 1] = '\0'; //strncpy不会追加‘\0’,所以这里手动加
			/*for (int i = 0; i < this->m_len + 1; i++) {
				this->m_pData[i] = str[i];
			}*/
		}
		else{ //len大于字符串str本身的长度
			this->m_len = len_temp; 
			this->m_pData = new char(this->m_len + 1);
			//strcpy_s(this->m_pData, this->m_len + 1, str);
			strcpy(this->m_pData, str);
		}
		
	}

}

// 拷贝构造函数
CMyString::CMyString(const CMyString& str) 
{
	if (!str.m_len)
	{
		this->m_len = 0;
		this->m_pData = new char( this->m_len + 1);
		this->m_pData[0] = '\0';
	}
	else
	{
		this->m_len = str.m_len;
		this->m_pData = new char[this->m_len + 1];
	//	strcpy_s(this->m_pData, this->m_len + 1, str.m_pData);
		strcpy(this->m_pData, str.m_pData);
	}
}

//从索引index的拷贝构造函数
CMyString::CMyString(const CMyString& str, const int &index)
{
    if(str.m_len == 0 || index >= str.m_len){
        this->m_len = 0;
        this->m_pData = new char( this->m_len +1 );
        this->m_pData[0] = '\0';
    
    }
    else{
       this->m_len = str.m_len - index;
       this->m_pData = new char( this->m_len + 1);
       int j = 0;
       for(int i = index; i < str.m_len; i++){
            this->m_pData[j++] = str.m_pData[i];
       }
    
    }

}

//从索引index的、长度为len的拷贝构造函数
CMyString::CMyString(const CMyString& str, const int &index, const int &len)
{
     if(str.m_len == 0 || index >= str.m_len){
        this->m_len = 0;
        this->m_pData = new char( this->m_len +1 );
        this->m_pData[0] = '\0';
    
    }
    else{
       int j = 0;
       if(len <= str.m_len - index){
           this->m_len = len;
           this->m_pData = new char(this->m_len + 1);
           for(int i = index; i < index + len; i++){
              this->m_pData[j++] = str.m_pData[i];
          }  
       }
       else{
         this->m_len = str.m_len - index;
         this->m_pData = new char(this->m_len + 1);
         for(int i = index; i < str.m_len; i++){
                this->m_pData[j++] = str.m_pData[i];
         }
       }      
    }

}

//析构函数
CMyString::~CMyString( void )
{
        if ( this->m_pData)
        {	
                delete[] this->m_pData;
				this->m_len = 0;
                this->m_pData = 0;
        }
}

CMyString& CMyString::operator=( const CMyString& str)
{
	if (this == &str)
		return *this;
	else //如果2个地址不同
        {
				//先释放原来的字符串
                delete[] this->m_pData;
                if ( str.m_len == 0 )
                {
					this->m_len = 0;
					this->m_pData = new char(this->m_len + 1);
					this->m_pData[0] = '\0';
                }
                else
                {
					this->m_len = str.m_len;
                    this->m_pData = new char[this->m_len + 1 ];
                    //strcpy_s( this->m_pData, this->m_len + 1, str.m_pData );
                    strcpy(this->m_pData, str.m_pData);
                }
        }
        return *this;
}

CMyString CMyString::operator+( const CMyString& str )
{
        CMyString newString;
        if ( str.m_len == 0 )
        {
                newString = *this;
        }
        else if ( this->m_len == 0 )
        {
                newString = str;
        }
        else
        {
			    newString.m_len = this->m_len + str.m_len;
                newString.m_pData = new char[newString.m_len + 1 ];
                //strcpy_s( newString.m_pData, newString.m_len + 1, this->m_pData );
                strcpy(newString.m_pData, this->m_pData);
                strcat( newString.m_pData, str.m_pData );
        }
        return newString;
}

bool CMyString::operator==( const CMyString& str )
{
        if ( this->m_len != str.m_len )
        {
                return false;
        }
        else
        {
                return strcmp( this->m_pData, str.m_pData ) ? false : true;
        }
}

char CMyString::operator[]( const int idx )
{
        if ( idx > 0 && idx < strlen( this->m_pData ) )
        return this->m_pData[idx];
}

int CMyString::getLength()
{
        return this->m_len;
}

std::ostream& operator<<( std::ostream& os, const CMyString& str )
{
        os<< str.m_pData;
        return os;
}
char * CMyString::getString() {

	return this->m_pData;
}

