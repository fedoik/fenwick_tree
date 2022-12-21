#include"header.h"

one_dimensional_fenvick_tree::one_dimensional_fenvick_tree(vector<int> a)
{
	n = a.size();
	fen.assign(n, 0);
	for (int i = 0; i < a.size(); i++)
		update(i, a[i]);
}
void one_dimensional_fenvick_tree::update(int i, int delta)
{
	for (; i < n; i = i | (i + 1))
		fen[i] += delta;
}
int one_dimensional_fenvick_tree::prefix_sum(int index)
{
	int result = 0;
	for (; index >= 0; index = (index & (index + 1)) - 1)
		result += fen[index];
	return result;
}
int one_dimensional_fenvick_tree::interval_sum(int left, int right)
{
	return prefix_sum(right) - prefix_sum(left - 1);
}

vector<int> pending_one_dimensional_fenvick_tree::cunstuct_tree()
{
	vector<int> fen(n, 0);
	for (int i = status.size() - 1; i >= 0; i--)
	{
		pending_update_operation(i, status[i], fen);
	}
	return fen;
}
void pending_one_dimensional_fenvick_tree::pending_update_operation(int i, int delta, vector<int>& fen)  // функция прохиоджится по спец. индексам(вычеслиным по i | (i + 1)) и обновляет все элементы массива фенвика в который входит этот индекс массива исходного
{
	for (; i < n; i = i | (i + 1))
		fen[i] += delta;
}

pending_one_dimensional_fenvick_tree::pending_one_dimensional_fenvick_tree(vector<int> a)
{
	n = a.size();
	status.assign(n, 0);
	for (int i = 0; i < a.size(); i++)
		update(i, a[i]);
}
void pending_one_dimensional_fenvick_tree::update(int i, int delta)
{
	status[i] += delta;
}

int pending_one_dimensional_fenvick_tree::prefix_sum(int index)
{
	vector<int> fen(n, 0);
	for (int i = index; i >= 0; i--)
	{
		pending_update_operation(i, status[i], fen);
	}
	int result = 0;
	for (; index >= 0; index = (index & (index + 1)) - 1)
		result += fen[index];
	return result;
}
int pending_one_dimensional_fenvick_tree::interval_sum(int left, int right)
{
	return prefix_sum(right) - prefix_sum(left - 1);
}

two_dimension_fenvick_tree::two_dimension_fenvick_tree(vector<vector<int> > a)
{
	for (int i = 0; i < a.size(); i++)
	{
		vector<int> arr;
		arr.assign(a[0].size(), 0);
		fen.push_back(arr);
	}
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[0].size(); j++)
		{
			update(i, j, a[i][j]);
		}
	}
}

void two_dimension_fenvick_tree::update(int x, int y, int delta)
{
	for (int i = x; i < fen.size(); i = (i | (i + 1)))
		for (int j = y; j < fen[0].size(); j = (j | (j + 1)))
			fen[i][j] += delta;
}
int two_dimension_fenvick_tree::prefix_sum(int x, int y)
{
	int result = 0;
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
			result += fen[i][j];
	return result;
}
int two_dimension_fenvick_tree::interval_sum(int x, int y, int x1, int y1)
{
	return prefix_sum(x1, y1) - prefix_sum(x1, y - 1) - (prefix_sum(x - 1, y1) - prefix_sum(x - 1, y - 1));
}
