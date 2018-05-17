/*======================================
Stochastic Music Created from Markov Transition Probability Matrix
Copyright (c) by LHY
======================================*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <time.h>
#include <iterator>
#include <map>
#include "variable.h"
using namespace std;

ifstream is;
ofstream os;
int k, n, c;

struct note
{
	int high;
	int time;
	note() {}
	note(int _h, int _t) :high(_h), time(_t) {}
	friend bool operator <(const note& a, const note &b)
	{
		return a.high < b.high || (a.high == b.high&&a.time < b.time);
	}
	friend bool operator ==(const note& a, const note& b)
	{
		return a.high == b.high&&a.time == b.time;
	}
	friend bool operator !=(const note& a, const note& b)
	{
		return !(a == b);
	}
	friend ifstream& operator >>(ifstream& _is, note& n)
	{
		_is >> n.high;
		_is.ignore(100, ',');
		_is >> n.time;
		return _is;
	}
	friend ofstream& operator <<(ofstream& _os, const note& n)
	{
		_os << n.high << "," << n.time << endl;
		return _os;
	}
	friend ostream& operator <<(ostream& _os, const note& n)
	{
		_os << n.high << "," << n.time << endl;
		return _os;
	}
};

struct seq
{
	int size;
	note p[10];
	seq(int _size) :size(_size) {}
	template <class T>//�������г�ʼλ�õĵ�����
	seq(int _size, T start) : size(_size)
	{
		for (int i = 0; i < size; i++)
			p[i] = *(start + i);
	}
	friend ifstream& operator >>(ifstream& _is, seq& s)
	{
		for (int i = 0; i < s.size; i++)
			_is >> s.p[i];
		return _is;
	}
	friend bool operator <(const seq& a, const seq& b)
	{
		for (int i = 0; i < a.size; i++)
		{
			if (a.p[i] < b.p[i])
				return 1;
			else if (b.p[i] < a.p[i])
				return 0;
		}
		return 0;
	}
	friend bool operator ==(const seq& a, const seq& b)
	{
		for (int i = 0; i < a.size; i++)
		{
			if (a.p[i] != b.p[i])
				return 0;
		}
		return 1;
	}
};

typedef vector<double> prob;
typedef vector<note> mus_seq;

mus_seq create(int _k, //����k=size
	int _n, //��������ת�Ƹ��ʾ�������
	int _c, //ת�Ƹ��ʾ�������
	int len)//����������г���
{
	mus_seq next;//ת�Ƹ��ʾ���ÿ�е�����
	map<seq, prob> matrix;//ת�Ƹ��ʷֲ�����
	int i, j;
	note no;
	for (i = 0; i < _n; i++)
	{
		is >> no;//�����ʽ���ļ���ʽΪ׼�����޸�>>���غ���
		next.push_back(no);
	}
	for (i = 0; i < _c; i++)
	{
		seq name(_k);
		is >> name;
		prob pro;
		double sum = 0;
		double p;
		for (j = 0; j < _n; j++)
		{
			is >> p;
			sum += p;//������ĸ���ת��Ϊ�ֲ�
			pro.push_back(sum);
		}
		matrix.insert(make_pair(name, pro));
	}
	mus_seq music;
	seq start(_k);//�����ʼk����
	is >> start;
	for (i = 0; i < _k; i++)
		music.push_back(start.p[i]);//����ʼk����������������
	int first = 0;
	srand(time(0));//�������������
	for (i = _k; i < len; i++)
	{
		mus_seq::iterator ite = music.begin() + first;
		seq pre(_k, ite);
		double ran = (double)rand() / RAND_MAX;

		cout << ran << endl;

		prob& p = matrix[pre];
		prob::iterator iter = lower_bound(p.begin(), p.end(), ran);
		music.push_back(next[iter - p.begin()]);
		first++;
	}

	for (int i = 0; i < len; i++)
		os << music[i];
	return music;
}

void short_create();//�ö̵�Ƭ�������������
void long_create();//�ó���Ƭ�������������
void(*p)() = long_create;

int main()
{
	p();
	return 0;
}

void short_create()//�ö̵�Ƭ�������������
{
	//1�ײ���ʱֵ
	{
		pre_1_order_no_time();
		is.open("1-order-no-time.txt");
		os.open("1-order-no-time.csv");
		create(k, n, c, 1000);
		is.close();
		os.close();
	}
	//1�״�ʱֵ
	{
		pre_1_order_time();
		is.open("1-order-time.txt");
		os.open("1-order-time.csv");
		create(k, n, c, 1000);
		is.close();
		os.close();
	}
	//2�ײ���ʱֵ
	{
		pre_2_order_no_time();
		is.open("2-order-no-time.txt");
		os.open("2-order-no-time.csv");
		create(k, n, c, 1000);
		is.close();
		os.close();
	}
}

void long_create()
{
	//1�ײ���ʱֵ
	{
		long_pre_1_order_no_time();
		is.open("long_1-order-no-time.txt");
		os.open("long_1-order-no-time.csv");
		create(k, n, c, 1000);
		is.close();
		os.close();
	}
	//1�״�ʱֵ
	{
		long_pre_1_order_time();
		is.open("long_1-order-time.txt");
		os.open("long_1-order-time.csv");
		create(k, n, c, 1000);
		is.close();
		os.close();
	}
	//2�ײ���ʱֵ
	{
		long_pre_2_order_no_time();
		is.open("long_2-order-no-time.txt");
		os.open("long_2-order-no-time.csv");
		create(k, n, c, 1000);
		is.close();
		os.close();
	}
}