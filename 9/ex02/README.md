# A Ford-Johnson Guide
This exercise was very challenging for me, so I decided to give you a hopefully clear and simple explanation of this very complex algorithm. 

I mainly followed [this](https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91) article and spoke with some very talented 42 students who were able to explain to me what I didn't quite get from the article.

To my understanding, these are the basic characteristics that the Ford-Johnson algorithm has:
- Divides and sorts recursively, sorting the bigger numbers to later insert the smaller numbers in their correct position
- Uses the Jacobsthal sequence to decide the insertioin order of the elements to insert

I also understood from this article that the binary serarch/insertion is also an important characteristic of this algorithm and that it plays a part in the efficiency of the insertion, so I incorporated it, but it is still unclear to me whether it is necessary or not.

I used std::vector and std::deque, and I also print the comparisions made, which, because the code is exactly the same for deque and vector, are always the same in both cases.

> [!TIP]
> I also made a DEBUG mode, which was extremely useful to me when doing the insertions.

### How to use the debug mode:
To compile normally we would do 'make', so for the debug we do:

    make debug
And we get the executable:

    ./PmergeMe_debug <num1> <num2> <num3> ...

## Algorithm breakdown
I see this algorithm working in two very distinct parts:
1. Grouping and sorting
2. Inserting in the different group levels

I'm gonna use the following input as example for the following explanations:

    ./PmergeMe  7 3 9 2 5 1 4 6

This is not the best example because there are only 8 numbers (even number), we won't have any leftover numbers in the grouping process, and we will only insert when the elements are formed by only 1 number.

This means it will be a very simple example, but, if you're starting out, I think it will be less overwhelming and more clear, and you can always check out more complex examples like the ones in the article.

### 1. Grouping and Sorting
This part is simple. It consists on making groups of powers of 2 and sorting those pairs in a recursive manner until you can no longer create a group because you don't have enough numbers to create a group.

In emuniov's article, he refers to each group as an element, which makes sense and helps keep things clear, so I will use the term like so as well.

Every time speak about an element, we should know how many numbers form that element. When we start, we have a std::vector<unsigned int> and an elements will simply be each number. The first grouping will be of pairs/groups of 2.

We will not change anything in the vector, but our elements will have a size of 2 and look like this:

    [7 3] [9 2] [5 1] [4 6]

Then we will simply put the biggest number in each element to the right:

    [3 7] [2 9] [1 5] [4 6]
We switched the positions of 7 and 3 because 7 > 3, and the same thing with 9 and 2 and 5 and 1. We left 4 and 6 as they were because they are already in the correct order.

Now we repeat the process with the modified sequence: we make groups of (the previous group size(2) x 2) -> 4.

    [[3 7] [2 9]] [[1 5] [4 6]]

Notice that we mantain the previous grouping. This is very important. The logic of the algorithm works with the idea that in each level of grouping and sorting we are sorting the bigger numbers and putting them in the right-most position, and this means that we will only check the number in that position (last number of each element) and moving the whole group when needed.

In this case, we have 2 elements per group, so we ask ourselves: is 7 > 9? and, is 5 > 6?: 
Because both of them are smaller, we don't need to do any switch in positions.

So, now, you guessed it! We make groups again: 

    [[[3 7] [2 9]] [[1 5] [4 6]]]
Now we have one group with 2 elements of size 4.

We ask ourselves, is 9 > 6 ? It isn't, so we switch the whole group like so:

    [[[1 5] [4 6]] [[3 7] [2 9]]]

As you can see, now the bigger numbers in each pair are already in order (5, 6, 7, 9). And the smaller aren't, but that is something we will deal with in the next part.








