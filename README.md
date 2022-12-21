# Fenwick tree

[Wiki](https://en.wikipedia.org/wiki/Fenwick_tree)  
[Brilliant](https://brilliant.org/wiki/fenwick-tree/)  
[Codeforces](https://codeforces.com/blog/entry/57292)

## Program description
The program has three classes:`one_dimensional_fenvick_tree`, `pending_one_dimensional_fenvick_tree`, `two_dimension_fenvick_tree`.  
- **one_dimensional_fenvick_tree** - class for a simple one-dimensional fenwick tree
- **pending_one_dimensional_fenvick_tree** - class with implemented pending operations (The structure no longer has a BIT array. Now we store an array of statuses from which the Fenwick tree is built at the right time)
- **two_dimension_fenvick_tree** - class with 2D Fenwick tree 

All three classes have standard fenwick tree methods such as item update, prefix sum and interval sum.

