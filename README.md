## The Fourth Lab 


## Electricians

Your company is installing an electricity network in the village of Vilshanka.  The condition of the tender was to involve local craftsmen, and you had to agree to it.  These craftsmen are peculiar, and as a result you have N poles/electrical poles that are located at a distance w from each other.  The problem is that the exact height of each pole is unknown - you only know that the height of the pole i is in the range [1, heights[i] ], and you can connect the wire only to the top of the pole (the necessary equipment is already installed there).

You order the electric wire for connecting the poles from China, and it will take a long time to travel/sail.	  You don't know exactly how much wire you need (it depends on the specific heights of the poles), so you want to order just enough for the worst case scenario.

(In other words - you need to find such a sequence of pole heights that the wire connecting their tops will be the longest)


## Input data:

The first line contains w - the distance between the pillars. The second line contains N numbers describing the maximum possible height for each pillar (i.e. an array of heights).


## Output:

The maximum possible required length of the wire with 2 digits after the decimal point.


## Constraints:

w, heights[i] - integers in the range 1 ... 100
N < 50

Of course, you must ignore various physical constraints ala wire sagging or wire consumption per connection


## Examples:
In:
2
3 3 3

Out:
5.65
(For example, with pole heights of 3 1 3, the wire length is sqrt((3-1)**2 + (3-1)**2) + sqrt((3-1)**2 + (3-1)**2) == 5.65

In:
100
1 1 1 1
Out:
300
(All supports of the same height)

In:
4
100 2 100 2 100
Out:
396.32
(We will need the most wire if the 1/3/5 poles are 100 high and the 2/4 poles are 1 high)

In:
4
56 18 17 94 23 7 21 94 29 54 44 26 86 79 4 15 5 91 25 17 88 66 28 2 95 97 60 93 40 70 75 48 38 51 34 52 87 8 62 77 35 52 3 93 34 57 51 11 39 72
Out:
2738.18


## Solution

The greatest height will be when the hypotenuse of the square triangle (the distance between the vertices of the pillars) is the greatest. This can be done if one of the adjacent pillars is set to height 1, and the other is left with the same height. But we need to consider two cases. The first is when height 1 is for even numbers of posts, 2 for odd numbers. Of course, when the array starts with 1, we will take only for odd numbers.

We walk down the binary tree (one of the examples is shown in the picture below), after reaching the leftmost child, we start to go back up and immediately calculate the hypotenuse. At each level we find the branch with the largest sum of hypotenuses.

Dynamic programming is that there are identical sections whose values can be written in a queue, and when they come again, instead of calculating them, you can simply substitute the values.
Such areas can be seen in the figure below. 
Here the columns are 2 3 4 5. 
In this case, the complexity of the algorithm is O(n).

![Diagram](/Lab4/assets/Diagram.jpg)





