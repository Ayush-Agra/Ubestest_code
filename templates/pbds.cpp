#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
//pb_ds provide same method as set and 2 extra functionality
//find_by_order() returns an iterator to the kth largest element
//order_of_key() the number of items in set that are smaller than our item
//we can change the comparator which is less<int> to greater<int>
//or custom defined comparators
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pb_ds;
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
int32_t main(){
  
}