#include <iostream>
#include <cstring>
using namespace std;

class String {
	private:
		size_t length;
		char *str;

	public:
		String();
		String(const char *s);//有参构造
		String(const String &s);//拷贝构造
		~String();
		size_t getLength() const;//获取字符串长度
		char operator[](size_t index) const;//访问指定下标的字符
		String &operator=(const String &s);//字符串赋值
		bool operator==(const String &s) const;//[判断字符串是否相等
		bool operator!=(const String &s) const;
		String copy() const;//字符串拷贝函数
		String operator+(const String &s) const;//字符串拼接
		friend ostream &operator<<(ostream &out, const String &s);//输出字符串

};

//构造string
String::String() {
	length = 0;
	str = new char[1];
	str[0] = '\0';
}

String::String(const char *s) {
	length = strlen(s);
	str = new char[length + 1];
	strcpy(str, s);
}

String::String(const String &s) {
	length = s.length;
	str = new char[length + 1];
	strcpy(str, s.str);
}

//销毁
String::~String() {
	delete[] str;
}

//获取长度
size_t String::getLength() const {
	return length;
}

//string的索引
char String::operator[](size_t index) const {
	return str[index];
}

//串的赋值
//返回引用是为了支持连续赋值
String &String::operator=(const String &s) {
	if (this != &s) {
		delete[] str;
		length = s.length;
		str = new char[length + 1];
		strcpy(str, s.str);
	}
	return *this;
}

//串的比较
bool String::operator==(const String &s) const {
	return strcmp(str, s.str) == 0;
}

bool String::operator!=(const String &s) const {
	return strcmp(str, s.str) != 0;
}

//串的拷贝
String String::copy() const {
	String s = *this;
	return s;
}

//串的拼接
String String::operator+(const String &s) const {
	String result;
	result.length = length + s.length;
	result.str = new char[result.length + 1];
	strcpy(result.str, str);
	strcat(result.str, s.str);
	return result;
}

//串的输出
ostream &operator<<(ostream &out, const String &s) {
	out << s.str;
	return out;
}

int main() {
	String s("114514_STA");
	cout << s << endl;
	cout << s + "_run" << endl;
	cout << s[5] << endl;
	cout << (s == "114514_STA") << '\n';
	cout << (s != "114514_STA") << '\n';
	s = s + "_running";
	String a, b, c;
	a = b = c = s;
	cout << s << '\n';
	cout << a << b << c << s << '\n';
	String x = s.copy();
	cout << x << '\n';

	return 0;
}