#pragma once

#include<vector>

using namespace std;

enum CONTROL { UPDOWN, UP, CONST };
enum VNEXT { VN, VNCAP, VN�OR };

class rkm_method {
private:
	vector<double (*)(double, double, double)> f;

	double x0, u0, ud0;
	double h0;
	int Nmax;
	double b, Egr, E, Emin;

	CONTROL control;
	VNEXT vnext;

public:
	rkm_method(double (*_f1)(double, double, double), double (*_f2)(double, double, double), double _x0 = 0.0,
		double _u0 = 0.0, double _ud0 = 0.0, double _h0 = 0.001, int _Nmax = 10000, double _b = 1.0,
		double _Egr = 0.000001, double _E = 0.00000001, double _Emin = 0.0000000001, CONTROL _control = UPDOWN, VNEXT _vnext = VN);

	void setFunc(double (*_f1)(double, double, double), double (*_f2)(double, double, double));
	void setSC(double _x0, double _u0, double _ud0);
	void setH0(double _h0);
	void setControl(int _Nmax, double _b, double _Egr, double _E, double _Emin, CONTROL _control, VNEXT _vnext);

	void solve(vector<double>& X, vector<double>& H, vector<vector<double>>& V, vector<vector<double>>& V_cap,
		vector<double>& OLP, vector<vector<double>>& V_res, vector<int>& step_dec, vector<int>& step_inc);
};