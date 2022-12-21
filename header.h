#pragma once
#include<iostream>
#include<vector>

using namespace std;
class one_dimensional_fenvick_tree
{
private:

	int n;
	vector<int> fen;

public:
	one_dimensional_fenvick_tree(vector<int> a);
	
	void update(int i, int delta);
	
	int prefix_sum(int index);
	
	int interval_sum(int left, int right);
	
	friend ostream& operator<<(ostream& s, one_dimensional_fenvick_tree& obj)
	{
		cout << "Fenvick tree: ";
		for (auto i : obj.fen)
			cout << i << ", ";
		cout << '\n';
		return s;
	}
};

class pending_one_dimensional_fenvick_tree
{
private:
	int n;
	vector<int> status;

	vector<int> cunstuct_tree();
	
	void pending_update_operation(int i, int delta, vector<int>& fen);  // функция прохиоджится по спец. индексам(вычеслиным по i | (i + 1)) и обновляет все элементы массива фенвика в который входит этот индекс массива исходного
	
public:
	pending_one_dimensional_fenvick_tree(vector<int> a);
	
	void update(int i, int delta);

	int prefix_sum(int index);

	int interval_sum(int left, int right);

	friend ostream& operator<<(ostream& s, pending_one_dimensional_fenvick_tree& obj)
	{
		vector<int> current = obj.cunstuct_tree();
		cout << "Fenvick pending tree: ";
		for (auto i : current)
			cout << i << ", ";
		cout << '\n';
		return s;
	}
};

class two_dimension_fenvick_tree
{
private:
	int size;
	vector<vector<int> > fen;

public:
	two_dimension_fenvick_tree(vector<vector<int> > a);

	void update(int x, int y, int delta);

	int prefix_sum(int x, int y);

	int interval_sum(int x, int y, int x1, int y1);

	friend ostream& operator<<(ostream& s, two_dimension_fenvick_tree& tree)
	{
		s << "Fenvick_two_dimension :\n";
		for (vector<int>& vec_current : tree.fen) {
			for (int& value : vec_current) {
				s << value << " ";
			}
			s << endl;
		}
		return s;
	}
};
