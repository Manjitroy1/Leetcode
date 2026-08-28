# WITRH

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Within Reach

A robot is standing at position $X$ on a  **one-dimensional line**, and its charging station is located at position $Y$ on the same line.

The robot can move  **either left or right**  and can travel at most $K$ units with its remaining battery.

Determine whether the robot can  **reach the charging station**.

### Input Format
- The first line contains three space-separated integers $X$, $Y$, and $K$.
### Output Format
- Print YES if the robot can reach the charging station.
- Otherwise, print NO.
### Constraints
- $0 \le X,Y \le 100$
- $0 \le K \le 100$
### Sample 1:
Input
Output

```
4 11 7
```

```
YES
```

### Explanation:

The charging station is $7$ units away from the robot.

Since the robot can travel at most $7$ units, it can reach the charging station.

### Sample 2:
Input
Output

```
12 3 5
```

```
NO
```

### Explanation:

The charging station is $9$ units away from the robot.

Since the robot can travel only $5$ units, it cannot reach the charging station.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-28T16:17:09.370Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int x,y,k;
	cin>>x>>y>>k;
	
	if(abs(y-x)<=k){
	    cout<<"YES"<<endl;
	}else{
	    cout<<"NO"<<endl;
	}
	return 0;

}

```

---

[View on CodeChef](https://www.codechef.com/problems/WITRH)