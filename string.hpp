#include <string>
#include <iostream>

class string
{
private:
    char* m_data;
    unsigned long long int m_size;

public:
    // Constructors
    string(const char* str)
    {
        m_size = strlen(str);
        m_data = new char[m_size + 1];
        memcpy(m_data, str, m_size + 1);
    }

    string(long long int size)
    {
        m_size = size;
        m_data = new char[size];
    }

    string(const string& rhs)
    {
        for (int i = 0; i < this->m_size; i++)
        {
            this->m_data[i] = rhs.m_data[i];
        }

        this->m_size = rhs.m_size;
        
    }

    // Move constructor
    string(string&& other)
    {
        m_size = other.m_size;
        m_data = other.m_data;
        other.m_data = nullptr;
        other.m_size = 0;
    }

    // Destructor
    virtual ~string()
    {
        delete[] m_data;
        m_data = nullptr;
        m_size = 0;
    }

    long long int GetSize()
    {
        return m_size;
    }
    char* GetBuf() const
    {
        return m_data;
    }   

    //operator=
    string& operator=(const string& rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }
        
        long long int max = 0;
        long long int min = 0;
        if(this->m_size > rhs.m_size)
        {
            max = this->m_size;
            min = rhs.m_size;
        }
        else
        {
            max = rhs.m_size;
            min = this->m_size;
        }
        
        char* tmp = new char[max];
        for (int i = 0; i < min; i++)
        {
            tmp[i] = rhs.m_data[i];
        }

        this->m_data = tmp;
        tmp = nullptr;

        this->m_size = rhs.m_size;

        return *this;
        
    }
    string& operator=(std::string str)
    {
        long long int max = 0;
        long long int min = 0;
        if(this->m_size > str.size())
        {
            max = this->m_size;
            min = str.size();
        }
        else
        {
            max = str.size();
            min = this->m_size;
        }

        char* tmp = new char[max];
        for (int i = 0; i < min; i++)
        {
            tmp[i] = str[i];
        }

        this->m_data = tmp;
        tmp = nullptr;

        this->m_size = str.size();

        return *this;
        
    }
    string& operator=(const char* cptr)
    {
        long long int max = 0;
        long long int min = 0;
        long long int size_for_cptr = strlen(cptr);
        if(this->m_size > size_for_cptr)
        {
            max = this->m_size;
            min = size_for_cptr;
        }
        else
        {
            max = size_for_cptr;
            min = this->m_size;
        }

        char* tmp = new char[max];

        for (int i = 0; i < min; i++)
        {
            tmp[i] = cptr[i];
        }

        this->m_data = tmp;
        tmp = nullptr;

        this->m_size = size_for_cptr;;

        return *this;
    }

    //operator+
    string operator+(const string& rhs)
    {
        unsigned int tmpindex = 0;
        string tmp(this->m_size + rhs.m_size);
        for (int i = 0; i < this->m_size; i++)
        {
            tmp.m_data[i] = this->m_data[i];
            ++tmpindex;
            
        }

        for (int i = 0; i < rhs.m_size; i++)
        {
            tmp.m_data[tmpindex] = rhs.m_data[i];
            ++tmpindex;
        }
        
        return tmp;  
    }
    string operator+(std::string str)
    {
        unsigned int tmpindex = 0;
        string tmp(this->m_size + str.size());
        for (int i = 0; i < this->m_size; i++)
        {
            tmp.m_data[i] = this->m_data[i];
            ++tmpindex;
            
        }

        for (int i = 0; i < str.size(); i++)
        {
            tmp.m_data[tmpindex] = str[i];
            ++tmpindex;
        }
        return tmp;
    }
    string operator+(const char* cptr)
    {
        long long int size_for_cptr = strlen(cptr);
        unsigned int tmpindex = 0;
        string tmp(this->m_size + size_for_cptr);
        for (int i = 0; i < this->m_size; i++)
        {
            tmp.m_data[i] = this->m_data[i];
            ++tmpindex;
            
        }

        for (int i = 0; i < size_for_cptr; i++)
        {
            tmp.m_data[tmpindex] = cptr[i];
            ++tmpindex;
        }
        return tmp;
    }

};

std::ostream& operator<<(std::ostream& os, const string& str)
{
    os << str.GetBuf();
    return os;
}
string operator+(std::string str, string& rhs)
{
    unsigned int tmpindex = 0;
    string tmp(str.size() + rhs.GetSize());
    char* tmpbuf = tmp.GetBuf();

    for (int i = 0; i < str.size(); i++)
    {
        tmpbuf[i] = str[i];
        ++tmpindex;
        
    }

    char* rhsbuf = rhs.GetBuf();
    for (int i = 0; i < rhs.GetSize(); i++)
    {
        tmpbuf[tmpindex] = rhsbuf[i];
        ++tmpindex;
    }
    return tmp;
}

string operator+(const char* cptr, string& rhs)
{
    unsigned int tmpindex = 0;
    long long int size_of_cptr = strlen(cptr);
    string tmp(size_of_cptr + rhs.GetSize());
    char* tmpbuf = tmp.GetBuf();

    for (int i = 0; i < size_of_cptr; i++)
    {
        tmpbuf[i] = cptr[i];
        ++tmpindex;
        
    }

    char* rhsbuf = rhs.GetBuf();
    for (int i = 0; i < rhs.GetSize(); i++)
    {
        tmpbuf[tmpindex] = rhsbuf[i];
        ++tmpindex;
    }
    return tmp;
}







