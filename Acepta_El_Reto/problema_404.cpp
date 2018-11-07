#include <iostream>
#include <string>

using namespace std;

int cont;

/*

    // Descomentar en AER
    
inline void out(int n)
{
	int N = n, rev, count = 0;
	rev = N;
	if (N == 0) {
		putchar_unlocked('0');
		putchar_unlocked('\n');
		return;
	}
	while ((rev % 10) == 0) { count++; rev /= 10; }
	rev = 0;
	while (N != 0) { rev = (rev << 3) + (rev << 1) + N % 10; N /= 10; }
	while (rev != 0) { putchar_unlocked(rev % 10 + '0'); rev /= 10; }
	while (count--) putchar_unlocked('0');
	putchar_unlocked('\n');
}
*/

inline void out(int n)
{
	int N = n, rev, count = 0;
	rev = N;
	if (N == 0) {
		putchar('0');
		putchar('\n');
		return;
	}
	while ((rev % 10) == 0) { count++; rev /= 10; }
	rev = 0;
	while (N != 0) { rev = (rev << 3) + (rev << 1) + N % 10; N /= 10; }
	while (rev != 0) { putchar(rev % 10 + '0'); rev /= 10; }
	while (count--) putchar('0');
	putchar('\n');
}
void num(string str, int i) {

	if (i == str.length())
		cont++;

	if ((i < str.size()))
		num(str, i + 1);

	if ((i + 1 < str.size()) && (str[i] == 'I' && str[i + 1] == 'I') || (str[i] == 'I' && str[i + 1] == 'V') || (str[i] == 'I' && str[i + 1] == 'X') || (str[i] == 'V' && str[i + 1] == 'I'))
		num(str, i + 2);

	if ((i + 2 < str.size()) && (str[i] == 'V' && str[i + 1] == 'I' && str[i + 2] == 'I') || (str[i] == 'I' && str[i + 1] == 'I' && str[i + 2] == 'I'))
		num(str, i + 3);

	if ((i + 3 < str.size()) && (str[i] == 'V' && str[i + 1] == 'I' && str[i + 2] == 'I' && str[i + 3] == 'I'))
		num(str, i + 4);

}

int main() {

	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;

	while (cin >> str) {

		cont = 0;
		num(str, 0);
		out(cont);

	}

	return 0;
}