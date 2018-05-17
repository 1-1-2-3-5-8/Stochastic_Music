#include <iostream>
#include <fstream>
#include <vector>
#include "variable.h"
using namespace std;

ifstream is_note;
ifstream is_prob;
ofstream _os;
extern int k, n, c;

void pre_1_order_no_time()
{
	k = 1;//1��
	is_note.open("1-order-no-time_input.b.txt");//����ÿ�ж�Ӧ����
	_os.open("1-order-no-time.txt");
	int note;
	int cnt = 0;
	while (is_note >> note)
	{
		_os << note << ",4 ";
		cnt++;
	}
	n = cnt;
	_os << endl;
	is_note.close();
	is_note.open("1-order-no-time_input.a.txt");//����ÿ�ж�Ӧ����
	is_prob.open("1-order-no-time_input.c.txt");//����
	double prob;
	cnt = 0;
	while (is_note >> note)
	{
		_os << note << ",4 ";
		cnt++;
		for (int i = 0; i < n; i++)
		{
			is_prob >> prob;
			_os << prob << " ";
		}
		_os << endl;
	}
	c = cnt;

	_os << "69,4" << endl;//��ʼ����

	is_note.close();
	is_prob.close();
	_os.close();
}

void pre_1_order_time()
{
	vector<pair<int, int>> line;//first��note��second��time
	k = 1;//1��
	is_note.open("1-order-time_input.b.txt");//����ÿ�ж�Ӧ����
	_os.open("1-order-time.txt");
	int note, time;
	int cnt = 0;

	is_note >> note;
	while (note > 50)
	{
		line.push_back(make_pair(note, 4));
		cnt++;
		is_note >> note;
	}
	line[0].second = note;//������ȥ��ʵ�����ǵ�һ��ʱֵ
	n = cnt;
	for (int i = 1; i < n; i++)
	{
		is_note >> time;
		line[i].second = time;
	}
	for (int i = 0; i < n; i++)
		_os << line[i].first << "," << line[i].second << " ";
	_os << endl;
	is_note.close();

	is_note.open("1-order-time_input.a.txt");//����ÿ�ж�Ӧ����
	is_prob.open("1-order-time_input.c.txt");//����
	double prob;
	cnt = 0;
	while (is_note >> note >> time)
	{
		_os << note << "," << time << " ";
		cnt++;
		for (int i = 0; i < n; i++)
		{
			is_prob >> prob;
			_os << prob << " ";
		}
		_os << endl;
	}
	c = cnt;

	_os << "69,8" << endl;//��ʼ����

	is_note.close();
	is_prob.close();
	_os.close();
}

void pre_2_order_no_time()
{
	k = 2;//2��
	is_note.open("2-order-no-time_input.b.txt");//����ÿ�ж�Ӧ����
	_os.open("2-order-no-time.txt");
	int note1, note2;
	int cnt = 0;
	while (is_note >> note1)
	{
		_os << note1 << ",4 ";
		cnt++;
	}
	n = cnt;
	_os << endl;
	is_note.close();
	is_note.open("2-order-no-time_input.a.txt");//����ÿ�ж�Ӧ����
	is_prob.open("2-order-no-time_input.c.txt");//����
	double prob;
	cnt = 0;
	while (is_note >> note1 >> note2)
	{
		_os << note1 << ",4 " << note2 << ",4 ";
		cnt++;
		for (int i = 0; i < n; i++)
		{
			is_prob >> prob;
			_os << prob << " ";
		}
		_os << endl;
	}
	c = cnt;

	_os << "69,4 74,4" << endl;//��ʼ����

	is_note.close();
	is_prob.close();
	_os.close();
}