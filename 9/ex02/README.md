# A Ford-Johnson Guide
This exercise was very challenging for me, so I decided to give you a hopefully clear and simple explanation of this very complex algorithm. 

I mainly followed [this](https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91) article and spoke with some very talented 42 students who were able to explain to me what I didn't quite get from the article.

To my understanding, these are the basic characteristics that the Ford-Johnson algorithm has:
- Divides and sorts recursively, sorting the bigger numbers to later insert the smaller numbers in their correct position
- Uses the Jacobsthal sequence to decide the insertion order of the elements to insert

I also understood from this article that the binary serarch/insertion is an important characteristic of this algorithm and that it plays a part in the efficiency of the insertion, so I incorporated it, but it is still unclear to me whether it is necessary or not.

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

<br/>

### 1. Grouping and Sorting
This part is simple. It consists on making groups of powers of 2 and sorting those pairs in a recursive manner until you can no longer create a group because you don't have enough numbers to create a group.

In emuniov's article, he refers to each group as an element, which makes sense and helps keep things clear, so I will use the term like so as well.

Every time speak about an element, we should know how many numbers form that element. When we start, we have a std::vector<unsigned int> and our elements will simply be each number. The first grouping will be of pairs/groups of 2.

So we start with:

    7 3 9 2 5 1 4 6
    
    grouped like so:
    
    [7 3] [9 2] [5 1] [4 6]

Then we will simply put the biggest number in each element to the right:

    [3 7] [2 9] [1 5] [4 6]

We switched the positions of 7 and 3 because 7 > 3, and the same thing with 9 and 2 and 5 and 1. We left 4 and 6 as they were because they are already in the correct order.

> [!NOTE]
>
>Later, in the insertion part, we'll see that we identify elements by being ***b***'s or ***a***'s.
>
>        [3 7]  [2 9]  [1 5]  [4 6]
>        b1 a1  b2 a2  b3 a3  b4 a4
>
> After the sorting  ->   b's = ***smaller*** numbers  |  a's = ***bigger*** ones.
> 
> This is something that is ALWAYS true, in every level.
> (the tags will change each level, but we'll see that later on)
>
> Our goal this first stage is to have the bigger numbers in ascending order.

If that note didn't help you, don't panic! Everything is much clearer through example. Let's continue.
    
Now that we have our pairs with the bigger numbers to the right, we repeat the grouping process: we make groups of (the previous group size(2) x 2) -> 4.

    [ [3 7] [2 9] ] [ [1 5] [4 6] ]
         Group           Group

Notice that we mantain the previous grouping of pairs. This is very important. The logic of the algorithm works with the idea that in each level of grouping and sorting we are sorting the bigger numbers and putting them in the right-most position, and this means that we will only check the number in that position (last number of each element) and moving the whole group when needed.

Now we have 2 elements per group, each element formed by 2 numbers:

      [ [3 7]    [2 9] ]   [ [1 5]    [4 6] ]
         (b1)     (a1)        (b2)     (a2)
      
we only check the right-most number of each element, so we ask ourselves: is 7 > 9? and, is 5 > 6?: 
Because both 7 is smaller than 9, and 5 is samller than 6, we don't need to do any switch in positions.

We are making sure that the bigger elements( formed by pairs in this case) go to the right.

So, now, you guessed it! We make groups again, of (4 x 2) = 8: 

    [  [ [3 7] [2 9] ]   [ [1 5] [4 6] ]  ]
           Element           Element
                     Group
    
We have 1 group, with 2 elements of size 4. We ask ourselves, is 9(last number of element) > 6(last number of element) ? 
It is, and we want the bigger element to the right, so we switch the elements:
 
    [  [ [1 5] [4 6] ]   [ [3 7] [2 9] ]  ]
            (b1)              (a1)

Notice that we have switched all 4 numbers that compose the element. As you can see, in this case, the bigger numbers in each pair are already in ascendinig order (5, 6, 7, 9). 

We stop recursion/grouping here because it is not possible to make bigger groups. Our vector size = 8 and the next group would have to have at least 16 (8 x 2) numbers.

The smaller numbers aren't in order, but that is precisely what we will deal with in the next part.

This is how our sequence looks after grouping and sorting:

    1 5 4 6 3 7 2 9


***ODD NUMBERS***

If we had had an odd amount of numbers, we would have probably encountered at some point something like this:
    
    element size = 2
    vector size = 5

    [4 1] [2 6] 3

The vector[4], which is = 3, is left out of the sorting process. We will simply sort what we can, add the leftover number, and continue the grouping process:
     
     [4 1] [2 6] 3  - >   [ [1 4] [2 6] ] 3   - >  1 4 2 6 3    (and that would be it)
<br/>

In terms of code, this first process is simple, but I'll point out some things to keep in mind:

- I am not dividing in any moment the vector (it's just a clearer representation of the idea) 
- I use an std::vector<unsigned int> as argument to the recursive function.
  This means I always have to keep track of the size of elements.
  I never use std::pairs, it seemed hard to implement to me.
- You have to respect the grouping of elements of the previous call.
<br/>

### 2. Inserting in the different group levels

This part consists on creating chains and inserting elements from one chain to the other. 

The 'main' chain will consist of the bigger elements (already sorted) and the 'pend' chain will have the smaller elements (not sorted).\
We will insert elements from the 'pend' (b's) to the 'main'(b1 + a's).\
We start this process with the element size that we left off with during the grouping process.

Follwing our example, we had: 

    1 5 4 6 3 7 2 9
    
    and we left off at element size = 4
   
    [ [1 5] [4 6] ]   [ [3 7] [2 9] ]
         (b1)              (a1)

The order of elements is ALWAYS going to be b1, a1, b2, a2, b3, a3, b4, a4, and so on, no matter the element's size. We will reset these 'tags' after each recursion level; because yes, we will also use recursion for this process :') 

Now, as I am following emuminov's article, I chose to do the same he does, which is to initialize the 'main' chain always with b1 + all the a's. The alternative would be to simply initialize the 'main' with all a's (bigger elements) and the 'pend' with all b's (smaller elements).

Keeping b1 in the 'main' saves us an insertion and is supposed to be a very obvious optimization, because we have already established and seen that b elements are always smaller than their corresponding a alements (for ex: b1 will always be smaller than a1). If we have done the first part of the process correctly, this should be true. In our current example, we can see that if we take the last number of b1 (6), it is indeed smaller than the last number of a1 (9). 

Why is this more efficient? Because our goal is to insert the smaller numbers into the 'main'. And if we know that the first two are always in order, we can skip the usual process.

In our example, there are no other b elements besides b1, so we don't have anything to insert, we can go to the next grouping level - > where element size = 2.

We are now doing the inverse process. In part 1 we created groups of bigger numbers each time, and here we start with big groups, put them in 'main' and 'pend' chains, put the elements in the 'pend' in the correct order inside the 'main', and then we go back a level of grouping, until we have elements composed by only 1 number. Let's see how this looks.

With element size = 2:

     [1 5] [4 6] [3 7] [2 9] 
       b1    a1    b2    a2

Our main and pend should look like:

    main = [1 5] [4 6] [2 9]   |    pend = [3 7]
             b1    a1    a2    |             b2

Now comes the part I struggled the most to understand: 

### the insertion order ✨

This is simply gonna be the order of the elements to be inserted. If we had 5 elements in the pend, we will always insert those same 5 elements, the only thing we decide here is when to insert each of them.

The implications of this order is something that I still find difficult to understand. How could inserting one element before another matter, if we are inserting them anyway? Well, I don't have the answer 100% clear. The gist of it relies in the fact that we will be inserting the pend elements in the main with the help of binary search and the [Jacobsthal numbers](https://en.wikipedia.org/wiki/Jacobsthal_number). 

> [!TIP]
> If you don't know anything about binary search, it is a way to find a number inside an ***already sorted*** array.\
> [This](https://www.youtube.com/watch?v=eVuPCG5eIr4&t=52s) video is extremely simple but suuper clear, and you'll understand it in a second!

We use the Jacobsthal numbers to determine the order, and it is very consistent. It is always the same order and it is related to the elements that we are working with. 
I see it this way:

    Jacobsthal numbers (not repeated) = 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, ...

    Jacobsthal 1 = b1
    Jacobsthal 3 = b3
    Jacobsthal 5 = b5
    Jacobsthal 11 = b11
    ...

This is just the base of how we are gonna use the Jacobsthal numbers. We are linking them to the 'tags' of the elements of the pend (small elements). 
Seen in a different way, these 'tags' also represent the positions of the b elements. And we are gonna apply an order of insertion based on the positions of these b elements.

Let's briefly imagine we have 7 ***b*** elements. 6 of those elements will be in the pend (b1 will be in the main):
    
    pend = [1 5]  [4 6]  [2 9]  [3 8]  [0 7]  [11 12]
             b2     b3     b4     b5     b6     b7
The order of insertion will be: b3, b2, b5, b4, b7, b6

If we had 11 ***b*** elements, 10 of those elements in the pend (b1 in the main):
    
    pend = [1 5]  [4 6]  [2 9]  [3 8]  [0 7]  [11 12]  [15 25]  [13 14]  [16 19]  [20 22]
             b2     b3     b4     b5     b6      b7       b8       b9      b10      b11 
The order of insertion will be: b3, b2, b5, b4, b11, b10, b9, b8, b7, b6

The pattern is: 
1. We start with the b element the closest to Jacobsthal 3
   >  We ***always*** start with Jacobsthal 3 because we have already inserted b1 in the main (it's as if we had already used Jacobsthal 1)
   
2. We descend in our vector to the left untill we reach the start of the vector
   > because we always start with b2, that's gonna be our next element to insert
   
3. We look for the element corresponding to the next Jacobsthal number (Jacobsthal 5) -> b5
   - if it exists: we choose it 
   - if it doesn't exist: we insert the remainig elements in reverse order, like we saw in the first example with Jacobsthal 11:
      
         pend = [1 5]  [4 6]  [2 9]  [3 8]  [0 7]  [11 12]
                  b2     b3     b4     b5     b6     b7
         there is no b11, we have from b6 to b7 to insert, so the order of insertion is : b3, b2, b5, b4, b7, b6
   
4. If we found the Jacobsthal element in step 3, we descend from that element to the last element to the left of the vector that hasn't been inserted yet
   > If we came from jacobsthal 5, the next element to insert will be b4 (b3 and b2 will have already been inserted at this point)
   
5. We look for the element corresponding to the next Jacobsthal number (Jacobsthal 11)
    > we'll repeat step 3 and 4 basically, until we can no longer use a Jacobsthal number




