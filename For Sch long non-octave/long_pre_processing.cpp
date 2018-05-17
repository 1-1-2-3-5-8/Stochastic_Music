#include <iostream>
#include <fstream>
#include <vector>
#include "variable.h"
using namespace std;

ifstream long_is_note;
ifstream long_is_prob;
ofstream long_os;
extern int k, n, c;

void long_pre_1_order_no_time()
{
	k = 1;//1阶
	long_is_note.open("sch_first_col.txt");//矩阵每列对应音符
	long_os.open("long_1-order-no-time.txt");
	int note;
	int cnt = 0;
	while (long_is_note >> note)
	{
		long_os << note << ",4 ";
		cnt++;
	}
	n = cnt;
	long_os << endl;
	long_is_note.close();
	long_is_note.open("sch_first_row.txt");//矩阵每行对应音符
	long_is_prob.open("sch_first_matrix.txt");//概率
	double prob;
	cnt = 0;
	while (long_is_note >> note)
	{
		long_os << note << ",4 ";
		cnt++;
		for (int i = 0; i < n; i++)
		{
			long_is_prob >> prob;
			long_os << prob << " ";
		}
		long_os << endl;
	}
	c = cnt;

	long_os << "60,4" << endl;//初始音符

	long_is_note.close();
	long_is_prob.close();
	long_os.close();
}

void long_pre_1_order_time()
{
	vector<pair<int, int>> line;//first是note，second是time
	k = 1;//1阶
	long_is_note.open("sch_time_col.txt");//矩阵每列对应音符
	long_os.open("long_1-order-time.txt");
	int note;
	double time;
	int cnt = 0;

	long_is_note >> note;
	while (note > 35)
	{
		line.push_back(make_pair(note, 4));
		cnt++;
		long_is_note >> note;
	}
	line[0].second = note * 3;//最后读进去的实际上是第一个时值
	n = cnt;
	for (int i = 1; i < n; i++)
	{
		long_is_note >> time;
		line[i].second = (time+0.01) * 3;
	}
	for (int i = 0; i < n; i++)
		long_os << line[i].first << "," << line[i].second << " ";
	long_os << endl;
	long_is_note.close();

	long_is_note.open("sch_time_row.txt");//矩阵每行对应音符
	long_is_prob.open("sch_time_matrix.txt");//概率
	double prob;
	cnt = 0;
	while (long_is_note >> note >> time)
	{
		long_os << note << "," << (int)((time + 0.01) * 3) << " ";
		cnt++;
		for (int i = 0; i < n; i++)
		{
			long_is_prob >> prob;
			long_os << prob << " ";
		}
		long_os << endl;
	}
	c = cnt;

	long_os << "60,2" << endl;//初始音符

	long_is_note.close();
	long_is_prob.close();
	long_os.close();
}

void long_pre_2_order_no_time()
{
	k = 2;//2阶
	long_is_note.open("sch_second_col.txt");//矩阵每列对应音符
	long_os.open("long_2-order-no-time.txt");
	int note1, note2;
	int cnt = 0;
	while (long_is_note >> note1)
	{
		long_os << note1 << ",4 ";
		cnt++;
	}
	n = cnt;
	long_os << endl;
	long_is_note.close();
	long_is_note.open("sch_second_row.txt");//矩阵每行对应音符
	long_is_prob.open("sch_second_matrix.txt");//概率
	double prob;
	cnt = 0;
	while (long_is_note >> note1 >> note2)
	{
		long_os << note1 << ",4 " << note2 << ",4 ";
		cnt++;
		for (int i = 0; i < n; i++)
		{
			long_is_prob >> prob;
			long_os << prob << " ";
		}
		long_os << endl;
	}
	c = cnt;

	long_os << "60,4 67,4" << endl;//初始音符

	long_is_note.close();
	long_is_prob.close();
	long_os.close();
}