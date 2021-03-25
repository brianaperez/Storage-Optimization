# Storage Optimization
#### Experience Level : Experienced
#### Year : 2020 / 2021

## Problem

The local library is considering making their bookshelves more efficient by implementing a new flexible shelf system. The new shelves consist of rearrangeable dividers (both vertically and horizontally), with the smallest blocks being a cube of 1 foot by 1 foot by 1 foot.

Given a shelf configuration, calculate the volume of the largest space in the shelf.

n = number of horizontal dividers

m = number of vertical dividers

h = a list of numbers representing the horizontal dividers that are missing

v = a list of numbers representing the vertical dividers that are missing

Example 1:

Input:

n = 6 m = 6 h = [4] v = [2]

Output: 4

Explanation:

Consider the diagram below. The left image depicts the initial storage unit with all the dividers. The right image depicts the unit after h = [4] and v = [2] dividers are removed. The maximum storage volume for that shelf is therefore 2 x 2 x 1 = 4 cubic feet. The last dimension is always 1, since all shelves are 1 foot deep.

![Image of Shelf1](https://i.ibb.co/JHWrg8n/image.png)

Example 2:

Input:

n = 3 m = 3 h = [2] v = [2]

Output: 4

Explanation:

There are n = m = 3 dividers in each direction. After removing divider [2] from both axes, we have the following.

![Image of Shelf2](https://i.ibb.co/LnSb6Vy/image.png)


The largest space size is 2 x 2 x 1 = 4 cubic feet.

Example 3:

Input:

n = 3 m = 2 h = [1, 2, 3] v = [1, 2]

Output: 12

Explanation:

After removing all the separators, the unit will look like the following.

![Image All Removed](https://i.ibb.co/JHWrg8n/image.png)

The volume is the size of the overall shelf, which is 3 x 4 x 1 = 12 cubic feet.

## My Prcoess

### Solution v 1.0

Within the problem, it talks about vectos h and v being the horizontal/vertical dividers that would be removed. 
