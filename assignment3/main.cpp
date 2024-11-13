#include <iostream>
#include <cstdlib>
using namespace std;

typedef char* charPtr;

class CMPT125_String
{
private:
	//Member variable
	charPtr buffer;	//This will be the dynamic array to represent the cstring
	
	//Member function
	int cstrlen(const charPtr &s) const
	{
		int len = 0;
		for (int i = 0; s[i] != '\0'; i++)
			len++;
		return len;
	}
	
public:
	//Default Constructor
	CMPT125_String();

	//Non-default Constructors
	CMPT125_String(const char &c);
	CMPT125_String(const charPtr cStr); //*cStr is a cstring

	//Copy Constructor
	CMPT125_String(const CMPT125_String &s);

	//Destructor
	~CMPT125_String();

	//Assignment operators
	CMPT125_String& operator = (const CMPT125_String &s);
	CMPT125_String& operator = (const char &c);
	CMPT125_String& operator = (const charPtr cStr); //*cStr is a cstring

	//Getter member functions
	int length() const;
	char& operator[](const int &index) const;

	//Setter member functions
	void append(const CMPT125_String &s);
	void append(const char &c);
	void append(const charPtr cStr); //*cStr is a cstring

	//Operator member functions
	CMPT125_String operator + (const CMPT125_String &s) const;
	CMPT125_String operator + (const char &c) const;
	CMPT125_String operator + (const charPtr cStr) const; //*cStr is a cstring
	CMPT125_String& operator += (const CMPT125_String &s);
	CMPT125_String& operator += (const char &c);
	CMPT125_String& operator += (const charPtr cStr); //*cStr is a cstring
	bool operator == (const CMPT125_String &s) const;
	bool operator == (const charPtr cStr) const; //*cStr is a cstring
	bool operator != (const CMPT125_String &s) const;
	bool operator != (const charPtr cStr) const; //*cStr is a cstring
	bool operator < (const CMPT125_String &s) const;
	bool operator < (const charPtr cStr) const; //*cStr is a cstring
	bool operator > (const CMPT125_String &s) const;
	bool operator > (const charPtr cStr) const; //*cStr is a cstring
	bool operator <= (const CMPT125_String &s) const;
	bool operator <= (const charPtr cStr) const; //*cStr is a cstring
	bool operator >= (const CMPT125_String &s) const;
	bool operator >= (const charPtr cStr) const; //*cStr is a cstring
	
	//Friend Functions (for operators)
	friend CMPT125_String operator + (const char &c, const CMPT125_String &s);
	friend CMPT125_String operator + (const charPtr cStr, const CMPT125_String &s); //*cStr is a cstring
	friend bool operator == (const charPtr cStr, const CMPT125_String &s); //*cStr a cstring
	friend bool operator != (const charPtr cStr, const CMPT125_String &s); //*cStr is a cstring
	friend bool operator < (const charPtr cStr, const CMPT125_String &s); //*cStr is a cstring
	friend bool operator > (const charPtr cStr, const CMPT125_String &s); //*cStr is a cstring
	friend bool operator <= (const charPtr cStr, const CMPT125_String &s); //*cStr is a cstring
	friend bool operator >= (const charPtr cStr, const CMPT125_String &s); //*cStr is a cstring
	friend ostream& operator << (ostream& outputStream, const CMPT125_String &s);
	friend istream& operator >> (istream& inputStream, CMPT125_String &s);
};


//Constructors
CMPT125_String::CMPT125_String()
{
	/*
	This function constructs a default CMPT125_String object whose buffer 
	is initialized to nullptr. 

	This function is implemented by the instructor. MAKING ANY CHANGE TO IT IS NOT ALLOWED.
	*/
	buffer = nullptr;
}
CMPT125_String::CMPT125_String(const char &c)
{
	/*
	This function constructs a non-default CMPT125_String whose bufffer contains one printable
	character (which is the argument) and a null character at the end.

	This function is implemented by the instructor. MAKING ANY CHANGE TO IT IS NOT ALLOWED.
	*/
	buffer = new char[2];
	buffer[0] = c;
	buffer[1] = '\0';
}
CMPT125_String::CMPT125_String(const charPtr cStr) //*cStr is a cstring
{
	/*
	This function constructs a non-default CMPT125_String whose buffer contains all the printable
	characters of the cstring argument and a null character at the end.
	This function uses the private member function cstrlen to compute the length of the cstring argument.

	This function is implemented by the instructor. MAKING ANY CHANGE TO IT IS NOT ALLOWED.
	*/
	int len = cstrlen(cStr);
	if (len == 0)
		buffer = nullptr;
	else
	{
		buffer = new char[len+1];
		for (int i = 0; i < len; i++)
			buffer[i] = cStr[i];
		buffer[len] = '\0';
	}
}
CMPT125_String::CMPT125_String(const CMPT125_String &s)
{
	/*
	This function constructs a CMPT125_String object which is a copy of the argument s
	*/
	int len = s.length(); 
	buffer = new char[len+1];
	for(int i = 0; i < len; i++) { 
		buffer[i] = s[i];
	}
	buffer[len] = '\0'; 
}

//Destructor
CMPT125_String::~CMPT125_String()
{
	/*
	This function destructs a CMPT125_String object. That is it deletes its buffer and 
	assign the buffer a nullptr value

	This function is implemented by the instructor. MAKING ANY CHANGE TO IT IS NOT ALLOWED.
	*/
	if (buffer != nullptr)	
	{
		delete[] buffer;
		buffer = nullptr;
	}
}

//Assignment operators
CMPT125_String& CMPT125_String::operator = (const CMPT125_String &s)
{
	/*
	This function assigns a copy of the value of the argument s to the calling object
	*/
	int len = s.length();
	if(buffer != nullptr) delete [] buffer;
	buffer = new char[len+1]; 
	for(int i = 0; i < len; i++) { 
		buffer[i] = s[i];
	}
	buffer[len] = '\0';
	return *this; 

}
CMPT125_String& CMPT125_String::operator = (const char &c)
{
	/*
	This function assigns a copy of a CMPT125_String object constructed from the character argument to the calling object
	*/
	if(buffer != nullptr) 
		delete [] buffer; 
	buffer = new char[2]; 
	buffer[0] = c; 
	buffer[1] = '\0';
	return *this; 
}
CMPT125_String& CMPT125_String::operator = (const charPtr cStr) //*cStr is a cstring
{
	/*
	This function assigns a copy of a CMPT125_String object constructed from the cstring argument to the calling object
	*/
	int len = cstrlen(cStr);
	if(buffer != nullptr) 
		delete [] buffer; 
	buffer = new char[len+1]; 
	for(int i = 0; i < len; i++) { 
		buffer[i] = cStr[i];
	}
	buffer[len] = '\0';
	return *this; 
}

//Getter member functions
int CMPT125_String::length() const
{
	/*
	This function returns the length of the buffer of the calling object
	If the buffer is a nullptr, then it returns 0; othyerwise it uses 
	the private member function cstrlen to compute the length of the buffer 

	This function is implemented by the instructor. MAKING ANY CHANGE TO IT IS NOT ALLOWED.
	*/
	if (buffer == nullptr)
		return 0;
	else
		return cstrlen(buffer);
}
char& CMPT125_String::operator[](const int &index) const
{
	/*
	This function returns the character at the given index of the calling object.
	If the index is out of the valid bounds, then a runtime error occurs.
	The valid indexes are [0, this->length()-1]

	This function is implemented by the instructor. MAKING ANY CHANGE TO IT IS NOT ALLOWED.
	*/
	if (index < 0 || index > this->length() - 1)
	{
		cout << "ERROR! Index out of bound..." << endl;
		abort(); //This will crash the execution of the application
	}
	return buffer[index];
}

//Setter member functions
void CMPT125_String::append(const CMPT125_String &s)
{
	/*
	This function appends a copy of the value of the argument s to the calling object.
	*/
	int current_len = this->length(); 
	int str_len 	= s.length(); 
	int new_len 	= current_len + str_len; 
	charPtr new_buffer = new char[new_len + 1]; 
	for(int i = 0; i < current_len; i++) { 
		new_buffer[i] = buffer[i];
	}
	for(int i = 0; i < str_len; i++) { 
		new_buffer[current_len + i] = s[i];
	}
	new_buffer[new_len] = '\0';

	if(buffer != nullptr)
		delete [] buffer; 
	buffer = new char[new_len + 1]; 
	for(int i = 0; i <= new_len; i++) { 
		buffer[i] = new_buffer[i];
	}
	delete [] new_buffer; 
	return; 
}

void CMPT125_String::append(const char &c)
{
	/*
	This function appends a copy of the character argument to the calling object
	*/
	int current_len = this->length(); 

	charPtr new_buffer = new char[current_len + 2]; 

	for(int i = 0; i < current_len; i++) { 
		new_buffer[i] = buffer[i];
	}
	new_buffer[current_len] = c; 
	new_buffer[current_len + 1] = '\0';


	if(buffer != nullptr)
		delete [] buffer; 

	buffer = new char[current_len + 2]; 
	for(int i = 0; i < current_len + 1; i++) { 
		buffer[i] = new_buffer[i];
	}
	buffer[current_len + 1] = '\0';
	delete [] new_buffer; 
	return; 
}
void CMPT125_String::append(const charPtr cStr) //*cStr is a cstring
{
	/*
	This function appends a copy of the cstring argument to the calling object
	*/
	int current_len = this->length();
	int str_len 	= this->cstrlen(cStr); 
	int new_len 	= current_len + str_len; 
	charPtr new_buffer = new char[new_len + 1]; 
	for(int i = 0; i < current_len; i++) { 
		new_buffer[i] = buffer[i];
	}
	for(int i = 0; i < str_len; i++) { 
		new_buffer[current_len + i] = cStr[i];
	}
	new_buffer[new_len] = '\0';
	if(buffer != nullptr)
		delete [] buffer; 
	buffer = new char[new_len + 1]; 
	for(int i = 0; i <= new_len; i++) { 
		buffer[i] = new_buffer[i];
	}
	delete [] new_buffer; 
	return; 
}

//Operator member functions
CMPT125_String CMPT125_String::operator + (const CMPT125_String &s) const
{
	/*
	This function returns a new CMPT125_String object made up all the characters of the
	calling object followed by the characters of the argument s
	*/

	int current_len = this->length(); 
	int str_len 	= s.length(); 
	int new_len 	= current_len + str_len; 
	charPtr new_buffer = new char[new_len + 1]; 
	for(int i = 0; i < current_len; i++) { 
		new_buffer[i] = buffer[i];
	}
	for(int i = 0; i < str_len; i++) { 
		new_buffer[current_len + i] = s[i];
	}
	new_buffer[new_len] = '\0';
	return CMPT125_String(new_buffer);
}

CMPT125_String CMPT125_String::operator + (const char &c) const
{
	/*
	This function returns a new CMPT125_String object made up all the characters of the
	calling object followed by the character argument c
	*/
	int current_len = this->length(); 
	int new_len  	= current_len + 1; 

	charPtr new_buffer = new char[new_len + 1]; 
	for(int i = 0; i < current_len; i++) { 
		new_buffer[i] = buffer[i];
	}
	new_buffer[current_len] = c; 
	new_buffer[current_len + 1] = '\0';

	return CMPT125_String(new_buffer);
}
CMPT125_String CMPT125_String::operator + (const charPtr cStr) const //*cStr is a cstring
{
	/*
	This function returns a new CMPT125_String object made up all the characters of the
	calling object followed by the characters of the cstring argument cStr
	*/
	int current_len = this->length(); 
	int str_len 	= cstrlen(cStr); 
	int new_len 	= current_len + str_len; 
	charPtr new_buffer = new char[new_len + 1]; 
	for(int i = 0; i < current_len; i++) { 
		new_buffer[i] = buffer[i];
	}
	for(int i = 0; i < str_len; i++) { 
		new_buffer[current_len + i] = cStr[i];
	}
	new_buffer[new_len] = '\0';
	return CMPT125_String(new_buffer); 
}

CMPT125_String& CMPT125_String::operator += (const CMPT125_String &s)
{
	/*
	This function appends a copy of the characters of s to the calling object and then
	returns the calling object
	*/
	int current_len = this->length(); 
	int str_len 	= s.length(); 
	int new_len 	= current_len + str_len; 
	charPtr new_buffer = new char[new_len + 1]; 
	for(int i = 0; i < current_len; i++) { 
		new_buffer[i] = buffer[i];
	}
	for(int i = 0; i < str_len; i++) { 
		new_buffer[current_len + i] = s[i];
	}
	new_buffer[new_len] = '\0';
	if(buffer != nullptr)
		delete [] buffer; 
	buffer = new char[new_len + 1]; 
	for(int i = 0; i <= new_len; i++) { 
		buffer[i] = new_buffer[i];
	}
	// delete [] new_buffer; 
	return *this; 
}
CMPT125_String& CMPT125_String::operator += (const char &c)
{
	/*
	This function appends a copy of the character c to the calling object and then
	returns the calling object
	*/
	int current_len = this->length(); 
	int new_len  	= current_len + 1; 

	charPtr new_buffer = new char[new_len + 1]; 
	for(int i = 0; i < current_len; i++) { 
		new_buffer[i] = buffer[i];
	}
	new_buffer[current_len] = c; 
	new_buffer[current_len + 1] = '\0';

	if(buffer != nullptr)
		delete [] buffer; 

	buffer = new char[new_len + 1]; 
	for(int i = 0; i <= new_len; i++) { 
		buffer[i] = new_buffer[i];
	}
	// delete [] new_buffer; 
	return *this; 
}
CMPT125_String& CMPT125_String::operator += (const charPtr cStr) //*cStr is a cstring
{
	/*
	This function appends a copy of the characters of the cstring cStr
	to the calling object and then returns the calling object
	*/
	int current_len = this->length(); 
	int str_len 	= cstrlen(cStr); 
	int new_len 	= current_len + str_len; 
	charPtr new_buffer = new char[new_len + 1]; 
	for(int i = 0; i < current_len; i++) { 
		new_buffer[i] = buffer[i];
	}
	for(int i = 0; i < str_len; i++) { 
		new_buffer[current_len + i] = cStr[i];
	}
	new_buffer[new_len] = '\0';
	if(buffer != nullptr)
		delete [] buffer; 
	buffer = new char[new_len + 1]; 
	for(int i = 0; i <= new_len; i++) { 
		buffer[i] = new_buffer[i];
	}
	// delete [] new_buffer; 
	return *this;
}
bool CMPT125_String::operator == (const CMPT125_String &s) const
{
	/*
	This function tests if the calling object is equal to the argument s
	NOTE:- Two CMPT125_String are equal if they have the same length and contain the same
	characters in the same order.

	This function is implemented by the instructor. MAKING ANY CHANGE TO IT IS NOT ALLOWED.
	*/
	int len = this->length();
	if (len != s.length())
		return false;
	else
	{
		for (int i = 0; i < len; i++)
		{
			if (buffer[i] != s[i])
				return false;
		}
		return true;
	}
}
bool CMPT125_String::operator == (const charPtr cStr) const //*cStr is a cstring
{
	/*
	This function tests if the calling object is equal to a CMPT125_String object constructed from the cstring cStr
	*/	
	int buffer_len = this->length(); 
	int str_len = cstrlen(cStr);

	if(buffer_len != str_len) 	
		return false; 

	for(int i = 0; i < buffer_len; i++) { 
		if(buffer[i] != cStr[i]) return false; 
	}
	return true;
}
bool CMPT125_String::operator != (const CMPT125_String &s) const
{
	/*
	This function tests if the calling object is not equal to the argument s
	*/
	int buffer_len = this->length(); 
	int str_len = s.length(); 

	if(buffer_len != str_len) 
		return true; 

	for(int i = 0; i < buffer_len; i++) { 
		if(buffer[i] != s[i]) return true; 
	}
	return false;
}
bool CMPT125_String::operator != (const charPtr cStr) const //*cStr is a cstring
{
	/*
	This function tests if the calling object is not equal to a CMPT125_String object constructed from the cstring cStr
	*/
	int buffer_len = this->length(); 
	int str_len = cstrlen(cStr);

	if(buffer_len != str_len) 
		return true; 

	for(int i = 0; i < buffer_len; i++) { 
		if(buffer[i] != cStr[i]) return true; 
	}
	return false;
}
bool CMPT125_String::operator < (const CMPT125_String &s) const
{
	/*
	This function tests if the calling object is less than the argument s
	NOTE:- Given two CMPT125_String objects s1 and s2, we compare them as follows:
		Step 1. Find the smallest valid index k such that s1[k] IS NOT EQUAL TO s2[k]
		Step 2. If such an index k is found, then
			2.1 This function returns true if s1[k] < s2[k] otherwise returns false
		Step 3. If such an index k is not found, then
			3.1 This function returns true if the length of s1 is less than the length of s2 otherwise returns false
	*/
	int buffer_len = this->length(); 
	int str_len = s.length(); 

	int smaller_len = (buffer_len <= str_len ? buffer_len : str_len); 

	for(int i = 0; i < smaller_len; i++) { 
		if(buffer[i] < s[i]) return true;
		if(buffer[i] > s[i]) return false; 
		continue; 
	}

	return buffer_len < str_len; 
}
bool CMPT125_String::operator < (const charPtr cStr) const //*cStr is a cstring
{
	/*
	This function tests if the calling object is less than a CMPT125_String object constructed from the cstring cStr
	*/
	int buffer_len = this->length(); 
	int str_len = cstrlen(cStr); 

	int smaller_len = (buffer_len <= str_len ? buffer_len : str_len); 

	for(int i = 0; i < smaller_len; i++) { 
		if(buffer[i] < cStr[i]) return true;
		if(buffer[i] > cStr[i]) return false; 
		continue; 
	}

	return buffer_len < str_len; 
}
bool CMPT125_String::operator > (const CMPT125_String &s) const
{
	/*
	This function tests if the calling object is greater than the argument s
	*/
	int buffer_len = this->length(); 
	int str_len = s.length(); 

	int smaller_len = (buffer_len <= str_len ? buffer_len : str_len); 

	for(int i = 0; i < smaller_len; i++) { 
		if(buffer[i] > s[i]) return true;
		if(buffer[i] < s[i]) return false; 
		continue; 
	}

	return buffer_len > str_len; 
}
bool CMPT125_String::operator > (const charPtr cStr) const //*cStr is a cstring
{
	/*
	This function tests if the calling object is greater than a CMPT125_String object constructed from the cstring cStr
	*/
	int buffer_len = this->length(); 
	int str_len = cstrlen(cStr); 

	int smaller_len = (buffer_len <= str_len ? buffer_len : str_len); 

	for(int i = 0; i < smaller_len; i++) { 
		if(buffer[i] > cStr[i]) return true;
		if(buffer[i] < cStr[i]) return false; 
		continue; 
	}

	return buffer_len > str_len; 
}
bool CMPT125_String::operator <= (const CMPT125_String &s) const
{
	/*
	This function tests if the calling object is less than or equal to the argument s
	*/
	int buffer_len = this->length(); 
	int str_len = s.length(); 

	int smaller_len = (buffer_len <= str_len ? buffer_len : str_len); 

	for(int i = 0; i < smaller_len; i++) { 
		if(buffer[i] < s[i]) return true;
		if(buffer[i] > s[i]) return false; 
		continue; 
	}

	return buffer_len <= str_len; 
	
}
bool CMPT125_String::operator <= (const charPtr cStr) const //*cStr is a cstring
{
	/*
	This function tests if the calling object is less than or equal to a CMPT125_String object constructed from the cstring cStr
	*/
	int buffer_len = this->length(); 
	int str_len = cstrlen(cStr); 

	int smaller_len = (buffer_len <= str_len ? buffer_len : str_len); 

	for(int i = 0; i < smaller_len; i++) { 
		if(buffer[i] < cStr[i]) return true;
		if(buffer[i] > cStr[i]) return false; 
		continue; 
	}

	return buffer_len <= str_len; 
}
bool CMPT125_String::operator >= (const CMPT125_String &s) const
{
	/*
	This function tests if the calling object is greater than or equal to the argument s
	*/
	int buffer_len = this->length(); 
	int str_len = s.length(); 

	int smaller_len = (buffer_len <= str_len ? buffer_len : str_len); 

	for(int i = 0; i < smaller_len; i++) { 
		if(buffer[i] > s[i]) return true;
		if(buffer[i] < s[i]) return false; 
		continue; 
	}

	return buffer_len >= str_len; 
}
bool CMPT125_String::operator >= (const charPtr cStr) const //*cStr is a cstring
{
	/*
	This function tests if the calling object is greater than or equal to a CMPT125_String object constructed from the cstring cStr
	*/
	int buffer_len = this->length(); 
	int str_len = cstrlen(cStr); 

	int smaller_len = (buffer_len <= str_len ? buffer_len : str_len); 

	for(int i = 0; i < smaller_len; i++) { 
		if(buffer[i] > cStr[i]) return true;
		if(buffer[i] < cStr[i]) return false; 
		continue; 
	}

	return buffer_len >= str_len; 

}

//Friend Functions (for operators)
CMPT125_String operator + (const char &c, const CMPT125_String &s)
{
	/*
	This function returns a new CMPT125_String object whose characters are that of character
	argument c followed by those of s
	*/
	int current_len = s.length(); 

	charPtr new_buffer = new char[current_len + 2]; 
	
	new_buffer[0] = c; 

	for(int i = 1; i <= current_len; i++) { 
		new_buffer[i] = s.buffer[i-1];
	}
	new_buffer[current_len + 1] = '\0';
	

	return CMPT125_String(new_buffer);

}
CMPT125_String operator + (const charPtr cStr, const CMPT125_String &s) //*cStr is a cstring
{
	/*
	This function returns a new CMPT125_String object containing the printable characters 
	of the cstring argument cStr followed by those of s
	*/
	int current_len = s.length();  
	int str_len 	= s.cstrlen(cStr);
	int new_len 	= current_len + str_len; 
	charPtr new_buffer = new char[new_len + 1];

	for(int i = 0; i < str_len; i++) { 
		new_buffer[i] = cStr[i];
	}
	for(int i = 0; i < current_len; i++) { 
		new_buffer[str_len + i] = s[i];
	}
	new_buffer[new_len] = '\0';
	return CMPT125_String(new_buffer);

}
bool operator == (const charPtr cStr, const CMPT125_String &s) //*cStr a cstring
{
	/*
	This function tests if a CMPT125_String object constructed from the cstring cStr is equal to s
	*/
	int str_len = s.cstrlen(cStr); 
	int buffer_len = s.length(); 

	if(str_len != buffer_len) return false; 

	for(int i = 0; i < str_len; i++) { 
		if(cStr[i] != s[i]) return false; 
	}
	return true; 
}
bool operator != (const charPtr cStr, const CMPT125_String &s) //*cStr is a cstring
{
	/*
	This function tests if a CMPT125_String object constructed from the cstring cStr is not equal to s
	*/
	int str_len = s.cstrlen(cStr); 
	int buffer_len = s.length();

	if(str_len != buffer_len) return true; 

	for(int i = 0; i < str_len; i++) { 
		if(cStr[i] != s[i]) return true; 
	}
	return false; 

}
bool operator < (const charPtr cStr, const CMPT125_String &s) //*cStr is a cstring
{
	int buffer_len = s.length(); 
	int str_len = s.cstrlen(cStr); 

	int smaller_len = (buffer_len <= str_len ? buffer_len : str_len); 

	for(int i = 0; i < smaller_len; i++) { 
		if(s[i] > cStr[i]) return true;
		if(s[i] < cStr[i]) return false; 
		continue; 
	}

	return buffer_len > str_len; 

}
bool operator > (const charPtr cStr, const CMPT125_String &s) //*cStr is a cstring
{
	int buffer_len = s.length(); 
	int str_len = s.cstrlen(cStr); 

	int smaller_len = (buffer_len <= str_len ? buffer_len : str_len); 

	for(int i = 0; i < smaller_len; i++) { 
		if(s[i] < cStr[i]) return true;
		if(s[i] > cStr[i]) return false; 
		continue; 
	}

	return buffer_len < str_len; 
}
bool operator <= (const charPtr cStr, const CMPT125_String &s) //*cStr is a cstring
{
	/*
	This function tests if a CMPT125_String object constructed from the cstring cStr is less than or equal to s
	*/
	int buffer_len = s.length(); 
	int str_len = s.cstrlen(cStr); 

	int smaller_len = (buffer_len <= str_len ? buffer_len : str_len); 

	for(int i = 0; i < smaller_len; i++) { 
		if(s[i] > cStr[i]) return true;
		if(s[i] < cStr[i]) return false; 
		continue; 
	}

	return buffer_len >= str_len; 
}
bool operator >= (const charPtr cStr, const CMPT125_String &s) //*cStr is a cstring
{
	/*
	This function tests if a CMPT125_String object constructed from the cstring cStr is greater than or equal to s
	*/
	int buffer_len = s.length(); 
	int str_len = s.cstrlen(cStr); 

	int smaller_len = (buffer_len <= str_len ? buffer_len : str_len); 

	for(int i = 0; i < smaller_len; i++) { 
		if(s[i] < cStr[i]) return true;
		if(s[i] > cStr[i]) return false; 
		continue; 
	}

	return buffer_len <= str_len; 
}
ostream& operator << (ostream &cout, const CMPT125_String &s)
{
	/*
	This function prints the printable characters of the buffer of the CMPT125_String argument s.

	This function is implemented by the instructor. MAKING ANY CHANGE TO IT IS NOT ALLOWED.
	*/
	for (int i = 0; i < s.length(); i++)
		cout << s.buffer[i];
	return cout;
}
istream& operator >> (istream &cin, CMPT125_String &s)
{
	/*
	This function is designed to read ANY number of characters from the user.
	Reading will stop when the user presses the Enter Key.
	In order to achieve this, we will read one character at a time
	until end of line character ('\n') is read.

	This function is implemented by the instructor. MAKING ANY CHANGE TO IT IS NOT ALLOWED.
	*/
	s.~CMPT125_String();
	char ch;
	while (true)
	{
		cin.get(ch);
		if (ch == '\n')
			break;
		else
			s.append(ch);
	}
	return cin;
}

//Non-member and non-friend functions
// In addition, you are required to define the following non-member and non-friend functions

// 1. findCharIndex
// /*
// This function takes a CMPT125_String and a character arguments and returns the smallest valid
// index of the CMPT125_String argument such that the character of the CMPT125_String argument at 
// that index is equal to the character argument. If no such an index is found, then this function 
// must return -1.
// */

int findCharIndex (const CMPT125_String &s, const char &c) { 
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == c) return i;
	}
	return -1; 
}

// 2. reverseFindCharIndex
// /*
// This function takes a CMPT125_String and a character arguments and returns the largest valid
// index of the CMPT125_String argument such that the character of the CMPT125_String argument at 
// that index is equal to the character argument. If no such an index is found, then this function 
// must return -1.
// */

int reverseFindCharIndex(const CMPT125_String &s, const char &c) {
	for(int i = s.length() - 1; i >= 0; i--) { 
		if(s[i] == c) return i; 
	}
	return -1; 
}

// 3. countChar
// /*
// This function takes a CMPT125_String and a character arguments and returns the number of times the
// character argument is found in the CMPT125_String argument.
// */

int countChar(const CMPT125_String &s, const int &c) { 
	int ans = 0; 
	for(int i = 0; i < s.length(); i++) { 
		ans += (s[i] == c); 
	}
	return ans;
}

// 4. getSubString
// /*
// This function takes a CMPT125_String, a start index, and a length arguments and returns a
// CMPT125_String object with as many as length characters constructed from the characters of the
// CMPT125_String argument starting from the given start index. If there are no enough characters
// to copy as many as length characters from the CMPT125_String argument, then ONLY the available
// characters up to the end of the CMPT125_String argument are copied and a CMPT125_String with a
// shorter length is returned.

// The returned object is known as a substring of the CMPT125_String argument.
// */

CMPT125_String getSubString(const CMPT125_String &s, int startIndex, int subLen) {
	CMPT125_String newString; 
	for(int i = 0; i < subLen; i++) { 
		if(startIndex + i >= s.length()) break;
		newString += s[startIndex + i];
	}
	return newString; 
}

// 5. isSubString
// /*
// This function takes two CMPT125_String objects s1 and s2 as arguments and returns true if there
// exists a substring of s2 that is equal to s1; otherwise it returns false.
// */

bool isSubString (const CMPT125_String &s1, const CMPT125_String &s2) {
	if(s1.length() > s2.length()) return false; 
	if(s1.length() == s2.length() && s1 != s2) return false; 

	for(int i = 0; i < s2.length(); i++) {
		auto subStr = getSubString(s2, i, s1.length());
		if(subStr == s1) return true; 
	}
	return false; 
}	

// 6. getReversedString
// /*
// This function takes a CMPT125_String argument and returns a CMPT125_String object constructed from
// the characters of the CMPT125_String argument in reverse order.
// */

CMPT125_String getReversedString (const CMPT125_String &s) { 
	CMPT125_String reversedString; 
	for(int i = s.length() - 1; i >= 0; i--) { 
		reversedString.append(s[i]);
	}
	// cout << s << "\n";
	return reversedString;

}

// 7. removeChar
// /*
// This function takes a CMPT125_String and a character arguments and removes each character of the
// CMPT125_String argument that is equal to the character argument from the CMPT125_String argument.
// */

void removeChar (CMPT125_String &s, const char &c) { 
	CMPT125_String newString;
	for(int i = 0; i < s.length(); i++) { 
		if(s[i] != c) newString.append(s[i]);
	}
	s = newString; 
}

// 8. replaceChar
// /*
// This function takes a CMPT125_String and two characters named ch1 and ch2 (in that order) as
// arguments and replaces every character in the CMPT125_String argument that is equal to ch1 by
// the character ch2.
// */

void replaceChar (CMPT125_String &s, const char &ch1, const char &ch2) { 
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == ch1) s[i] = ch2; 
	}
}

//Test Program

int main()
{
	//Test default constructor and length member functions
	CMPT125_String s1;
	cout << "s1 is \"" << s1 << "\" and its length is " << s1.length() << endl;

	//Test non-default constructor and length member functions
	CMPT125_String s2 = 'Y';
	cout << "s2 is \"" << s2 << "\" and its length is " << s2.length() << endl;

	//Test non-default constructor and length member functions
	CMPT125_String s3 = "CMPT 125";
	cout << "s3 is \"" << s3 << "\" and its length is " << s3.length() << endl;

	//Test copy constructor and length member functions
	CMPT125_String s4 = s3;
	cout << "s4 is \"" << s4 << "\" and its length is " << s4.length() << endl;
	
	//Test destructor and length member functions
	s4.~CMPT125_String();
	cout << "s4 is \"" << s4 << "\" and its length is " << s4.length() << endl;

	//Test assignment operator and length member functions
	s4 = s2;
	cout << "s4 is \"" << s4 << "\" and its length is " << s4.length() << endl;

	//Test assignment operator and length member functions
	s4 = 'A';
	cout << "s4 is \"" << s4 << "\" and its length is " << s4.length() << endl;

	//Test assignment operator and length member functions
	s4 = "This is cool";
	cout << "s4 is \"" << s4 << "\" and its length is " << s4.length() << endl;

	//Test indexing operator member function
	cout << "s4[2] is " << s4[2] << endl;
	s4[2] = 'a';
	cout << "s4[2] is " << s4[2] << endl;
	s4[3] = 't';
	cout << "s4 is \"" << s4 << "\" and its length is " << s4.length() << endl;

	//Test append and length member functions
	s1.append(s4);
	cout << "s1 is \"" << s1 << "\" and its length is " << s1.length() << endl;

	//Test append and length member functions
	s3.append(' ');
	cout << "s3 is \"" << s3 << "\" and its length is " << s3.length() << endl;

	//Test append and length member functions
	s3.append("201901");
	cout << "s3 is \"" << s3 << "\" and its length is " << s3.length() << endl;

	// Test findCharIndex non-member function
	char ch = '1';
	int k = findCharIndex(s3, ch);
	cout << "The first index of '" << ch << "' in \"" << s3 << "\" is " << k << endl;
	ch = 'm';
	k = findCharIndex(s3, 'm');
	cout << "The first index of '" << ch << "' in \"" << s3 << "\" is " << k << endl;

	//Test reverseFindCharIndex non-member function
	ch = '1';
	k = reverseFindCharIndex(s3, ch);
	cout << "The last index of '" << ch << "' in \"" << s3 << "\" is " << k << endl;
	ch = 'm';
	k = reverseFindCharIndex(s3, 'm');
	cout << "The last index of '" << ch << "' in \"" << s3 << "\" is " << k << endl;
	
	//Test countChar non-member function
	ch = '1';
	k = countChar(s1, ch);
	cout <<  "'" << ch << "' appears " << k << " times in \"" << s1 << "\"" << endl;

	//Test getSubString non-member function
	s1 = getSubString(s3, 10, 3);
	cout << "s1 is \"" << s1 << "\" and its length is " << s1.length() << endl;
	s1 = getSubString(s3, 10, 5);
	cout << "s1 is \"" << s1 << "\" and its length is " << s1.length() << endl;
	s1 = getSubString(s3, 10, 8);
	cout << "s1 is \"" << s1 << "\" and its length is " << s1.length() << endl;
	
	//Test isSubString non-member function
	if (isSubString(s1, s3) == true)
		cout << "\"" << s1 << "\" is a substring of \"" << s3 << "\"" << endl;
	else
		cout << "\"" << s1 << "\" is not a substring of \"" << s3 << "\"" << endl;
	s2 = "01902029010190";
	if (isSubString(s1, s2) == true)
		cout << "\"" << s1 << "\" is a substring of \"" << s2 << "\"" << endl;
	else
		cout << "\"" << s1 << "\" is not a substring of \"" << s2 << "\"" << endl;
	char x[] = "01902019010190";
	if (isSubString(s1, x) == true)
		cout << "\"" << s1 << "\" is a substring of \"" << x << "\"" << endl;
	else
		cout << "\"" << s1 << "\" is not a substring of \"" << x << "\"" << endl;
	
	//Test getReversedString non-member function
	cout << "s1 is \"" << s1 << "\" and its length is " << s1.length() << endl;
	CMPT125_String rev = getReversedString(s1);
	cout << "The reverse of \"" << s1 << "\" is \"" << rev << "\"" << endl;
	
	//Test removeChar non-member function
	cout << "After removing all the '" << ch << "' characters from \"" << s1 << "\", we get ";
	removeChar(s1, ch);
	cout << "\"" << s1 << "\"" << endl;
	s3 = "11111111111";
	cout << "After removing all the '" << ch << "' characters from \"" << s3 << "\", we get ";
	removeChar(s3, ch);
	cout << "\"" << s3 << "\"" << endl;
	
	//Test replaceChar non-member function
	cout << "After replacing 1 by 5 from \"" << s2 << "\", we get ";
	replaceChar(s2, '1', '5');
	cout << s2 << endl;

	//Test + operator member function
	cout << "s1 is \"" << s1 << "\", s3 is \"" << s3 << "\" and s1 + s3 is \"" << s1 + s3 << "\"" << endl;
	cout << "s1 is \"" << s1 << " and s1 + \"yonas\" is \"" << s1 + "yonas" << endl;
	cout << "s1 is \"" << s1 << " and s1 + 'Y' is \"" << s1 + 'Y' << endl;

	//Test += operatror member function
	s2 = "Test";
	cout << "s1 is \"" << s1 <<"\", s2 is \"" << s2 << "\", and s3 is \"" << s3 << "\"" << endl;
	s3 = s1 += s2;
	cout << "After s3 = s1 += s2, we get s1 is " << s1 <<", s2 is " << s2 << ", and s3 is " << s3 << endl;

	cout << "s2 is \"" << s2 << "\". ";
	s2 += "FIC";
	cout << "After s2 += \"FIC\", we get \"" << s2 << "\"" << endl; 
	cout << "s2 is \"" << s2 << "\". ";
	s2 += '!';
	cout << "After s2 += '!', we get \"" << s2 << "\"" << endl;

	//Test relational operators member functions
	s1 = "Test101";
	s2 = "Test2";
	cout << "s1 is \"" << s1 << "\", s2 is \"" << s2 << "\" and s1 == s2 is " << (s1 == s2) << endl;
	cout << "s1 is \"" << s1 << "\", s2 is \"" << s2 << "\" and s1 != s2 is " << (s1 != s2) << endl;
	cout << "s1 is \"" << s1 << "\", s2 is \"" << s2 << "\" and s1 > s2 is " << (s1 > s2) << endl;
	cout << "s1 is \"" << s1 << "\", s2 is \"" << s2 << "\" and s1 < s2 is " << (s1 < s2) << endl;
	cout << "s1 is \"" << s1 << "\", s2 is \"" << s2 << "\" and s1 >= s2 is " << (s1 >= s2) << endl;
	cout << "s1 is \"" << s1 << "\", s2 is \"" << s2 << "\" and s1 <= s2 is " << (s1 <= s2) << endl;

	//Test + friend functions
	cout << "\"Yonas\" + \"" << s1 << "\" is \"" << "Yonas" + s1 << "\"" << endl;
	cout << "'y' + \"" << s1 << "\" is \"" << 'y' + s1 << "\"" << endl;

	//Test friend relational operators
	cout << "s1 is \"" << s1 << "\" and \"Test2\" == s1 is " << ("Test2" == s1) << endl;
	cout << "s1 is \"" << s1 << "\" and \"Test2\" != s1 is " << ("Test2" != s1) << endl;
	cout << "s1 is \"" << s1 << "\" and \"Test2\" < s1 is " << ("Test2" < s1) << endl;
	cout << "s1 is \"" << s1 << "\" and \"Test2\" > s1 is " << ("Test2" > s1) << endl;
	cout << "s1 is \"" << s1 << "\" and \"Test2\" <= s1 is " << ("Test2" <= s1) << endl;
	cout << "s1 is \"" << s1 << "\" and \"Test2\" >= s1 is " << ("Test2" >= s1) << endl;

	//Test input streaming operator
	cout << "Enter a string of any length you want (including spaces, punctuation marks, etc if you wish): ";
	cin >> s1;
	cout << "You entered \"" << s1 << "\"" << endl;

	system("pause");
	return 0;
}