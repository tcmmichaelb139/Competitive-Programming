#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	double x1, x2, x3, y1, y2, y3;
	while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
		double a, b, c;
		a = x1*(y2-y3)-y1*(x2-x3)+x2*y3-x3*y2;
		b = (x1*x1+y1*y1)*(y3-y2)+(x2*x2+y2*y2)*(y1-y3)+(x3*x3+y3*y3)*(y2-y1);
		c = (x1*x1+y1*y1)*(x2-x3)+(x2*x2+y2*y2)*(x3-x1)+(x3*x3+y3*y3)*(x1-x2);
		double x = -b/(2*a);
		double y = -c/(2*a);
		double ans = sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1))*2;
		cout << fixed << setprecision(2) << ans*3.141592653589793 << '\n';
	}
}
