#include <iostream>
#include <cstring>
using namespace std;

class String {
	private:
		size_t length;
		char *str;

	public:
		String();
		String(const char *s);//�вι���
		String(const String &s);//��������
		~String();
		size_t getLength() const;//��ȡ�ַ�������
		char operator[](size_t index) const;//����ָ���±���ַ�
		String &operator=(const String &s);//�ַ�����ֵ
		bool operator==(const String &s) const;//[�ж��ַ����Ƿ����
		bool operator!=(const String &s) const;
		String copy() const;//�ַ�����������
		String operator+(const String &s) const;//�ַ���ƴ��
		friend ostream &operator<<(ostream &out, const String &s);//����ַ���

};

//����string
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

//����
String::~String() {
	delete[] str;
}

//��ȡ����
size_t String::getLength() const {
	return length;
}

//string������
char String::operator[](size_t index) const {
	return str[index];
}

//���ĸ�ֵ
//����������Ϊ��֧��������ֵ
String &String::operator=(const String &s) {
	if (this != &s) {
		delete[] str;
		length = s.length;
		str = new char[length + 1];
		strcpy(str, s.str);
	}
	return *this;
}

//���ıȽ�
bool String::operator==(const String &s) const {
	return strcmp(str, s.str) == 0;
}

bool String::operator!=(const String &s) const {
	return strcmp(str, s.str) != 0;
}

//���Ŀ���
String String::copy() const {
	String s = *this;
	return s;
}

//����ƴ��
String String::operator+(const String &s) const {
	String result;
	result.length = length + s.length;
	result.str = new char[result.length + 1];
	strcpy(result.str, str);
	strcat(result.str, s.str);
	return result;
}

//�������
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